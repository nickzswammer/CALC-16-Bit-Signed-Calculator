module gencon (
    input  logic clk,
    input  logic reset,
    input  logic [3:0] keypad_input,
    input  logic [1:0] operator_code, // 00=ADD, 01=SUB, 10=MUL
    input  logic equal_input,

    output logic complete,
    output logic [15:0] display_output,

    // Memory
    output logic we,
    output logic oe,
    output logic [3:0] mem_addr,
    output logic [15:0] mem_data,
    input  logic [15:0] data
);

    // ALU signals
    logic [15:0] ALU_in1, ALU_in2;
    logic start_calc, ALU_finish;
    logic [15:0] ALU_out;

    // Multiplier signals
    logic [15:0] mul_in1, mul_in2;
    logic start_mul, mul_finish;
    logic [15:0] mul_out;

    // State machine
    typedef enum logic [2:0] {
        GET_FIRST_NUM,
        GET_SECOND_NUM,
        SEND_TO_UNIT,
        WAIT_UNIT,
        SHOW_RESULT
    } state_t;

    state_t current_state, next_state;

    logic [15:0] operand1, operand2;
    logic [3:0] prev_key;
    logic is_calc_done;
    logic [15:0] result;

    // FSM register update
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            current_state <= GET_FIRST_NUM;
        end else begin
            current_state <= next_state;
        end
    end

    // FSM next state logic
    always_comb begin
        next_state = current_state;
        case (current_state)
            GET_FIRST_NUM:
                if (keypad_input != 0 && keypad_input != prev_key)
                    next_state = GET_FIRST_NUM;
                else if (operator_code != 2'b11)
                    next_state = GET_SECOND_NUM;
            GET_SECOND_NUM:
                if (keypad_input != 0 && keypad_input != prev_key)
                    next_state = GET_SECOND_NUM;
                else if (equal_input)
                    next_state = SEND_TO_UNIT;
            SEND_TO_UNIT:
                next_state = WAIT_UNIT;
            WAIT_UNIT:
                if (is_calc_done)
                    next_state = SHOW_RESULT;
            SHOW_RESULT:
                next_state = GET_FIRST_NUM;
        endcase
    end

    // FSM output logic
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            operand1 <= 0;
            operand2 <= 0;
            complete <= 0;
            display_output <= 0;
            start_calc <= 0;
            start_mul <= 0;
            ALU_in1 <= 0;
            ALU_in2 <= 0;
            mul_in1 <= 0;
            mul_in2 <= 0;
            mem_addr <= 0;
            mem_data <= 0;
            we <= 0;
            oe <= 0;
            prev_key <= 0;
        end else begin
            complete <= 0;
            start_calc <= 0;
            start_mul <= 0;
            we <= 0;
            case (current_state)
                GET_FIRST_NUM: begin
                    if (keypad_input != 0 && keypad_input != prev_key) begin
                        operand1 <= operand1 * 10 + keypad_input;
                        mem_addr <= 4'd0;
                        mem_data <= operand1;
                        we <= 1;
                    end
                    prev_key <= keypad_input;
                end
                GET_SECOND_NUM: begin
                    if (keypad_input != 0 && keypad_input != prev_key) begin
                        operand2 <= operand2 * 10 + keypad_input;
                        mem_addr <= 4'd1;
                        mem_data <= operand2;
                        we <= 1;
                    end
                    prev_key <= keypad_input;
                end
                SEND_TO_UNIT: begin
                    case (operator_code)
                        2'b00, 2'b01: begin
                            ALU_in1 <= operand1;
                            ALU_in2 <= operand2;
                            start_calc <= 1;
                        end
                        2'b10: begin
                            mul_in1 <= operand1;
                            mul_in2 <= operand2;
                            start_mul <= 1;
                        end
                    endcase
                end
                SHOW_RESULT: begin
                    complete <= 1;
                    result <= (operator_code == 2'b10) ? mul_out : ALU_out;
                    display_output <= result;
                end
            endcase
        end
    end

    // Result readiness check
    always_comb begin
        is_calc_done = (operator_code == 2'b10) ? mul_finish : ALU_finish;
    end

    // ALU instantiation
    addition add_calc (
        .clk(clk),
        .nRST(~reset),
        .INn1(ALU_in1),
        .INn2(ALU_in2),
        .sub(operator_code == 2'b01),
        .start(start_calc),
        .out(ALU_out),
        .finish(ALU_finish)
    );

    // Multiplier instantiation
    multiply mul_calc (
        .clk(clk),
        .nRST(~reset),
        .INn1(mul_in1),
        .INn2(mul_in2),
        .start(start_mul),
        .out(mul_out),
        .finish(mul_finish)
    );

    // Memory instantiation
    memory mem (
        .clk(clk),
        .mem_addr(mem_addr),
        .mem_data(mem_data),
        .data(data),
        .we(we),
        .oe(oe)
    );

endmodule
