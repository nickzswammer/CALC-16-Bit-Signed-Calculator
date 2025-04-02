`timescale 1ns / 1ps

module gencon_tb;
    // Testbench Signals
    logic clk;
    logic reset;
    logic [3:0] keypad_input;
    logic operator_input;
    logic equal_input;
    logic complete;
    logic [15:0] display_output;
    logic [15:0] ALU_in1, ALU_in2;
    logic start_calc;
    logic [15:0] ALU_out;
    logic ALU_finish;
    logic we, oe;
    logic [3:0] mem_addr;
    logic [15:0] mem_data;
    logic [15:0] data;
    logic [15:0] mul_in1, mul_in2;
    logic start_mul;
    logic [15:0] mul_out;
    logic mul_finish;

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
        .data(data),
        .mul_in1(mul_in1),
        .mul_in2(mul_in2),
        .start_mul(start_mul),
        .mul_out(mul_out),
        .mul_finish(mul_finish)
    );

    // Clock Generation
    always #5 clk = ~clk; // 10 ns clock period

    // Test Sequence
    initial begin
        clk = 0;
        reset = 1;
        keypad_input = 0;
        operator_input = 0;
        equal_input = 0;
        ALU_finish = 0;
        mul_finish = 0;

        #10 reset = 0; // Release reset
        
        // Enter first number: 23 (Sequential Keypad Presses)
        #10 keypad_input = 4'd2; #10 keypad_input = 4'd0;
        #10 keypad_input = 4'd3; #10 keypad_input = 4'd0;
        
        #10 operator_input = 1; // Press operator to move to second number
        #10 operator_input = 0;
        
        // Enter second number: 45 (Sequential Keypad Presses)
        #10 keypad_input = 4'd4; #10 keypad_input = 4'd0;
        #10 keypad_input = 4'd5; #10 keypad_input = 4'd0;
        
        #10 equal_input = 1; // Press equal to start addition
        #10 equal_input = 0;
        
        // Simulate ALU finish signal
        #20 ALU_out = 16'd68; // Expected result: 23 + 45 = 68
        ALU_finish = 1;
        #10 ALU_finish = 0;
        
        #50; // Wait for result to be displayed
        
        $display("Final Output: %d", display_output);
        
        #50 $finish; // End simulation
    end
endmodule

