module input_control_tb();

  logic clk, nRST;
  logic [3:0] RowIn;
  logic [3:0] ColOut;
  logic read_input, key_read;
  logic [3:0] keypad_input;
  logic [2:0] operator_input;
  logic equal_input;

  input_control dut (
    .clk(clk), .nRST(nRST),
    .RowIn(RowIn), .ColOut(ColOut),
    .read_input(read_input), .key_read(key_read),
    .keypad_input(keypad_input),
    .operator_input(operator_input),
    .equal_input(equal_input)
  );

  always #5 clk = ~clk;

  task automatic apply_inputs(input int key_index);
    int row = key_index / 4;
    int col = key_index % 4;

    @(posedge clk);
    nRST = 0;
    @(posedge clk);
    nRST = 1;
    @(posedge clk);
	  
    // Wait until the correct column is active
    wait (ColOut == ~(4'b0001 << col));

    // Press the key by pulling the correct row low
    RowIn = ~(4'b0001 << row);

    // Hold for debounce cycles
    repeat (13) @(posedge clk);

    // Wait until in CONFIRM state (state == 3)
    wait(dut.state == 3);
    @(posedge clk);

    RowIn = 4'b1111;  // release key
    @(posedge clk);

    wait (read_input == 1);
    $display("Key [%0d] => keypad = %0d, op = %0d, eq = %0b",
              key_index, keypad_input, operator_input, equal_input);

    key_read = 1;
    @(posedge clk);
    key_read = 0;

    repeat (5) @(posedge clk);
  endtask

  initial begin
    $dumpfile("input_control.vcd");
    $dumpvars();

    clk = 0;
    nRST = 0;
    RowIn = 4'b1111;
    key_read = 0;
    keypad_input = 0;

    #10;
    nRST = 1;
    #20;

    // Try all 16 keys from index 0 to 15
    for (int i = 0; i < 16; i++) begin
      apply_inputs(i);
    end

    $display("✅ Finished testing all 16 keypad inputs.");
    #20;
    $finish;
  end

endmodule


/*
module input_control_tb();

	logic Reset, Clock;
	logic [3:0] RowIn;
	logic [3:0] ColOut;
	logic LFSRReset, LFSRFlg;
	logic read_input, key_read;
	logic [3:0] Number;
	logic [2:0] Operator;
	logic EqualSign;

	input_control dut (
        .Reset(Reset), .Clock(Clock),
        .RowIn(RowIn), .ColOut(ColOut),
        .LFSRReset(LFSRReset), .LFSRFlg(LFSRFlg),
        .read_input(read_input), .key_read(key_read),
        .Number(Number), .Operator(Operator), .EqualSign(EqualSign)
    );

	always #5 Clock = ~Clock;

	initial begin
		$dumpfile("input_control.vcd");
		$dumpvars();
		
		// Initialization
		Clock = 0;
		Reset = 1; LFSRFlg = 0; RowIn = 4'b1111; key_read = 0;
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

		key_read = 1; #10; key_read = 0;
		
		#20;
		$finish;
	end
endmodule
*/
