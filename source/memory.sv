module memory
  ( 	
    input clk,
    input [1:0] mem_addr,
    input [15:0] mem_data,
    output [15:0] data,
    input cs,
    input we,
    input oe
  );

  reg [31:0] 	tmp_data;
  reg [31:0] 	mem [0:15];

  always @ (posedge clk) begin
    if (cs & we)
      mem[mem_addr] <= mem_data;
  end

  always @ (posedge clk) begin
    if (cs & !we)
    	tmp_data <= mem[mem_addr];
  end

  assign data = cs & oe & !we ? tmp_data : 'hz;
endmodule

