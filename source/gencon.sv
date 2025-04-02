// General Controller Module (Fixed for Addition-Only)
module gencon (
    input logic clk,                    // System clock
    input logic nRST,                  // Reset signal
    input logic [3:0] keypad_input,     // 4-bit Keypad input (single digit)
    input logic operator_input,         // Operator input (ignored since only addition)
    input logic equal_input,            // Equal input to trigger addition
    output logic complete,              // Calculation completion flag
    output logic [15:0] display_output, // 16-bit output to display result

    // Memory Control
    input logic cs,                     // Chip select for memory
    input logic we,                     // Write enable
    input logic oe,                     // Output enable
    output logic [1:0] mem_addr,        // Memory address (2 bits: 00, 01, 10)
    inout logic [15:0] mem_data         // Memory data bus
);

    // State Definitions
    typedef enum logic [1:0] {
        GET_FIRST_NUM = 2'b00,  // Getting the first operand
        GET_SECOND_NUM = 2'b01, // Getting the second operand
        PERFORM_CALC = 2'b10,   // Adding operands
        SHOW_RESULT   = 2'b11   // Displaying result
    } state_t;

    state_t current_state, next_state;

    // Internal Registers
    logic [15:0] operand1, operand2, result;  // Registers for operands and result

    // FSM: State Transitions
    always_ff @(posedge clk or posedge reset) begin
        if (reset)
            current_state <= GET_FIRST_NUM;  // Reset to initial state
        else
            current_state <= next_state;     // State transition
    end

    // FSM: State Logic
    always_comb begin
        case (current_state)
            GET_FIRST_NUM:
                if (keypad_input != 4'b0000)    next_state = GET_FIRST_NUM;
                else if (operator_input)        next_state = GET_SECOND_NUM;
                else                            next_state = GET_FIRST_NUM;

            GET_SECOND_NUM:
                if (keypad_input != 4'b0000)    next_state = GET_SECOND_NUM;
                else if (equal_input)          next_state = PERFORM_CALC;
                else                            next_state = GET_SECOND_NUM;

            PERFORM_CALC:
                next_state = SHOW_RESULT;  // Immediately move to result display

            SHOW_RESULT:
                next_state = GET_FIRST_NUM; // Reset after showing result

            default:
                next_state = GET_FIRST_NUM;
        endcase
    end

    // Memory Read/Write Logic
    always_ff @(posedge clk) begin
        case (current_state)
            GET_FIRST_NUM: begin
                if (keypad_input != 4'b0000) begin
                    operand1 <= operand1 * 10 + keypad_input; // Append digit to operand1
                    mem_addr <= 2'b00;  // Store in memory at address 00
                    mem_data <= operand1;
                    we <= 1;
                end
            end

            GET_SECOND_NUM: begin
                if (keypad_input != 4'b0000) begin
                    operand2 <= operand2 * 10 + keypad_input; // Append digit to operand2
                    mem_addr <= 2'b01;  // Store in memory at address 01
                    mem_data <= operand2;
                    we <= 1;
                end
            end

            PERFORM_CALC: begin
                result <= operand1 + operand2; // Perform addition directly
                mem_addr <= 2'b10;  // Store result in memory
                mem_data <= result;
                we <= 1;
            end

            SHOW_RESULT: begin
                complete <= 1;  // Indicate calculation done
                display_output <= result;  // Send result to display
            end

            default: begin
                we <= 0;
                complete <= 0;
            end
        endcase
    end

endmodule

