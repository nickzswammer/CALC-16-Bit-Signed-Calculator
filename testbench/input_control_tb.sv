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
		
		RowIn = 4'b1101;           // Active-low: row 0 pressed 
		#10;
		RowIn = 4'b1111;           // Release the key

		// 0111, 1011, 1101, 1110 (Bottom to Top)
		// 7FFF, BFFF
		
		#500;
		$display("Key Detected: Number = %x, Operator = %x, Equal = %b",
		         Number, Operator, EqualSign);

		KeyRd = 1; #10; KeyRd = 0;
		
		#20;
		$finish;
	end
endmodule
