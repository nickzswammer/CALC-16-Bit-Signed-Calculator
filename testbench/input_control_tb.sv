module input_control_tb();

	logic Reset;
	logic Clock;
	logic [3:0] RowIn;
        logic [3:0] ColOut;
    	logic LFSRReset;
    	logic LFSRFlg;
    	logic [3:0] Number;
	logic [2:0] Operator;
	logic EqualSign;
    	logic KeyRdy;
    	logic KeyRd;

	input_control dut (
       	 .Reset(Reset),
       	 .Clock(Clock),
       	 .RowIn(RowIn),
       	 .ColOut(ColOut),
       	 .LFSRReset(LFSRReset),
       	 .LFSRFlg(LFSRFlg),
       	 .KeyRdy(KeyRdy),
       	 .KeyRd(KeyRd),
	 .Number(Number),
	 .Operator(Operator),
	 .EqualSign(EqualSign)		 
  	);

	always #5 Clock = ~Clock;


	initial begin	
		$dumpfile("input_control.vcd");
		$dumpvars();
		
		Reset = 1;
		Clock = 0;
		RowIn = 4'b1111; //start with no key pressed
		LFSRFlg = 0;
		KeyRd = 0;	
		$monitor("button pressed is %d", Number);
			
		RowIn = 4'b1011;
		
		$monitor("When RowIn 4'b1011, Number = %d", Number);
		
		RowIn = 4'b0001;
		$monitor("When RowIN 4'b0001, Number = %d", Number);
	
		$finish;
	end
endmodule 
