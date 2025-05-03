`timescale 1ns / 1ns

module calculator_top_tb();

  logic clk, nRST;
  logic [3:0] RowIn;
  logic [3:0] ColOut;
  logic [15:0] display_output;
  logic complete;

  calculator_top dut (
    .clk(clk),
    .nRST(nRST),
    .RowIn(RowIn),
    .ColOut(ColOut),
    .display_output(display_output),
    .complete(complete)
  );

  // Clock generation
  always #5 clk = ~clk;

  // Helper: simulate a key press
  task automatic press_key(input int key_index);
    int row = key_index / 4;
    int col = key_index % 4;

	  $display("Row: %d, Col: %d, Time: %0t", row, col, $time);
	  
	  
    // Wait for the right column to become active
    wait (ColOut == ~(4'b0001 << col));
    @(posedge clk);

    // Pull the correct row low (active low press)
    RowIn = ~(4'b0001 << row);

	  $display("RowIn: %b, ColOut: %b, Time: %0t", ColOut, RowIn, $time);
    @(posedge clk);  // debounce or FSM transition delay
    @(posedge clk);

    wait(dut.input_ctrl_inst.state == 3);
    
    @(posedge clk);
    @(posedge clk);

    // Let gencon acknowledge
    wait (dut.gencon_inst.key_read == 1);
    @(posedge clk);

    // Release the key
    RowIn = 4'b1111;
    @(posedge clk);
    @(posedge clk);
    
  endtask

  // Map: keypad index for 3 + 4 =
  localparam KEY_3 = 2;   // 3
  localparam KEY_5 = 5;   // 3
  localparam KEY_7 = 8;   // 3
  localparam KEY_ADD = 3; // A (Add)
  localparam KEY_SUB = 7; // S (Subtract)
  localparam KEY_MULT = 11; // A (Add)
  localparam KEY_4 = 4;   // 4
  localparam KEY_EQ = 12; // D (Equal)
  localparam KEY_NEG = 15; // D (Equal)

  initial begin
    $dumpfile("calculator_top.vcd");
    $dumpvars();

    clk = 0;
    nRST = 1;
    RowIn = 4'b1111;
    #(1);
    nRST = 0;
    @(negedge clk);
    @(negedge clk);

    @(negedge clk);  // reset pulse
    nRST = 1;

    // Sequence: -3 * -4 = 12
    press_key(KEY_NEG); // negative
    press_key(KEY_3);
	  
    press_key(KEY_MULT);

    press_key(KEY_NEG); // negative
    press_key(KEY_4);
    press_key(KEY_EQ);

    wait (complete == 1);
    $display("✅ Result: %0d", display_output);

    #20;
	  
    // Sequence: 3 * 4 = 12
    press_key(KEY_3);
    press_key(KEY_MULT);
	  
    press_key(KEY_4);
    press_key(KEY_EQ);

    wait (complete == 1);
    $display("✅ Result: %0d", display_output);

    #20;

    // Sequence: 3 + 4 = 7
    press_key(KEY_3);
    press_key(KEY_ADD);
	  
    press_key(KEY_4);
    press_key(KEY_EQ);

    wait (complete == 1);
    $display("✅ Result: %0d", display_output);

    #20;

    // Sequence: 5 - 4 = 1
    press_key(KEY_5);
    press_key(KEY_SUB);
	  
    press_key(KEY_4);
    press_key(KEY_EQ);

    wait (complete == 1);
    $display("✅ Result: %0d", display_output);

    #20;

	  @(posedge clk);
    // Sequence: -5 - 4 = -9
    press_key(KEY_NEG);
    press_key(KEY_5);
    press_key(KEY_SUB);
	  
    press_key(KEY_4);
    press_key(KEY_EQ);

    wait (complete == 1);
    $display("✅ Result: %0d", display_output);

    #20;

	@(posedge clk);
    // Sequence: -5 - 4 = -9
    press_key(KEY_5);
	  press_key(KEY_3);
    press_key(KEY_SUB);
	  
    press_key(KEY_4);
	  press_key(KEY_5);
    press_key(KEY_EQ);

    wait (complete == 1);
    $display("✅ Result: %0d", display_output);

    #20;
	  
    $finish;
  end

  // timeout block
  initial begin
    repeat(100000) @(negedge clk);
    $finish;
  end

endmodule
