// Refactored gencon module with proper multiplier operand handling via FSM state split
`include "gencon_defs.sv"

module gencon (
    input logic clk,
    input logic nRST,

    input logic [3:0] keypad_input,
    input logic read_input,
    input logic [2:0] operator_input,
    input logic equal_input,

    output logic complete,
    output logic [15:0] display_output,
    output state_t tb_current_state  // ← add this in port list

);

    logic [3:0] latched_keypad_input;
    logic [2:0] latched_operator_input;
    // ALU control
    logic [15:0] ALU_in1, ALU_in2;
    logic addOrSub, start_ALU;
    logic ALU_finish;
    logic [15:0] ALU_out;

    // Multiplier control
    logic [15:0] mult_in1, mult_in2;
    logic start_mult;
    logic [15:0] mult_out;
    logic mult_finish;

    // Internal state flags
    logic getting_op1, getting_op2;

    // Temporary Operator Input Variables
    logic latch_operator;
    logic [2:0] operator_to_latch;


    state_t current_state, next_state;

    // operands to send to ALU/ Multiplier
    logic [15:0] operand1, operand2;

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

    assign tb_current_state = current_state; // ← drive it inside gencon

    // FSM state transition
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            current_state <= SEND_MULT_OP1_START;
            operand1 <= 0;
            operand2 <= 0;
            complete <= 0;
            display_output <= 0;
            getting_op1 <= 0;
            getting_op2 <= 0;
            latched_operator_input <= 0;
            latched_keypad_input <= 0;
            mult_in1 <= 0;
            mult_in2 <= 0;
            ALU_in1 <= 0;
            ALU_in2 <= 0;
        end else begin
            current_state <= next_state;
            if (latch_operator) begin
                latched_operator_input <= operator_to_latch;
            end
        end
    end
    /* verilator lint_off CASEINCOMPLETE */

    // FSM logic
    always_comb begin
        next_state = current_state;
        latch_operator = 0;
        operator_to_latch = latched_operator_input;
        
        case (current_state)
            SEND_MULT_OP1_START:
    
                if (operator_input != 3'b000 && operator_input != 3'b001) begin
                    latch_operator = 1;
                    operator_to_latch = operator_input;
                    next_state = SEND_MULT_OP2_START;
                end
                else begin
                    next_state = (read_input) ? WAIT_MULT_OP1 : SEND_MULT_OP1_START;
                end

            WAIT_MULT_OP1:
                next_state = (mult_finish) ? GET_FIRST_NUM : WAIT_MULT_OP1;

            GET_FIRST_NUM:
                next_state = SEND_MULT_OP1_START;

            SEND_MULT_OP2_START:
                if (equal_input) begin
                    next_state = SEND_TO_ALU;
                end
                else begin
                    next_state = (read_input) ? WAIT_MULT_OP2 : SEND_MULT_OP2_START;
                end

            WAIT_MULT_OP2:
                next_state = (mult_finish) ? GET_SECOND_NUM : WAIT_MULT_OP2;

            GET_SECOND_NUM:
                next_state = SEND_MULT_OP2_START;

            SEND_TO_ALU:
                next_state = WAIT_ALU;

            WAIT_ALU:
                if (ALU_finish)
                    next_state = SHOW_RESULT_ALU;
                else if (mult_finish)
                    next_state = SHOW_RESULT_MULT;
                else
                    next_state = WAIT_ALU;

            SHOW_RESULT_ALU, SHOW_RESULT_MULT:
                next_state = SEND_MULT_OP1_START;
        endcase
        /* verilator lint_on CASEINCOMPLETE */

    end

    // Output + operand logic
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            start_ALU <= 0;
            start_mult <= 0;
        end else begin
            start_ALU <= 0;
            start_mult <= 0;

            case (current_state)
                SEND_MULT_OP1_START: begin
                    if (operator_input == 1) begin
                        operand1[15] <=  operand1[15] ^ 1'b1;
                    end
                    if (read_input) begin
                        latched_keypad_input <= keypad_input;
                        
                        mult_in1 <= operand1;
                        mult_in2 <= 16'd10;
                        start_mult <= 1;
                        getting_op1 <= 1;
                    end
    
                end

                WAIT_MULT_OP1: begin
                    
                    
                    if (mult_finish) begin
                        operand1 <= mult_out;
                        getting_op1 <= 0;
                    end
                end

                GET_FIRST_NUM: begin
                    operand1 <= operand1 + {12'd0, latched_keypad_input};
                end

                SEND_MULT_OP2_START: begin
                    if (operator_input == 1) begin
                        operand2[15] <=  operand2[15] ^ 1'b1;
                    end
                    
                    if (read_input) begin
                        latched_keypad_input <= keypad_input;
                        mult_in1 <= operand2;
                        mult_in2 <= 16'd10;
                        start_mult <= 1;
                        getting_op2 <= 1;
                    end
                    
                end

                WAIT_MULT_OP2: begin
                    if (mult_finish) begin
                        operand2 <= mult_out;
                        getting_op2 <= 0;
                    end
                end

                GET_SECOND_NUM: begin
                    operand2 <= operand2 + {12'd0, latched_keypad_input};
                end

                SEND_TO_ALU: begin
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

                WAIT_ALU:
                    ;

                SHOW_RESULT_ALU: begin
                    complete <= 1;
                    display_output <= ALU_out;
                end

                SHOW_RESULT_MULT: begin
                    complete <= 1;
                    display_output <= mult_out;
                end

                default: complete <= 0;
            endcase
        end
    end
endmodule
