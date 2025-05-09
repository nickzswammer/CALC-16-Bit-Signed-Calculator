// Refactored gencon module with proper multiplier operand handling via FSM state split
`include "gencon_defs.sv"

module gencon (
    input logic clk,
    input logic nRST,

    input logic [3:0] keypad_input,
    input logic read_input,
    input logic [2:0] operator_input,
    input logic equal_input,

    output logic key_read, // to input controller to indicate key is read
    
    output logic complete,
    output logic [15:0] display_output
);

    // latch keypad_input and operator_input to use in updating number and sending operands to compute
    logic [3:0] latched_keypad_input;
    logic [2:0] latched_operator_input;

    // ALU control
    logic [15:0] ALU_in1, ALU_in2, ALU_out;
    logic addOrSub, start_ALU, ALU_finish;

    // Multiplier control
    logic [15:0] mult_in1, mult_in2, mult_out;
    logic start_mult, mult_finish;

    // Temporary Operator Input Variables
    logic latch_operator;
    logic [2:0] operator_to_latch;

    // flag to assert key_read for one clock cycle
    logic prev_read_input;
    logic [2:0] prev_operator_input;

    // operands to send to ALU/ Multiplier
    logic [15:0] operand1, operand2;

    // state variables
    state_t gencon_state, next_state;
    
    // ALU instantiation
    addition add_calc(
        .clk(clk), .nRST(nRST),
        .INn1(ALU_in1), .INn2(ALU_in2), .sub(addOrSub),
        .start(start_ALU), .out(ALU_out), .finish(ALU_finish)
    );

    // Multiplier instantiation
    multiply mult_calc(
        .clk(clk), .nRST(nRST),
        .INn1(mult_in1), .INn2(mult_in2),
        .start(start_mult), .out(mult_out), .finish(mult_finish)
    );


    // FSM logic
    always_comb begin
        next_state = gencon_state;
        latch_operator = 0;
        operator_to_latch = latched_operator_input;
        
        case (gencon_state)
            WAIT_OP1: begin
                if (operator_input != 3'b000 && operator_input != 3'b001) begin
                    latch_operator = 1;
                    operator_to_latch = operator_input;
                    next_state = WAIT_OP2;
                end
                else begin
                    next_state = (read_input) ? WAIT_MULT_OP1 : WAIT_OP1;
                end
            end

            WAIT_MULT_OP1:
                next_state = (mult_finish) ? ADD_KEY_INPUT_OP1 : WAIT_MULT_OP1;

            ADD_KEY_INPUT_OP1:
                next_state = WAIT_OP1;

            WAIT_OP2:
                if (equal_input) begin
                    next_state = SEND_TO_COMPUTE;
                end
                else begin
                    next_state = (read_input) ? WAIT_MULT_OP2 : WAIT_OP2;
                end

            WAIT_MULT_OP2:
                next_state = (mult_finish) ? ADD_KEY_INPUT_OP2 : WAIT_MULT_OP2;

            ADD_KEY_INPUT_OP2:
                next_state = WAIT_OP2;

            SEND_TO_COMPUTE:
                next_state = WAIT_COMPUTE;

            WAIT_COMPUTE:
                if (ALU_finish)
                    next_state = SHOW_RESULT_ADDSUB;
                else if (mult_finish)
                    next_state = SHOW_RESULT_MULT;
                else
                    next_state = WAIT_COMPUTE;

            SHOW_RESULT_ADDSUB, SHOW_RESULT_MULT:
                next_state = WAIT_OP1;

            default:
                next_state = WAIT_OP1;
        endcase
    end

    // Output + operand logic
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            key_read <= 0;
            display_output <= 0;
            complete <= 0;
            gencon_state <= WAIT_OP1;
            operand1 <= 0;
            operand2 <= 0;
            latched_operator_input <= 0;
            latched_keypad_input <= 0;
            
        end else begin
            start_ALU <= 0;
            start_mult <= 0;
            
            gencon_state <= next_state;
            if (latch_operator) begin
                latched_operator_input <= operator_to_latch;
                key_read <= 0;
            end

            case (gencon_state)
                WAIT_OP1: begin
                    display_output <= operand1;
                    complete <= 0;
                    
                    key_read <= (read_input && !prev_read_input) || 
                                ((operator_input != 0) && (prev_operator_input == 3'b000));

                    prev_read_input <= read_input;

                    if (operator_input == 1 && key_read) begin
                        operand1[15] <= 1'b1;
                    end
                    
                    if (read_input) begin
                        prev_operator_input <= 0;
                        latched_keypad_input <= keypad_input;
                        mult_in1 <= operand1;
                        mult_in2 <= 16'd10;
                        start_mult <= 1;
                    end
                    else begin
                        prev_operator_input <= operator_input;
                    end
                end

                WAIT_MULT_OP1: begin
                    key_read <= 0;
                    if (mult_finish) begin
                        operand1 <= mult_out;
                    end
                end

                ADD_KEY_INPUT_OP1: begin
                    operand1 <= operand1 + {12'd0, latched_keypad_input};
                end

                WAIT_OP2: begin
                    display_output <= operand2;

                    key_read <= (read_input && !prev_read_input) || 
                                ((operator_input != 0) && (prev_operator_input == 0));

                    prev_read_input <= read_input;
                    prev_operator_input <= operator_input;
                    
                    if (operator_input == 1 && key_read) begin
                            operand2[15] <=  1'b1;
                    end
                    
                    if (read_input) begin
                        latched_keypad_input <= keypad_input;
                        prev_operator_input <= 0;
                        mult_in1 <= operand2;
                        mult_in2 <= 16'd10;
                        start_mult <= 1;
                    end
                end

                WAIT_MULT_OP2: begin
                    key_read <= 0;
                    if (mult_finish) begin
                        operand2 <= mult_out;
                    end
                end

                ADD_KEY_INPUT_OP2: begin
                    operand2 <= operand2 + {12'd0, latched_keypad_input};
                end

                SEND_TO_COMPUTE: begin
                    key_read <= 1;
                    if (latched_operator_input == 2 || latched_operator_input == 3) begin
                        ALU_in1 <= operand1;
                        ALU_in2 <= operand2;
                        addOrSub <= (latched_operator_input == 3);
                        start_ALU <= 1;
                    end else if (latched_operator_input == 4) begin
                        mult_in1 <= operand1;
                        mult_in2 <= operand2;
                        start_mult <= 1;
                    end
                end

                WAIT_COMPUTE:
                    key_read <= 0;

                SHOW_RESULT_ADDSUB: begin
                    operand1 <= ALU_out;
                    operand2 <= 0;
                    complete <= 1;
                    
                    display_output <= ALU_out;
                end

                SHOW_RESULT_MULT: begin
                    operand1 <= mult_out;
                    operand2 <= 0;
                    complete <= 1;
                    
                    display_output <= mult_out;
                end

                default: complete <= 0;
            endcase
        end
    end
endmodule
