module gencon (
    input logic clk,                
    input logic nRST,    

    // Operand, Operator, and Result Input
    input logic [3:0] keypad_input,     // 4-bit Keypad input (single digit)
    input logic [2:0] operator_input,         // Operator Input [001 (add), 010 (subtract), 100 (multiplication)
    input logic equal_input,            // Equal input to trigger addition

    output logic complete,              // Calculation completion flag
    output logic [15:0] display_output // 16-bit output to display result

);
    // Signals to Send to ALU (ONLY ADDITION AND SUBTRACTION)
    logic [15:0] ALU_in1;        // Operand 1 to ALU
    logic [15:0] ALU_in2;        // Operand 2 to ALU
    logic addOrSub; // 0 for add, 1 for subtraction
    logic start_ALU;            // Start ALU calculation signal
    
    // Signals Recieved from ALU
    logic ALU_finish;             // ALU finish signal
    logic [15:0] ALU_out;         // Result from ALU

    // Signals to Send to Multiplier
    logic [15:0] mult_in1;        // Operand 1 to mult
    logic [15:0] mult_in2;        // Operand 2 to mult
    logic start_mult;            // Start mult calculation signal
    
    logic [15:0] mult_out;
    logic mult_finish;


    addition add_calc(
        .clk(clk),
        .nRST(nRST),  // Reset signal (active low)

        .INn1(ALU_in1),
        .INn2(ALU_in2),
        .sub(addOrSub),
        
        .start(start_ALU), // to tell ALU to start
        
        .out(ALU_out),
        .finish(ALU_finish)
    );

    multiply mult_calc(
        .clk(clk),
        .nRST(nRST),

        .INn1(mult_in1),
        .INn2(mult_in2),
        
        .start(start_mult), // to tell mult to start
        
        .out(mult_out),
        .finish(mult_finish)
    );
    
    // State Definitions
    typedef enum logic [2:0] {
        GET_FIRST_NUM = 3'b000,  // Getting the first operand
        GET_SECOND_NUM = 3'b001, // Getting the second operand
        SEND_TO_ALU   = 3'b010,  // Send operands to ALU
        WAIT_ALU      = 3'b011,  // Wait for ALU to finish
        SHOW_RESULT   = 3'b100   // Displaying result
    } state_t;
    
    state_t current_state, next_state, last_state;
    
    // Internal Registers
    logic [15:0] operand1, operand2;
    
    // FSM: State Transitions
    always_ff @(posedge clk or posedge nRST) begin
        if (nRST) begin
            current_state <= GET_FIRST_NUM;
            last_state <= GET_FIRST_NUM;
        end

        else begin
            last_state <= current_state;
            current_state <= next_state;
        end
        
        if (current_state != last_state) begin
            $display("STATE CHANGE: %0t ns: %0d -> %0d", $time, last_state, current_state);
        end
    end
    
    // FSM: State Logic
    always_comb begin
        case (current_state)
            GET_FIRST_NUM:
                if (keypad_input == 4'b0000 && (operator_input == 3'b001 || operator_input == 3'b010 || operator_input == 3'b100)) begin
                    next_state = GET_SECOND_NUM;
                end 
                else begin                     
                    next_state = GET_FIRST_NUM;
                end
            
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
   
    // MEMORY AND ALU INTERACTIONS WOULD GO HERE
 
  // Memory & ALU Interaction
    always_ff @(posedge clk or posedge nRST) begin
        case (current_state)
            GET_FIRST_NUM: begin
                //$display("GETTING FIRST NUMBER");
                if (keypad_input != 4'b0000) begin
                    operand1 <= (operand1 << 3) + (operand1 << 1) + {12'd0, keypad_input};
                end
            end
    
            GET_SECOND_NUM: begin
                $display("GETTING SECOND NUMBER");

                if (keypad_input != 4'b0000) begin
                    operand2 <= (operand2 << 3) + (operand2 << 1) + {12'd0, keypad_input};
                end
            end
        
            SEND_TO_ALU: begin
                ALU_in1 <= operand1; // Send operands to ALU
                ALU_in2 <= operand2;
                start_ALU <= 1; // Trigger ALU computation
                // ========================================================================================================================================
                addOrSub <= 1; // THIS IS A DEBUG STATEMENT PLEASE REMOVE AFTER, STILL HAVE TO IMPLEMENT MULTIPLICATION CHOOSING OR ADDITION SUBTRACTIon
                // ========================================================================================================================================
            end
        
            WAIT_ALU: begin
                start_ALU <= 0; // Stop ALU start signal
            end
        
            SHOW_RESULT: begin
                complete <= 1;  // Indicate calculation done
                display_output <= ALU_out;  // Store ALU result in display
            end
        
            default: begin
                complete <= 0;
            end
        endcase
    end 
endmodule

