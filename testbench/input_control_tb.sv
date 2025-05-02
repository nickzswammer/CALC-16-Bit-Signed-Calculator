module input_control_tb();

  logic clk, nRST;
  logic [3:0] RowIn;
  logic [3:0] ColOut;
  logic KeyRdy, KeyRd;
  logic [3:0] keypad_input;
  logic [2:0] operator_input;
  logic equal_input;

  input_control dut (
    .clk(clk), .nRST(nRST),
    .RowIn(RowIn), .ColOut(ColOut),
    .KeyRdy(KeyRdy), .KeyRd(KeyRd),
    .keypad_input(keypad_input),
    .operator_input(operator_input),
    .equal_input(equal_input)
  );

  // Clock
  always #5 clk = ~clk;

  initial begin
    $dumpfile("input_control.vcd");
    $dumpvars();

	  $monitor("State, Counter: %d %d", dut.state, dut.debounce_cnt);

    // Initialization
    clk = 0;
    nRST = 0;
    RowIn = 4'b1111;
    KeyRd = 0;

    #10;
    nRST = 1;
    #10;


    // Wait for ColOut to scan to column 0 (ColOut = 4'b1110)
    wait (ColOut == 4'b1110);  // column 0 active (bit 0 driven low)

    // Simulate key press in row 0
    RowIn = 4'b1110; // row 0 pulled low (key '1')

    // Hold for debounce
	  repeat (13) @(posedge clk);

	  wait(dut.state == 3);
	  #10;
    RowIn = 4'b1111; // release key
	  #10;

    // Wait for KeyRdy
    wait (KeyRdy == 1);
    $display("Key Detected: keypad_input = %0d, operator = %0d, equal = %0b",
              keypad_input, operator_input, equal_input);

    // Check if key '1' was detected
    if (keypad_input == 4'd1 && operator_input == 3'b000 && equal_input == 0)
      $display("✅ Test PASSED: Key '1' correctly detected.");
    else
      $display("❌ Test FAILED: Expected 1, got keypad_input = %0d", keypad_input);

    // Acknowledge read
    KeyRd = 1;
    @(posedge clk);
    KeyRd = 0;

	  @(posedge clk);
	nRST = 0;
	  @(posedge clk);
	nRST = 1;
	  
    #20 $finish;
  end

endmodule

/*
module input_control_tb();

	logic Reset, Clock;
	logic [3:0] RowIn;
	logic [3:0] ColOut;
	logic LFSRReset, LFSRFlg;
	logic KeyRdy, KeyRd;
	logic [3:0] Number;
	logic [2:0] Operator;
	logic EqualSign;

	input_control dut (
        .Reset(Reset), .Clock(Clock),
        .RowIn(RowIn), .ColOut(ColOut),
        .LFSRReset(LFSRReset), .LFSRFlg(LFSRFlg),
        .KeyRdy(KeyRdy), .KeyRd(KeyRd),
        .Number(Number), .Operator(Operator), .EqualSign(EqualSign)
    );

	always #5 Clock = ~Clock;

	initial begin
		$dumpfile("input_control.vcd");
		$dumpvars();
		
		// Initialization
		Clock = 0;
		Reset = 1; LFSRFlg = 0; RowIn = 4'b1111; KeyRd = 0;
		#10 Reset = 0;
		#10 Reset = 1;

		#10;
		LFSRFlg = 1;
		#10;
		
		RowIn = 4'b1110;           // Active-low: row 0 pressed 
		#10;
		RowIn = 4'b1111;           // Release the key

		// 0111, 1011, 1101, 1110 (Bottom to Top)
		// 7FFF, BFFF, DFFF, EFFF
		
		#500;
		$display("Key Detected: Number = %x, Operator = %x, Equal = %b",
		         Number, Operator, EqualSign);

		KeyRd = 1; #10; KeyRd = 0;
		
		#20;
		$finish;
	end
endmodule
*/
