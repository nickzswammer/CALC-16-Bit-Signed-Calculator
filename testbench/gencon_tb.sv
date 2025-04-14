module gencon_tb;

    // Testbench signals
    logic clk = 0;
    logic nRST;
    logic [3:0] keypad_input;
    logic [2:0] operator_input;
    logic equal_input;
    logic complete;
    logic [15:0] display_output;
    logic read_input;

    // Clock generation
    always #5 clk = ~clk; // 100 MHz clock

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

    // Task to simulate a digit keypress
    task press_digit(input [3:0] digit);
        begin
            keypad_input = digit;
            #10;
            read_input = 1;
            #10;
            read_input = 0;
            #10;
        end
    endtask

    // Simulate ALU finish behavior
    assign dut.ALU_finish = dut.start_ALU;
    assign dut.ALU_out = dut.ALU_in1 + (dut.addOrSub ? -dut.ALU_in2 : dut.ALU_in2);

    // Simulate Multiplier finish behavior
    assign dut.mult_finish = dut.start_mult;
    assign dut.mult_out = dut.mult_in1 * dut.mult_in2;

    initial begin
        // Reset sequence
        nRST = 0;
        keypad_input = 0;
        operator_input = 3'b000;
        equal_input = 0;
        #20;
        nRST = 1;

        // Input operand1 = 1 2
        press_digit(1);
        press_digit(1);

        // Operator = Add (3'b001)
        // Operator = Subtract (3'b010)
        // Operator = Add (3'b100)
        operator_input = 3'b100;
        #20;

        // Input operand2 = 3 4
        press_digit(1);
        press_digit(0);

        // Equal pressed
        equal_input = 1;
        #10;
        equal_input = 0;

        // Wait for completion
        wait (complete);
        $display("Result: %d", display_output);

        // Finish simulation
        #50;

                // Reset sequence
        nRST = 0;
        keypad_input = 0;
        operator_input = 3'b000;
        equal_input = 0;
        #20;
        nRST = 1;

        // Input operand1 = 1 2
        press_digit(1);
        press_digit(1);

        // Operator = Add (3'b001)
        // Operator = Subtract (3'b010)
        // Operator = Add (3'b100)
        operator_input = 3'b001;
        #20;

        // Input operand2 = 3 4
        press_digit(1);
        press_digit(0);

        // Equal pressed
        equal_input = 1;
        #10;
        equal_input = 0;

        // Wait for completion
        wait (complete);
        $display("Result: %d", display_output);

        // Finish simulation
        #50;
        $finish;
    end

endmodule
