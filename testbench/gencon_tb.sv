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
	    if (operation == 3'b001) begin
		$display("Addition");
	    end
	    else if (operation == 3'b010) begin
		$display("Subtraction");
	    end
	    else if (operation == 3'b100) begin
		$display("Multiplication");
	    end

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

	    operator_input = operation;
	    if (operation == 3'b001) begin
		$display("Addition");
	    end
	    else if (operation == 3'b010) begin
		$display("Subtraction");
	    end
	    else if (operation == 3'b100) begin
		$display("Multiplication");
	    end

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

	// Addition tests
	apply_inputs(1,   3'b001, 2, 3);        // basic add
	apply_inputs(99,  3'b001, 1000, 2345);  // large values
	apply_inputs(50,  3'b001, -10, 10);     // neg + pos
	apply_inputs(4,   3'b001, -25, -15);    // neg + neg
	apply_inputs(2,   3'b001, 0, 0);        // zero + zero
	apply_inputs(3,   3'b001, -32768, 32767); // max negative + max positive
	
	// Subtraction tests
	apply_inputs(7,   3'b010, 5, 3);        // pos - pos (positive result)
	apply_inputs(8,   3'b010, 3, 5);        // pos - pos (negative result)
	apply_inputs(9,   3'b010, -3, -5);      // neg - neg (positive result)
	apply_inputs(10,  3'b010, -5, -3);      // neg - neg (negative result)
	apply_inputs(11,  3'b010, 32767, -32768); // extreme edge case
	apply_inputs(12,  3'b010, 0, 99);       // zero - pos
	apply_inputs(13,  3'b010, 99, 0);       // pos - zero
	
	// Multiplication tests
	apply_inputs(14,  3'b100, 4, 3);        // basic mult
	apply_inputs(15,  3'b100, -2, 5);       // neg * pos
	apply_inputs(16,  3'b100, -3, -6);      // neg * neg
	apply_inputs(17,  3'b100, 0, 100);      // 0 * pos
	apply_inputs(18,  3'b100, 100, 0);      // pos * 0
	apply_inputs(19,  3'b100, 1, -1);       // edge test
	apply_inputs(20,  3'b100, 32767, 1);    // max positive
	apply_inputs(21,  3'b100, -32768, 1);   // max negative
	apply_inputs(22,  3'b100, 256, 256);    // potential overflow
	
	// Mixed type operand stress
	apply_inputs(23,  3'b001, 1234, -5678);
	apply_inputs(24,  3'b010, -999, 999);
	apply_inputs(25,  3'b100, -12, 3000);
	
	// Identity tests
	apply_inputs(26,  3'b001, -1, 1);       // cancel to 0
	apply_inputs(27,  3'b010, 1, 1);        // cancel to 0
	apply_inputs(28,  3'b100, 1, 1);        // 1 * 1
	apply_inputs(29,  3'b100, -1, 1);       // -1 * 1
	apply_inputs(30,  3'b100, -1, -1);      // -1 * -1
	
	// Large number coverage
	apply_inputs(31,  3'b001, 16384, 16384); // sum near overflow
	apply_inputs(32,  3'b010, -16384, 16384); // large diff
	apply_inputs(33,  3'b100, 128, 256);    // medium mult
	
	// Zeros in all ops
	apply_inputs(34,  3'b001, 0, -10);
	apply_inputs(35,  3'b010, 0, -10);
	apply_inputs(36,  3'b100, 0, -10);
	apply_inputs(37,  3'b001, 0, 0);
	apply_inputs(38,  3'b010, 0, 0);
	apply_inputs(39,  3'b100, 0, 0);

        $display("Passed %0d/%0d tests.\n", num_passed, test_number);
	$display("==========================================\n");

        $finish;
    end

endmodule
