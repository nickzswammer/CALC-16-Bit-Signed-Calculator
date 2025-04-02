module gencon (
    input logic clk,                    // System clock
    input logic reset,                  // Reset signal
    input logic [3:0] keypad_input,     // 4-bit Keypad input (single digit)
    input logic operator_input,         // Operator input (ignored since only addition)
    input logic equal_input,            // Equal input to trigger addition
    output logic complete,              // Calculation completion flag
    output logic [15:0] display_output, // 16-bit output to display result
    
    // ALU Interface - corrected directions
    output logic [15:0] ALU_in1,        // Operand 1 to ALU
    output logic [15:0] ALU_in2,        // Operand 2 to ALU
    output logic start_calc,            // Start ALU calculation signal
    output logic [15:0] ALU_out,         // Result from ALU
    output logic ALU_finish,             // ALU finish signal
    
    // Memory Control - corrected directions
    output logic we,                    // Write enable
    output logic oe,                    // Output enable
    output logic [3:0] mem_addr,        // Memory address
    output logic [15:0] mem_data,       // Data bus to update memory
);

    // Instantiate the addition module
    addition add_calc(
        .clk(clk),
        .nRST(~reset),  // Active low reset
        .INn1(ALU_in1),
        .INn2(ALU_in2),
        .sub(1'b0),     // No subtraction, only addition
        .start(start_calc),
        .out(ALU_out),
        .finish(ALU_finish)
    );
    
    // Instantiate the memory module
    memory mem (
        .clk(clk),
        .mem_addr(mem_addr),
        .mem_data(mem_data),
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
    logic keypad_valid;  // Flag to indicate valid keypad input
    logic prev_operator; // Track previous operator state
    logic prev_equal;    // Track previous equal state
    
    // Edge detection for inputs
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            prev_operator <= 0;
            prev_equal <= 0;
        end
        else begin
            prev_operator <= operator_input;
            prev_equal <= equal_input;
        end
    end
    
    // Define edge detection signals
    wire operator_edge = operator_input && !prev_operator;
    wire equal_edge = equal_input && !prev_equal;
    
    // FSM: State Transitions
    always_ff @(posedge clk or posedge reset) begin
        if (reset)
            current_state <= GET_FIRST_NUM;
        else
            current_state <= next_state;
    end
    
    // FSM: State Logic with improved transitions
    always_comb begin
        next_state = current_state;
        
        case (current_state)
            GET_FIRST_NUM:
                if (operator_edge)     
                    next_state = GET_SECOND_NUM;
            
            GET_SECOND_NUM:
                if (equal_edge)
                    next_state = SEND_TO_ALU;
            
            SEND_TO_ALU:
                next_state = WAIT_ALU;
            
            WAIT_ALU:
                if (ALU_finish) 
                    next_state = SHOW_RESULT;
            
            SHOW_RESULT:
                next_state = GET_FIRST_NUM; // Reset after showing result
            
            default:
                next_state = GET_FIRST_NUM;
        endcase
    end
    
    // Datapath: Register updates and control signals
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            operand1 <= 16'b0;
            operand2 <= 16'b0;
            display_output <= 16'b0;
            complete <= 0;
            we <= 0;
            oe <= 0;
            mem_addr <= 4'b0;
            mem_data <= 16'b0;
            start_calc <= 0;
            ALU_in1 <= 16'b0;
            ALU_in2 <= 16'b0;
        end
        else begin
            // Default values
            we <= 0;
            oe <= 0;
            complete <= 0;
            start_calc <= 0;
            
            case (current_state)
                GET_FIRST_NUM: begin
                    if (keypad_input != 4'b0000) begin
                        operand1 <= operand1 * 10 + {12'b0, keypad_input}; // Append digit
                        
                        // Store in memory
                        mem_addr <= 4'b0;
                        mem_data <= operand1 * 10 + {12'b0, keypad_input};
                        we <= 1;
                    end
                end
        
                GET_SECOND_NUM: begin
                    if (keypad_input != 4'b0000) begin
                        operand2 <= operand2 * 10 + {12'b0, keypad_input}; // Append digit
                        
                        // Store in memory
                        mem_addr <= 4'b1;
                        mem_data <= operand2 * 10 + {12'b0, keypad_input};
                        we <= 1;
                    end
                end
            
                SEND_TO_ALU: begin
                    ALU_in1 <= operand1;
                    ALU_in2 <= operand2;
                    start_calc <= 1;
                end
            
                WAIT_ALU: begin
                    // Keep start_calc low
                    start_calc <= 0;
                end
            
                SHOW_RESULT: begin
                    complete <= 1;
                    display_output <= ALU_out;
                    
                    // Store result in memory
                    mem_addr <= 4'b10;
                    mem_data <= ALU_out;
                    we <= 1;
                    
                    // Reset operands for next calculation
                    operand1 <= 16'b0;
                    operand2 <= 16'b0;
                end
            endcase
        end
    end
endmodule
