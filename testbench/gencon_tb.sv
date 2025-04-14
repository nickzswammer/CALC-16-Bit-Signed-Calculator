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

    // TB-only variables
    int test_number;
    int num_passed;
    
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

    task apply_inputs(
        input int num_1, // in decimal
        input [2:0] operation, // 001, 010, 100
        input int num_2, // in decimal
        input int expected_out // expected output
    );
        begin
            test_number += 1;
            reset_dut();
    
            int temp;
            int digit;
    
            // extract digits press for first number
    
            temp = num_1;
            while (temp > 0) begin
                digit = temp % 10;
                press_digit(digit);
                temp = temp / 10;
            end
    
            // get operator 
            operator_input = operation;
            #20;
    
            // second number digit press
            temp = num_2;
            while (temp > 0) begin
                digit = temp % 10;
                press_digit(digit);
                temp = temp / 10;
            end
    
            // equal press
            equal_input = 1;
            equal_input = 0;
    
            // Wait for completion
            wait (complete);
            $display("Result: %0d", display_output);
            
            if(expected_out != display_output) begin
                $display("[Time %0t]: Expected %d, got %d\n", $time, expected_out, display_output);
            end else begin
                num_passed += 1;
            end
    
            #50;
        end
    endtask
    
    initial begin
        test_number = 0;
        num_passed = 0;

        apply_inputs(1, 3'b001, 1, 2);

        $display("Passed %0d/%0d tests.", num_passed, test_number);

        $finish;
    end

endmodule
