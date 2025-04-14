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

    // TB-only variables
    int test_number;
    int num_passed;

    int digit; // curr digit to be passed in to the press task
    int temp; // temp for getting MSB
    int num_digits; // for getting MSB
    int divisor; // for the getting MSB
    
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
        input integer num_1, // in decimal
        input [2:0] operation, // 001, 010, 100
        input integer num_2, // in decimal
        input integer expected_out // expected output
    );
        begin
            test_number += 1;
            reset_dut();
    
            // extract digits press for first number
    
            temp = num_1;
	    num_digits = 0;

            while (temp > 0) begin
                temp = temp / 10;
            	num_digits += 1;
	    end

    	    divisor = 1;

    	    for (int i = 1; i < num_digits; i++) begin
                divisor *= 10;
    	    end

    	    temp = num_1;

    	    while (divisor > 0) begin
        	digit = temp / divisor;
		press_digit(digit[3:0]);
        	temp = temp % divisor;
                divisor = divisor / 10;
    	    end
    
            // get operator 

            operator_input = operation;
            #20;
    
            // second number digit press 

            temp = num_2;
	    num_digits = 0;

            while (temp > 0) begin
                temp = temp / 10;
            	num_digits += 1;
	    end

    	    divisor = 1;

    	    for (int i = 1; i < num_digits; i++) begin
                divisor *= 10;
    	    end

    	    temp = num_2;

    	    while (divisor > 0) begin
        	digit = temp / divisor;
		press_digit(digit[3:0]);
        	temp = temp % divisor;
                divisor = divisor / 10;
	    end

 
            // equal press
            equal_input = 1;
		
            // Wait for completion
            wait (complete);
	     
	    $display("\n==========================================\n");
	    $display("Operands: %d, %d\n", num_1, num_2);        
	    $display("Result: %0d\n", display_output);
	
            
		if(expected_out[15:0] != display_output) begin
                $display("[Time %0t]: Expected %d, got %d\n", $time, expected_out, display_output);
            end else begin
                num_passed += 1;
            end
	    $display("==========================================\n");
    
            #50;
        end
    endtask
    
    initial begin
	$dumpfile("gencon.vcd");
	$dumpvars();

        test_number = 0;
        num_passed = 0;

        apply_inputs(1, 3'b001, 1, 2);
	apply_inputs(12, 3'b001, 31, 43);
	apply_inputs(98, 3'b001, 101, 199); 
	apply_inputs(4, 3'b010, 1, 3);
	apply_inputs(59, 3'b010, 41, 18);
	apply_inputs(2, 3'b010, 9, -7);
	apply_inputs(1, 3'b010, 2, -1);
	apply_inputs(1, 3'b100, 1, 1);
	apply_inputs(51, 3'b100, 2, 102);
	apply_inputs(11, 3'b100, 12, 132);

        $display("Passed %0d/%0d tests.\n", num_passed, test_number);
	$display("==========================================\n");

        $finish;
    end

endmodule
