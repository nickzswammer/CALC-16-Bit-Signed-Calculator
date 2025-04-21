// Refactored gencon module with proper multiplier operand handling via FSM state split

module gencon (
    input logic clk,
    input logic nRST,

    input logic [3:0] keypad_input,
    input logic read_input,
    input logic [2:0] operator_input,
    input logic equal_input,

    output logic complete,
    output logic [15:0] display_output
);
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

    // FSM states
    typedef enum logic [3:0] {
        SEND_MULT_OP1_START = 4'b0000,
        WAIT_MULT_OP1       = 4'b0001,
        GET_FIRST_NUM       = 4'b0010,
        SEND_MULT_OP2_START = 4'b0011,
        WAIT_MULT_OP2       = 4'b0100,
        GET_SECOND_NUM      = 4'b0101,
        SEND_TO_ALU         = 4'b0110,
        WAIT_ALU            = 4'b0111,
        SHOW_RESULT_ALU     = 4'b1000,
        SHOW_RESULT_MULT    = 4'b1001
    } state_t;

    state_t current_state, next_state;

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
            current_state <= SEND_MULT_OP1_START;
            operand1 <= 0;
            operand2 <= 0;
            complete <= 0;
            display_output <= 0;
            getting_op1 <= 0;
            getting_op2 <= 0;
        end else begin
            current_state <= next_state;
        end
    end
    /* verilator lint_off CASEINCOMPLETE */

    // FSM logic
    always_comb begin
        next_state = current_state;
        case (current_state)
            SEND_MULT_OP1_START:
                next_state = (read_input) ? WAIT_MULT_OP1 : SEND_MULT_OP1_START;

            WAIT_MULT_OP1:
                next_state = (mult_finish) ? GET_FIRST_NUM : WAIT_MULT_OP1;

            GET_FIRST_NUM:
                next_state = (operator_input != 3'b000) ? SEND_MULT_OP2_START : SEND_MULT_OP1_START;

            SEND_MULT_OP2_START:
                next_state = (read_input) ? WAIT_MULT_OP2 : SEND_MULT_OP2_START;

            WAIT_MULT_OP2:
                next_state = (mult_finish) ? GET_SECOND_NUM : WAIT_MULT_OP2;

            GET_SECOND_NUM:
                next_state = (equal_input) ? SEND_TO_ALU : SEND_MULT_OP1_START;

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
                SEND_MULT_OP1_START:
                    if (read_input) begin
                        mult_in1 <= operand1;
                        mult_in2 <= 16'd10;
                        start_mult <= 1;
                        getting_op1 <= 1;
                    end

                WAIT_MULT_OP1:
                    if (mult_finish) begin
                        operand1 <= mult_out;
                        getting_op1 <= 0;
                    end

                GET_FIRST_NUM:
                    operand1 <= operand1 + {12'd0, keypad_input};

                SEND_MULT_OP2_START:
                    if (read_input) begin
                        mult_in1 <= operand2;
                        mult_in2 <= 16'd10;
                        start_mult <= 1;
                        getting_op2 <= 1;
                    end

                WAIT_MULT_OP2:
                    if (mult_finish) begin
                        operand2 <= mult_out;
                        getting_op2 <= 0;
                    end

                GET_SECOND_NUM:
                    operand2 <= operand2 + {12'd0, keypad_input};

                SEND_TO_ALU:
                    if (operator_input == 3'b001 || operator_input == 3'b010) begin
                        ALU_in1 <= operand1;
                        ALU_in2 <= operand2;
                        addOrSub <= (operator_input == 3'b010);
                        start_ALU <= 1;
                    end else if (operator_input == 3'b100) begin
                        mult_in1 <= operand1;
                        mult_in2 <= operand2;
                        start_mult <= 1;
                    end

                WAIT_ALU:
                    ; // no-op, waiting for finish signals

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
