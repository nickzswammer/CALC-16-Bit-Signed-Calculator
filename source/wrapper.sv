
module wrapper(
    input CLOCK_50,
    input [3:0] KEY,
    input [17:0] SW,
    inout [34:0] GPIO,
    output logic [17:0] LEDR,
    output logic [7:0] LEDG
);

    logic [25 : 0] leds;
    logic auto_nRST;
    logic [3:0] auto_nRST_count;

    initial begin
        auto_nRST = 0;
        auto_nRST_count = 0;
    end

    logic nRST;
    logic [3:0] RowIn;
    logic [3:0] ColOut;
    logic complete;
    
    assign RowIn = {GPIO[25], GPIO[23], GPIO[21], GPIO[19]};
    assign {GPIO[17], GPIO[15], GPIO[13], GPIO[11]} = ColOut;
    assign LEDG[4] = complete;
    
    assign nRST = KEY[3] & auto_nRST;

    always_ff @(posedge CLOCK_50) begin
        if(auto_nRST_count != 4'hF) begin
            auto_nRST_count <= auto_nRST_count + 1;
            auto_nRST <= '0;
        end else begin
            auto_nRST <= '1;
        end
    end
	 
	 logic test;
	 
	 always_ff @(posedge CLOCK_50, negedge nRST) begin
			if (~nRST)
				test <= 0;
			else
				test <= 1;
	 end
	   
    calculator_top DUT(
        .clk(CLOCK_50),
        .nRST(nRST),
        .RowIn(RowIn),
        .ColOut(ColOut),
		.input_state_FPGA(LEDG[7:5]),
		.key_pressed(LEDG[1]),
        .display_output(LEDR[15:0]),
        .complete(complete)
    );
	 
	 assign LEDG[0] = test;
	 
//     assign {LEDR, LEDG} = leds;
endmodule
