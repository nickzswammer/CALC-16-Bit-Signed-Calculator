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
            @(posedge clk);
            read_input = 1;
            @(posedge clk);
            read_input = 0;

	    @(negedge clk);
	    keypad_input = 0;
            @(posedge clk);
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
            nRST = 1'b1;
	    @(posedge clk);
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
            @(posedge clk);
    
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

	    $display("%s", $sformatf("Test #%d: ", test_number));
	     
	    $display("\n==========================================\n");

	    operator_input = operation;
	    if (operation == 3'b001) begin
    		$display("%s", $sformatf("Operation: Addition"));
	    end
	    else if (operation == 3'b010) begin
		$display("%s", $sformatf("Operation: Subtraction"));
	    end
	    else if (operation == 3'b100) begin
		$display("%s", $sformatf("Operation: Multiplication"));
	    end

	    $display("%s", $sformatf("Operands: %0d, %0d", num_1, num_2));      
		
	    $display("%s", $sformatf("Result: %0d", display_output));
	    $display("Binary Output: %b", display_output);
            
		if(expected_out[15:0] != display_output) begin
			$display("%s", $sformatf("[Time %0t]: ❌ Expected %0d, got %0d", $time, expected_out, display_output));
            end else begin
                num_passed += 1;
            end
	    $display("==========================================\n");
    
            @(posedge clk);
        end
    endtask
    
    initial begin
	$dumpfile("gencon.vcd");
	$dumpvars();

        test_number = 0;
        num_passed = 0;

	// Addition tests (3'b001)
	apply_inputs(2,   3'b001, 3, 5);            // 2 + 3 = 5
	apply_inputs(1000,3'b001, 2345, 3345);      // 1000 + 2345 = 3345
	apply_inputs(-10, 3'b001, 10, 0);           // -10 + 10 = 0
	apply_inputs(-25, 3'b001, -15, -40);        // -25 + -15 = -40
	apply_inputs(0,   3'b001, 0, 0);            // 0 + 0 = 0
	apply_inputs(-32768, 3'b001, 32767, -1);    // edge case
	
	// Subtraction tests (3'b010)
	apply_inputs(5,   3'b010, 3, 2);            // 5 - 3 = 2
	apply_inputs(3,   3'b010, 5, -2);           // 3 - 5 = -2
	apply_inputs(-3,  3'b010, -5, 2);           // -3 - (-5) = 2
	apply_inputs(-5,  3'b010, -3, -2);          // -5 - (-3) = -2
	apply_inputs(0,   3'b010, 99, -99);         // 0 - 99 = -99
	apply_inputs(99,  3'b010, 0, 99);           // 99 - 0 = 99
	
	// Multiplication tests (3'b100)
	apply_inputs(4,   3'b100, 3, 12);           // 4 * 3 = 12
	apply_inputs(-2,  3'b100, 5, -10);          // -2 * 5 = -10
	apply_inputs(-3,  3'b100, -6, 18);          // -3 * -6 = 18
	apply_inputs(0,   3'b100, 100, 0);          // 0 * 100 = 0
	apply_inputs(100, 3'b100, 0, 0);            // 100 * 0 = 0
	apply_inputs(1,   3'b100, -1, -1);          // 1 * -1 = -1
	apply_inputs(32767, 3'b100, 1, 32767);      // max positive * 1
	apply_inputs(-32768, 3'b100, 1, -32768);    // min negative * 1
	apply_inputs(128, 3'b100, 256, 32768);      // overflow borderline
	
	// Additional edge coverage
	apply_inputs(1234, 3'b001, -5678, -4444);   // addition with large neg
	apply_inputs(-999, 3'b010, 999, -1998);     // subtraction extreme
	apply_inputs(-12, 3'b100, 3000, -36000);    // large negative mult
	
	// Identity behavior
	apply_inputs(-1,  3'b001, 1, 0);            // -1 + 1 = 0
	apply_inputs(1,   3'b010, 1, 0);            // 1 - 1 = 0
	apply_inputs(1,   3'b100, 1, 1);            // 1 * 1 = 1
	apply_inputs(-1,  3'b100, 1, -1);           // -1 * 1 = -1
	apply_inputs(-1,  3'b100, -1, 1);           // -1 * -1 = 1


        $display("Passed %0d/%0d tests.\n", num_passed, test_number);
	$display("==========================================\n");

        $finish;
    end

endmodule
