module gencon_tb;

    // Testbench signals
    logic clk = 0;
    logic nRST;
    logic [3:0] keypad_input;
    logic [2:0] operator_input;
    logic equal_input;
    logic complete;
    logic signed [15:0] display_output;
    logic read_input;

    // Clock generation
    always #5 clk = ~clk; // every 5 time units, flip clock signal

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

    // Reset Task
    task reset_dut;
        begin
            keypad_input = 0;
            operator_input = 3'b000;
            equal_input = 0;
            nRST = 1'b0;
            
            @(posedge clk);
            @(posedge clk);
            @(negedge clk);
            nRST = 1'b1;
            @(negedge clk);
            @(negedge clk);
        end
    endtask

    initial begin
        // Reset sequence
        reset_dut();

        press_digit(1);
        press_digit(2);

        operator_input = 3'b001; // addition
        //operator_input = 3'b010; // subtraction
        //operator_input = 3'b100; // multiplication
        #20;

        press_digit(3);
        press_digit(4);

        // Equal pressed
        equal_input = 1;
        #10;
        equal_input = 0;

        // Wait for completion
        wait (complete);
        $display("Result: %0d", display_output);

        // Finish simulation
        #50;

        // Reset sequence
        reset_dut();

        press_digit(1);
        press_digit(5);

        //operator_input = 3'b001; // addition
        operator_input = 3'b010; // subtraction
        //operator_input = 3'b100; // multiplication
        #20;

        press_digit(7);

        // Equal pressed
        equal_input = 1;
        #10;
        equal_input = 0;

        // Wait for completion
        wait (complete);
        $display("Result: %0d", display_output);

        // Finish simulation
        #50;

        $finish;
    end

endmodule
