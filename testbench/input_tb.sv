module read_tb();

	logic Reset;
	logic Clock;
	logic [3:0] RowIn;
        logic [3:0] ColOut;
    	logic LFSRReset;
    	logic LFSRFlg;
    	logic [3:0] RowColVector;
    	logic KeyRdy;
    	logic KeyRd;

	read dut (
       	 .Reset(Reset),
       	 .Clock(Clock),
       	 .RowIn(RowIn),
       	 .ColOut(ColOut),
       	 .LFSRReset(LFSRReset),
       	 .LFSRFlg(LFSRFlg),
       	 .RowColVector(RowColVector),
       	 .KeyRdy(KeyRdy),
       	 .KeyRd(KeyRd)
  	);

	always #5 Clock = ~Clock;


	initial begin
		
		Reset = 1;
        	Clock = 0;
       		 RowIn = 4'b1111; //start with no key pressed
       		 LFSRFlg = 0;
        	KeyRd = 0;	
		$monitor("button pressed is %d",RowColVector);

	end
endmodule 
