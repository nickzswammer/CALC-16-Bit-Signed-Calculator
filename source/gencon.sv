module gencon (
    input logic clk,                    // Clock signal
    input logic reset,                  // Reset signal
    input logic [3:0] keypad_input,     // Keypad input (4 bits representing a digit or operator)
    input logic operator_input,         // Operator input (e.g., '+' or '-')
    input logic equal_input,            // Equal input to trigger calculation
    output logic complete,              // Completion signal (calculation done)
    output logic [15:0] display_output, // Output to display
    output logic oe,              // Memory read signal
    output logic we,             // Memory write signal
    output logic [15:0] mem_addr,       // Memory address (which location to access)
    output logic [15:0] mem_data_in,    // Data to write to memory
    input logic [15:0] mem_data_out     // Data read from memory
);
