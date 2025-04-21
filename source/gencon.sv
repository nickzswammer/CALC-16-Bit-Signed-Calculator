module gencon (
    input logic clk,                
    input logic nRST,    

    // Operand, Operator, and Result Input
    input logic [3:0] keypad_input,     // 4-bit Keypad input (single digit)
    input logic read_input,              // if 1, read whatever is in keypad input, if 0, don't read
    
    input logic [2:0] operator_input,         // Operator Input [001 (add), 010 (subtract), 100 (multiplication)]
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

    // Signals Recieved from mult
    logic [15:0] mult_out;       // mult finish signal
    logic mult_finish;           // Result from mult

    // keypad check
    logic [3:0] prev_keypad_input;

    // getting operator multiplier logic states
    logic getting_op1;
    logic getting_op2;

    logic next_getting_op1, next_getting_op2;

    // instantiate ALU
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

    // instantiate multiply
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
        SEND_TO_MULT_OP1   = 3'b011,  // Send operands to ALU
        SEND_TO_MULT_OP2   = 3'b100,  // Send operands to ALU
        WAIT_ALU      = 3'b101,  // Wait for ALU to finish
        SHOW_RESULT_ALU   = 3'b110,   // Displaying result from ALU
        SHOW_RESULT_MULT   = 3'b111   // Displaying result from ALU
    } state_t;
    
    state_t current_state, next_state, last_state;
    
    // Internal Registers
    logic [15:0] operand1, operand2;
    
    // FSM: State Transitions
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            current_state <= SEND_TO_MULT_OP1;
            last_state <= SEND_TO_MULT_OP1;
            prev_keypad_input <= 0;
            operand1 <= 0;
            operand2 <= 0;
            complete <= 0;
            display_output <= 0;
            getting_op1 <= 0;
            getting_op2 <= 0;

        end

        else begin
            last_state <= current_state;
            current_state <= next_state;
            getting_op1 <= next_getting_op1;
            getting_op2 <= next_getting_op2;
        end
    end
    
    // FSM: State Logic
    always_comb begin
        next_getting_op1 = getting_op1;
        next_getting_op2 = getting_op2;

        case (current_state)
            GET_FIRST_NUM:
                if ((operator_input == 3'b001 || operator_input == 3'b010 || operator_input == 3'b100)) begin
                    next_state = SEND_TO_MULT_OP2;
                end 
                else begin                     
                    next_state = SEND_TO_MULT_OP1;
                end
            
            GET_SECOND_NUM:
                if (equal_input)
                    next_state = SEND_TO_ALU;
                else
                    next_state = SEND_TO_MULT_OP1;
            
            SEND_TO_ALU:
                next_state = WAIT_ALU;  // Move to ALU wait state

            SEND_TO_MULT_OP1:
                if (getting_op1) begin
                    next_state = WAIT_ALU;
                end
                else begin
                    next_state = SEND_TO_MULT_OP1;
                end
            
            SEND_TO_MULT_OP2:
                if (getting_op2) begin
                    next_state = WAIT_ALU;
                end
                else begin
                    next_state = SEND_TO_MULT_OP2;
                end
            
            WAIT_ALU:
                if (ALU_finish) begin
                    next_state = SHOW_RESULT_ALU;
                end
            
                else if (mult_finish) begin
                    if (getting_op1) begin
                        operand1 = mult_out;
                        next_state = GET_FIRST_NUM;
                        next_getting_op1 = 0;
                    end

                    else if (getting_op2) begin
                        operand2 = mult_out;
                        next_state = GET_SECOND_NUM;
                        next_getting_op2 = 0;
                    end

                    else begin
                        next_state = SHOW_RESULT_MULT;
                    end
                end
            
                else begin
                    next_state = WAIT_ALU;
                end
                
            SHOW_RESULT_ALU, SHOW_RESULT_MULT:
                next_state = GET_FIRST_NUM; // Reset after showing result
            
            default:
                next_state = GET_FIRST_NUM;
        endcase
    end
   
    // MEMORY AND ALU INTERACTIONS WOULD GO HERE
 
  // Memory & ALU Interaction
    always_ff @(posedge clk or negedge nRST) begin
        case (current_state) 
            GET_FIRST_NUM: begin
                $display("Current State: GET_FIRST_NUM");
                operand1 <= operand1 + {12'd0, keypad_input};
            end

            // multiply operator 1
            SEND_TO_MULT_OP1: begin
                $display("Current State: SEND TO MULT OP1");
                
                if (read_input) begin
                    mult_in1 <= operand1; // Send operands to ALU
                    mult_in2 <= 10;
                    getting_op1 <= 1;
                    start_mult <= 1;
                end

            end

            // multiply operator 2
            SEND_TO_MULT_OP2: begin

                if (read_input) begin
                    mult_in1 <= operand2; // Send operands to ALU
                    mult_in2 <= 10;
                    getting_op2 <= 1;
                    start_mult <= 1;
                end
                
            end
    
            GET_SECOND_NUM: begin
                $display("Current State: GET SECOND NUM");

                operand2 <= operand2 + {12'd0, keypad_input};
            end
        
            SEND_TO_ALU: begin
                $display("Current State: SENDTOALU");
                
                // operator logic
                if (operator_input == 3'b001) begin // addition
                    ALU_in1 <= operand1; // Send operands to ALU
                    ALU_in2 <= operand2;
                    
                    addOrSub <= 0; // 0 is addition
                    start_ALU <= 1; // Trigger ALU computation
                end
                else if (operator_input == 3'b010) begin // subtraction
                    ALU_in1 <= operand1; // Send operands to ALU
                    ALU_in2 <= operand2;
                    
                    addOrSub <= 1; // 1 is subtraction
                    start_ALU <= 1; // Trigger ALU computation
                end

                else if (operator_input == 3'b100) begin // multiplication
                    mult_in1 <= operand1; // Send operands to ALU
                    mult_in2 <= operand2;
                    
                    start_mult <= 1;
                end
            end
        
            WAIT_ALU: begin
                $display("Current State: WAIT_ALU");
                
                start_ALU <= 0; // Stop ALU start signal
                start_mult <= 0;
            end
        
            SHOW_RESULT_ALU: begin
                $display("Current State: SHOWRESULTALU");
                
                complete <= 1;  // Indicate calculation done
                display_output <= ALU_out;  // Store ALU result in display
            end

            SHOW_RESULT_MULT: begin
                $display("Current State: SHOW RESULT MULT");
                complete <= 1;  // Indicate calculation done
                display_output <= mult_out;  // Store ALU result in display
            end
        
            default: begin
                complete <= 0;
            end
        endcase
        prev_keypad_input <= keypad_input;
    end 
endmodule

