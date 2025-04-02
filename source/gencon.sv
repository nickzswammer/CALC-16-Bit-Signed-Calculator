module gencon (
    input logic clk,                    // System clock
    input logic reset,                  // Reset signal
    input logic [3:0] keypad_input,     // 4-bit Keypad input (single digit)
    input logic operator_input,         // Operator input (ignored since only addition)
    input logic equal_input,            // Equal input to trigger addition
    output logic complete,              // Calculation completion flag
    output logic [15:0] display_output, // 16-bit output to display result
    
    // ALU Interface
    output logic [15:0] ALU_in1,        // Operand 1 to ALU
    output logic [15:0] ALU_in2,        // Operand 2 to ALU
    output logic start_calc,            // Start ALU calculation signal
    input logic [15:0] ALU_out,         // Result from ALU
    input logic ALU_finish,             // ALU finish signal
    
    // Memory Control
    input logic we,                     // Write enable
    input logic oe,                     // Output enable
    input logic [3:0] mem_addr,         // Memory address (2 bits: 00, 01, 10)
    input logic [15:0] mem_data,        // Data bus to update memory
    output logic [15:0] data             // Read Data

);

    addition add_calc(
        .clk(clk),
        .nRST(reset),  // Reset signal (active low)
        .INn1(ALU_in1),
        .INn2(ALU_in2),
        .sub(1'b0),       // No subtraction, only addition
        .start(start_calc),
        
        .out(ALU_out),
        .finish(ALU_finish)
    );
    
    memory mem (
        .clk(clk),
        .mem_addr(mem_addr),
        .mem_data(mem_data),
        .data(data),
        .we(we),
        .oe(oe)
    );
    
    // State Definitions
    typedef enum logic [2:0] {
        GET_FIRST_NUM = 3'b000,  // Getting the first operand
        GET_SECOND_NUM = 3'b001, // Getting the second operand
        SEND_TO_ALU   = 3'b010,  // Send operands to ALU
        WAIT_ALU      = 3'b011,  // Wait for ALU to finish
        SHOW_RESULT   = 3'b100   // Displaying result
    } state_t;
    
    state_t current_state, next_state;
    
    // Internal Registers
    logic [15:0] operand1, operand2;
    
    // FSM: State Transitions
    always_ff @(posedge clk or posedge reset) begin
        if (reset)
            current_state <= GET_FIRST_NUM;
        else
            current_state <= next_state;
    end
    
    // FSM: State Logic
    always_comb begin
        case (current_state)
            GET_FIRST_NUM:
                if (keypad_input != 4'b0000) 
                    next_state = GET_FIRST_NUM;
                else if (operator_input)     
                    next_state = GET_SECOND_NUM;
                else                         
                    next_state = GET_FIRST_NUM;
            
            GET_SECOND_NUM:
                if (keypad_input != 4'b0000)
                    next_state = GET_SECOND_NUM;
                else if (equal_input)
                    next_state = SEND_TO_ALU;
                else
                    next_state = GET_SECOND_NUM;
            
            SEND_TO_ALU:
                next_state = WAIT_ALU;  // Move to ALU wait state
            
            WAIT_ALU:
                if (ALU_finish) 
                    next_state = SHOW_RESULT;
                else
                    next_state = WAIT_ALU;
            
            SHOW_RESULT:
                next_state = GET_FIRST_NUM; // Reset after showing result
            
            default:
                next_state = GET_FIRST_NUM;
        endcase
    end
    
    // Memory & ALU Interaction
    always_ff @(posedge clk) begin
        case (current_state)
            GET_FIRST_NUM: begin
                if (keypad_input != 4'b0000) begin
                    operand1 <= operand1 * 10 + keypad_input; // Append digit
                    mem_addr <= 2'b00;  // Store in memory at address 00
                    mem_data <= operand1;
                    we <= 1;
                end
            end
    
            GET_SECOND_NUM: begin
                if (keypad_input != 4'b0000) begin
                    operand2 <= operand2 * 10 + keypad_input; // Append digit
                    mem_addr <= 2'b01;  // Store in memory at address 01
                    mem_data <= operand2;
                    we <= 1;
                end
            end
        
            SEND_TO_ALU: begin
                ALU_in1 <= operand1; // Send operands to ALU
                ALU_in2 <= operand2;
                start_calc <= 1; // Trigger ALU computation
            end
        
            WAIT_ALU: begin
                start_calc <= 0; // Stop ALU start signal
            end
        
            SHOW_RESULT: begin
                complete <= 1;  // Indicate calculation done
                display_output <= ALU_out;  // Store ALU result in display
            end
        
            default: begin
                we <= 0;
                complete <= 0;
            end
        endcase
    end
endmodule

