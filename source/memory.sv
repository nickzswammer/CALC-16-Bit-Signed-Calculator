module memory
  ( 	
    input clk,
    input [3:0] mem_addr,
    input [15:0] mem_data,
    output [15:0] data,
    input we,
    input oe
  );

  reg [15:0] tmp_data;
  reg [15:0] mem [0:15];

  always @ (posedge clk) begin
    if (we)
      mem[mem_addr] <= mem_data;
  end

  always @ (posedge clk) begin
    if (!we)
    	tmp_data <= mem[mem_addr];
  end

  assign data = oe & !we ? tmp_data : 16'hz;
endmodule

