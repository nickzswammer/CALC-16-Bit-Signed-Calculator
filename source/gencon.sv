// Refactored gencon module with proper multiplier operand handling via FSM state split
`include "gencon_defs.sv"
`timescale 1ns / 1ns

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

    // FSM state transition
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            current_state <= WAIT_OP1;
            key_read <= 0;
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
                key_read <= 0;
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
            WAIT_OP1:
                if (operator_input != 3'b000 && operator_input != 3'b001) begin
                    latch_operator = 1;
                    operator_to_latch = operator_input;
                    next_state = WAIT_OP2;
                end
                else begin
                    next_state = (read_input) ? WAIT_MULT_OP1 : WAIT_OP1;
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
                WAIT_OP1: begin
                    if (operator_input == 1) begin
                        key_read <= 1;
                        operand1[15] <=  operand1[15] ^ 1'b1;
                    end
                    if (read_input) begin
                        latched_keypad_input <= keypad_input;

                        key_read <= 1;
                        
                        mult_in1 <= operand1;
                        mult_in2 <= 16'd10;
                        start_mult <= 1;
                        getting_op1 <= 1;
                    end
                end

                WAIT_MULT_OP1: begin
                    key_read <= 0;
                    if (mult_finish) begin
                        operand1 <= mult_out;
                        getting_op1 <= 0;
                    end
                end

                ADD_KEY_INPUT_OP1: begin
                    operand1 <= operand1 + {12'd0, latched_keypad_input};
                end

                WAIT_OP2: begin
                    if (operator_input == 1) begin
                        key_read <= 1;
                        operand2[15] <=  operand2[15] ^ 1'b1;
                    end
                    
                    if (read_input) begin
                        latched_keypad_input <= keypad_input;

                        key_read <= 1;
                        
                        mult_in1 <= operand2;
                        mult_in2 <= 16'd10;
                        start_mult <= 1;
                        getting_op2 <= 1;
                    end
                end

                WAIT_MULT_OP2: begin
                    key_read <= 0;
                    if (mult_finish) begin
                        operand2 <= mult_out;
                        getting_op2 <= 0;
                    end
                end

                ADD_KEY_INPUT_OP2: begin
                    operand2 <= operand2 + {12'd0, latched_keypad_input};
                end

                SEND_TO_COMPUTE: begin
                    if (latched_operator_input == 2 || latched_operator_input == 3) begin
                        key_read <= 1;
                        ALU_in1 <= operand1;
                        ALU_in2 <= operand2;
                        addOrSub <= (latched_operator_input == 3);
                        start_ALU <= 1;
                    end else if (latched_operator_input == 4) begin
                        key_read <= 1;
                        mult_in1 <= operand1;
                        mult_in2 <= operand2;
                        start_mult <= 1;
                    end
                end

                WAIT_COMPUTE:
                    key_read <= 0;

                SHOW_RESULT_ADDSUB: begin
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
