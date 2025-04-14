
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
        reg [15:0] temp;
        reg [3:0] digit;
        begin
            temp = number;
            if (temp == 0) begin
                keypad_input = 0;
                read_input = 1;
                #10;
                read_input = 0;
                #10;
            end else begin
                int div = 10000;
                while (div > 0) begin
                    digit = (temp / div) % 10;
                    if (number >= div) begin
                        keypad_input = digit;
                        read_input = 1;
                        #10;
                        read_input = 0;
                        #10;
                    end
                    div = div / 10;
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
            complete = 0;

            enter_number(op1);
            operator_input = op;
            #20;

            enter_number(op2);
            equal_input = 1;
            #10;
            equal_input = 0;

            wait (complete);
            $display("RESULT: %0d", display_output);
            #40;
        end
    endtask

    // Test sequence
    initial begin
        nRST = 0;
        #20;
        nRST = 1;

        do_operation(12, 3'b001, 34);    // 12 + 34 = 46
        do_operation(100, 3'b010, 25);   // 100 - 25 = 75
        do_operation(6, 3'b100, 7);      // 6 * 7 = 42
        do_operation(123, 3'b001, 456);  // 123 + 456 = 579
        do_operation(0, 3'b001, 99);     // 0 + 99 = 99

        $finish;
    end

endmodule




/*module gencon_tb;

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

        $finish;
    end

endmodule*/
