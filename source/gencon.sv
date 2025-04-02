module gencon (
    input logic clk,                    // Clock signal
    input logic reset,                  // Reset signal
    input logic [3:0] keypad_input,     // Keypad input (4 bits representing a digit or operator)
    input logic operator_input,         // Operator input (e.g., '+' or '-')
    input logic equal_input,            // Equal input to trigger calculation
    output logic complete,              // Completion signal (calculation done)
    output logic [15:0] display_output, // Output to display
    input cs,                           // chip select
    input we,                           // write enable
    input oe,                           // output enable
    input [3:0] mem_addr,               // address of memory location
    input [31:0] mem_data,              // data list in memory
    output logic [31:0] data            // current data
);

    // Instantiate the Memory module
    single_port_sync_ram #(
        .ADDR_WIDTH(4),    // Adjust if needed
        .DATA_WIDTH(32),   // Adjust if needed
        .DEPTH(16)         // Adjust if needed
    ) memory_inst (
        .clk(clk),
        .mem_addr(mem_addr),
        .mem_data(mem_data),
        .cs(cs),
        .we(we),
        .oe(oe),
        .data(data)
    );

    // State definitions
    typedef enum logic [1:0] {
        GETTING_FIRST_NUMBER = 2'b00,  // State 1: Getting the first number
        GETTING_SECOND_NUMBER = 2'b01, // State 2: Getting the second number
        CALCULATING = 2'b10           // State 3: Performing calculation and showing result
    } state_t;

    state_t current_state, next_state;

    // Control signals for memory read/write and address/data
    logic [31:0] mem_1, mem_2;      // Memory locations for first and second numbers
    logic [31:0] arithmetic_result;  // ALU result (calculation result)
    
    // FSM: State transitions
    always_ff @(posedge clk or posedge reset) begin
        if (reset)
            current_state <= GETTING_FIRST_NUMBER;  // Go to initial state on reset
        else
            current_state <= next_state;  // Update state
    end

    // FSM: State logic for transitions based on inputs
    always_ff @(current_state or keypad_input or operator_input or equal_input) begin
        case (current_state)
            GETTING_FIRST_NUMBER: 
                if (keypad_input) begin  // Keypad input detected, store the number in mem_1
                    next_state = GETTING_FIRST_NUMBER;
                end else if (operator_input) begin  // If operator pressed, go to second number state
                    next_state = GETTING_SECOND_NUMBER;
                end else begin
                    next_state = GETTING_FIRST_NUMBER;
                end

            GETTING_SECOND_NUMBER: 
                if (keypad_input) begin  // Store the second number in mem_2
                    next_state = GETTING_SECOND_NUMBER;
                end else if (equal_input) begin  // If equal is pressed, go to calculating state
                    next_state = CALCULATING;
                end else begin
                    next_state = GETTING_SECOND_NUMBER;
                end

            CALCULATING: 
                next_state = CALCULATING;  // Remain in CALCULATING until calculation is complete
            
            default: 
                next_state = GETTING_FIRST_NUMBER;  // Default to the first state
        endcase
    end

    // Control logic for memory operations (read/write)
    always_ff @(posedge clk) begin
        case (current_state)
            GETTING_FIRST_NUMBER: begin
                if (keypad_input) begin
                    mem_addr <= 4'h1;  // Set memory address for first number
                    mem_1 <= mem_1 * 10 + keypad_input;  // Update mem_1 with the digit
                    we <= 1;  // Enable memory write
                    oe <= 0;  // Disable memory read
                end
            end

            GETTING_SECOND_NUMBER: begin
                if (keypad_input) begin
                    mem_addr <= 4'h2;  // Set memory address for second number
                    mem_2 <= mem_2 * 10 + keypad_input;  // Update mem_2 with the digit
                    we <= 1;  // Enable memory write
                    oe <= 0;  // Disable memory read
                end
            end

            CALCULATING: begin
                // Perform arithmetic operation in the ALU
                mem_addr <= 4'h3;  // Memory address to store the result
                arithmetic_result <= mem_1 + mem_2;  // Example: Addition operation
                mem_data <= arithmetic_result;    // Store result in memory
                we <= 1;  // Enable memory write for result
                oe <= 0;  // Disable memory read
            end

            default: begin
                we <= 0;  // Disable memory write in idle states
                oe <= 0;  // Disable memory read in idle states
            end
        endcase
    end

    // Output logic for completing the calculation
    always_ff @(posedge clk) begin
        if (current_state == CALCULATING) begin
            complete <= 1;  // Indicate calculation is done
            display_output <= arithmetic_result[15:0];  // Send the result to display
        end else begin
            complete <= 0;
            display_output <= 0;  // Clear display if no calculation is happening
        end
    end

    // Logic to read memory data when needed
    always_ff @(posedge clk) begin
        if (current_state == GETTING_FIRST_NUMBER) begin
            oe <= 1;  // Enable memory read for first number if necessary
            mem_addr <= 4'h1;  // Memory address for first number
        end else if (current_state == GETTING_SECOND_NUMBER) begin
            oe <= 1;  // Enable memory read for second number if necessary
            mem_addr <= 4'h2;  // Memory address for second number
        end else begin
            oe <= 0;  // Disable memory read when not in use
        end
    end

endmodule

