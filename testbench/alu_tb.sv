module adder15_tb();
	logic [14:0] in1;
	logic [14:0] in2;
	logic sub;

	wire [14:0] sum;
	wire cOut;

adder15 dut(
	.sum(sum),
	.cOut(cOut),

	.in1(in1),
	.in2(in2),
	.sub(sub)
);

integer i;

initial begin
	$monitor("%d + %d = %d", in1, in2, sum);
	
	for(i = 0; i < 10; i = i + 1) begin
	
		sub = 1; 
		in1 = $urandom_range(255)[14:0];
		in2 = $urandom_range(255)[14:0];
		#10;
	end

	$finish;		
end
endmodule : adder15_tb
module addition_tb();
	logic [15:0] in1;
	logic [15:0] in2;
	logic sub;
	logic start;

	logic clk;
	logic nRST;

	wire [15:0] sum;
	wire finish;

addition dut(
	.INn1(in1),
	.INn2(in2),
	.sub(sub),
	.start(start),

	.clk(clk),
	.nRST(nRST),

	.out(sum),
	.finish(finish)
);

integer i;
integer j;

always #10 clk = ~clk;

initial begin

	//$monitor("%d + %d = %d finished: %d sign: %d", in1 [14 : 0], in2 [14 : 0], sum [14 : 0], finish, sum[15]);

	nRST = 1'b1;

	for(i = 0; i < 10; i = i + 1) begin
	
		sub = $urandom_range(255) [0];

		in1 [14 : 0] = 17; //$urandom_range(255) [14 : 0];
		in2 [14 : 0] = 0;//$urandom_range(255) [14 : 0];
		
		in1 [15] = $urandom_range(255) [0];
		in2 [15] = $urandom_range(255) [0];

		start = 1;

			while(!finish) begin
				#10;
			end

		if(in1 [15]) begin
			$write("-");
		end else begin
			$write("+");
		end

		$write("%1d ", in1 [14 : 0]);

		
		if(sub) begin
			$write("- ");
		end else begin
			$write("+ ");
		end

		if(in2 [15]) begin
			$write("-");
		end else begin
			$write("+");
		end

		$write("%1d = ", in2 [14 : 0]);

		if(sum [15]) begin
			$write("-");
		end else begin
			$write("+");
		end

		$write("%1d finish: %d\n", sum [14 : 0], finish);



		start = 0;

		#20;
	end

	$finish;		
end

endmodule : addition_tb
