// Testbench for gencon

`timescale 1ns/1ps

module gencon_tb;

    logic clk = 0;
    logic reset;
    logic [3:0] keypad_input;
    logic [1:0] operator_code;
    logic equal_input;

    logic complete;
    logic [15:0] display_output;

    logic we, oe;
    logic [3:0] mem_addr;
    logic [15:0] mem_data;
    logic [15:0] data = 16'd0;

    // Clock generation
    always #5 clk = ~clk; // 100 MHz clock

    // Instantiate DUT
    gencon dut (
        .clk(clk),
        .reset(reset),
        .keypad_input(keypad_input),
        .operator_code(operator_code),
        .equal_input(equal_input),
        .complete(complete),
        .display_output(display_output),
        .we(we),
        .oe(oe),
        .mem_addr(mem_addr),
        .mem_data(mem_data),
        .data(data)
    );

    // Mock ALU
    assign dut.ALU_finish = dut.start_calc;
    assign dut.ALU_out = dut.ALU_in1 + (dut.ALU_in2 ^ {16{dut.add_calc.sub}}) + dut.add_calc.sub;

    // Mock Multiplier
    assign dut.mul_finish = dut.start_mul;
    assign dut.mul_out = dut.mul_in1 * dut.mul_in2;

    // Task to press a digit
    task press_digit(input [3:0] digit);
        begin
            keypad_input = digit;
            #10;
            keypad_input = 0;
            #10;
        end
    endtask

    initial begin
        // Initialize
        reset = 1;
        keypad_input = 0;
        operator_code = 2'b11;
        equal_input = 0;
        #20;
        reset = 0;

        // Input: 12 + 34
        press_digit(1);
        press_digit(2);

        operator_code = 2'b00; // ADD
        #20;

        press_digit(3);
        press_digit(4);

        equal_input = 1;
        #10;
        equal_input = 0;

        wait (complete);
        $display("Result (12 + 34) = %d", display_output);

        #50;
        reset = 1;
        #20;
        reset = 0;

        // Input: 56 * 2
        press_digit(5);
        press_digit(6);

        operator_code = 2'b10; // MUL
        #20;

        press_digit(2);

        equal_input = 1;
        #10;
        equal_input = 0;

        wait (complete);
        $display("Result (56 * 2) = %d", display_output);

        $finish;
    end

endmodule
