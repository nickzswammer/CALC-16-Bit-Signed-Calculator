module gencon (
    input logic clk,                    // System clock
    input logic reset,                  // Reset signal (active high)
    // Keypad input is debounced externally.
    // We assume that when no key is pressed, keypad_input is 4'hF.
    input logic [3:0] keypad_input,     // 4-bit keypad digit (0-9 valid, 4'hF = idle)
    input logic operator_input,         // Operator input (ignored, only addition supported)
    input logic equal_input,            // Equal input to trigger addition
    output logic complete,              // Calculation completion flag
    output logic [15:0] display_output, // 16-bit output to display result
    
    // ALU Interface – ALU_out and ALU_finish are driven by the ALU module.
    output logic [15:0] ALU_in1,        // Operand 1 to ALU
    output logic [15:0] ALU_in2,        // Operand 2 to ALU
    output logic start_calc,            // Start ALU calculation signal
    output logic [15:0] ALU_out,        // Result from ALU
    output logic ALU_finish,            // ALU finish signal
    
    // Memory Control – note that the memory module port is named "data"
    output logic we,                    // Write enable
    output logic oe,                    // Output enable (unused in this code)
    output logic [3:0] mem_addr,        // Memory address
    output logic [15:0] mem_data        // Data bus to update memory
);

    // Instantiate the addition (ALU) module
    addition add_calc(
        .clk(clk),
        .nRST(~reset),          // Active low reset
        .INn1(ALU_in1),
        .INn2(ALU_in2),
        .sub(1'b0),             // Only addition, so sub = 0
        .start(start_calc),
        .out(ALU_out),
        .finish(ALU_finish)
    );
    
    // Instantiate the memory module.
    // The memory module expects a port called "data", not "mem_data".
    memory mem (
        .clk(clk),
        .mem_addr(mem_addr),
        .data(mem_data),
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
    
    // For edge detection on keypad_input, we store its previous value.
    // (Assuming idle = 4'hF, so any value != 4'hF indicates a key press.)
    logic [3:0] prev_keypad;
    always_ff @(posedge clk or posedge reset) begin
        if (reset)
            prev_keypad <= 4'hF;  // Idle state
        else
            prev_keypad <= keypad_input;
    end
    
    // Edge detection: a new key press is detected when keypad_input is not idle
    // and differs from its previous value.
    wire keypad_edge = (keypad_input != 4'hF) && (keypad_input != prev_keypad);
    
    // Edge detection for operator and equal signals (assumed debounced)
    logic prev_operator, prev_equal;
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            prev_operator <= 1'b0;
            prev_equal <= 1'b0;
        end else begin
            prev_operator <= operator_input;
            prev_equal <= equal_input;
        end
    end
    
    wire operator_edge = operator_input && !prev_operator;
    wire equal_edge    = equal_input && !prev_equal;
    
    // FSM: State Transitions
    always_ff @(posedge clk or posedge reset) begin
        if (reset)
            current_state <= GET_FIRST_NUM;
        else
            current_state <= next_state;
    end
    
    // FSM: Next State Logic
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
                // After showing result, restart for next calculation.
                next_state = GET_FIRST_NUM;
            
            default:
                next_state = GET_FIRST_NUM;
        endcase
    end
    
    // Datapath: Register Updates and Control Signals
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            operand1        <= 16'b0;
            operand2        <= 16'b0;
            display_output  <= 16'b0;
            complete        <= 1'b0;
            we              <= 1'b0;
            oe              <= 1'b0;
            mem_addr        <= 4'b0;
            mem_data        <= 16'b0;
            start_calc      <= 1'b0;
            ALU_in1         <= 16'b0;
            ALU_in2         <= 16'b0;
        end
        else begin
            // Default assignments in each cycle
            we         <= 1'b0;
            complete   <= 1'b0;
            start_calc <= 1'b0;
            
            case (current_state)
                GET_FIRST_NUM: begin
                    // On a valid new key press, accumulate the digit into operand1.
                    if (keypad_edge) begin
                        operand1 <= operand1 * 10 + {12'b0, keypad_input};
                        
                        // Write updated operand1 to memory at address 0.
                        mem_addr <= 4'b0000;
                        mem_data <= operand1 * 10 + {12'b0, keypad_input};
                        we       <= 1'b1;
                    end
                end
                
                GET_SECOND_NUM: begin
                    // On a valid new key press, accumulate the digit into operand2.
                    if (keypad_edge) begin
                        operand2 <= operand2 * 10 + {12'b0, keypad_input};
                        
                        // Write updated operand2 to memory at address 1.
                        mem_addr <= 4'b0001;
                        mem_data <= operand2 * 10 + {12'b0, keypad_input};
                        we       <= 1'b1;
                    end
                end
            
                SEND_TO_ALU: begin
                    // Load operands into ALU inputs and trigger calculation.
                    ALU_in1    <= operand1;
                    ALU_in2    <= operand2;
                    start_calc <= 1'b1;  // Assert start for one cycle.
                end
            
                WAIT_ALU: begin
                    // Wait state: maintain start_calc low.
                    start_calc <= 1'b0;
                end
            
                SHOW_RESULT: begin
                    // Indicate that the calculation is complete and display the result.
                    complete       <= 1'b1;
                    display_output <= ALU_out;
                    
                    // Write the ALU result to memory at address 2.
                    mem_addr <= 4'b0010;
                    mem_data <= ALU_out;
                    we       <= 1'b1;
                    
                    // Reset the operands for the next calculation.
                    operand1 <= 16'b0;
                    operand2 <= 16'b0;
                end
            endcase
        end
    end

endmodule

