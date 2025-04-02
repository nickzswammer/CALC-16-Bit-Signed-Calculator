/*
Testbench for the General Controller FSM
*/
module test_gencon;

    // Testbench signals
    logic clk;
    logic reset;
    logic [3:0] keypad_input;
    logic operator_input;
    logic equal_input;
    logic [15:0] ALU_in1;
    logic [15:0] ALU_in2;
    logic start_calc;
    logic complete;
    logic [15:0] display_output;
    logic [15:0] ALU_out;
    logic ALU_finish;
    logic we;
    logic oe;
    logic [3:0] mem_addr;
    logic [15:0] mem_data;
    logic [15:0] data;
    
    // Instantiate the gencon module
    gencon uut (
        .clk(clk),
        .reset(reset),
        .keypad_input(keypad_input),
        .operator_input(operator_input),
        .equal_input(equal_input),
        .complete(complete),
        .display_output(display_output),
        .ALU_in1(ALU_in1),
        .ALU_in2(ALU_in2),
        .start_calc(start_calc),
        .ALU_out(ALU_out),
        .ALU_finish(ALU_finish),
        .we(we),
        .oe(oe),
        .mem_addr(mem_addr),
        .mem_data(mem_data),
        .data(data)
    );
    
    // Clock Generation
    always begin
        #5 clk = ~clk;  // Generate a clock with period of 10 time units
    end
    
    // Stimulus Block
    initial begin
        // Initialize signals
        clk = 0;
        reset = 0;
        keypad_input = 4'b0000;
        operator_input = 0;
        equal_input = 0;
        ALU_in1 = 0;
        ALU_in2 = 0;
        start_calc = 0;
        we = 0;
        oe = 0;
        mem_addr = 4'b0000;
        mem_data = 16'b0;

        // Apply reset
        $display("Applying reset...");
        reset = 1;
        #10;
        reset = 0;
        
        // Test 1: First Number Input (Operand 1)
        $display("Testing First Number Input");
        keypad_input = 4'b0001;  // Input '1' from keypad
        #10;
        keypad_input = 4'b0010;  // Input '2' from keypad
        #10;
        keypad_input = 4'b0000;  // Input end
        #10;
        
        // Test 2: Operator Input (Operator Input is ignored in this case, but simulate a press)
        operator_input = 1;  // This will move to GET_SECOND_NUM state
        #10;
        operator_input = 0;
        
        // Test 3: Second Number Input (Operand 2)
        $display("Testing Second Number Input");
        keypad_input = 4'b0011;  // Input '3' from keypad
        #10;
        keypad_input = 4'b0100;  // Input '4' from keypad
        #10;
        keypad_input = 4'b0000;  // End second number input
        #10;
        
        // Test 4: Equal Input (Trigger ALU calculation)
        $display("Testing Equal Input");
        equal_input = 1;  // Trigger ALU calculation
        #10;
        equal_input = 0;
        
        // Test 5: ALU Calculation Finish
        $display("Testing ALU Finish");
        ALU_finish = 1;  // Simulate ALU finishing the calculation
        #10;
        
        // Test 6: Check final result on display
        $display("Checking final result");
        #10;
        
        // Test done, end simulation
        $finish;
    end
endmodule

