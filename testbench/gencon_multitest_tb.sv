
`timescale 1ns / 1ps

module gencon_tb;

    // Inputs
    logic clk = 0;
    logic nRST;
    logic [3:0] keypad_input;
    logic read_input;
    logic [2:0] operator_input;
    logic equal_input;

    // Outputs
    logic complete;
    logic [15:0] display_output;

    // Instantiate DUT
    gencon dut (
        .clk(clk),
        .nRST(nRST),
        .keypad_input(keypad_input),
        .read_input(read_input),
        .operator_input(operator_input),
        .equal_input(equal_input),
        .complete(complete),
        .display_output(display_output)
    );

    // Clock generation
    always #5 clk = ~clk;

    // Simulate ALU finish behavior
    assign dut.ALU_finish = dut.start_ALU;
    assign dut.ALU_out = dut.ALU_in1 + (dut.addOrSub ? -dut.ALU_in2 : dut.ALU_in2);

    // Simulate Multiplier finish behavior
    assign dut.mult_finish = dut.start_mult;
    assign dut.mult_out = dut.mult_in1 * dut.mult_in2;

    // Task to simulate digit entry
    task enter_number(input [15:0] number);
        integer i;
        reg [3:0] digit;
        reg [15:0] temp;
        begin
            temp = number;
            int digits[0:4]; // at most 5 digits
            for (i = 4; i >= 0; i--) begin
                digits[i] = temp % 10;
                temp = temp / 10;
            end
            for (i = 0; i < 5; i++) begin
                if (number >= 10**i) begin
                    keypad_input = digits[i];
                    read_input = 1;
                    #10;
                    read_input = 0;
                    #10;
                end
            end
        end
    endtask

    // Task to perform one operation
    task do_operation(input [15:0] op1, input [2:0] op, input [15:0] op2);
        begin
            @(negedge clk);
            operator_input = 3'b000;
            equal_input = 0;
            keypad_input = 0;
            read_input = 0;

            // Reset complete flag
            complete = 0;

            // First operand
            enter_number(op1);

            // Operator
            operator_input = op;
            #20;

            // Second operand
            enter_number(op2);

            // Equal
            equal_input = 1;
            #10;
            equal_input = 0;

            // Wait for complete
            wait (complete);
            $display("RESULT: %0d", display_output);
            #40;
        end
    endtask

    // Test sequence
    initial begin
        // Reset
        nRST = 0;
        #20;
        nRST = 1;

        // Add: 12 + 34 = 46
        do_operation(12, 3'b001, 34);

        // Sub: 100 - 25 = 75
        do_operation(100, 3'b010, 25);

        // Mul: 6 * 7 = 42
        do_operation(6, 3'b100, 7);

        // Add: 123 + 456 = 579
        do_operation(123, 3'b001, 456);

        $finish;
    end

endmodule
