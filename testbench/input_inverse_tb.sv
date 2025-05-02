module input_inverse_tb();

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
    wait (ColOut == (4'b0001 << col));

    // Press the key by pulling the correct row low
    RowIn = (4'b0001 << row);

    // Hold for debounce cycles
    //repeat (13) @(posedge clk);

    // Wait until in CONFIRM state (state == 3)
	  wait(dut.state == state_t'(3));
    @(posedge clk);
    @(posedge clk);

    RowIn = 4'b0000;  // release key
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
	  $dumpfile("input_control_inverse.vcd");
    $dumpvars();

    clk = 0;
    nRST = 0;
    RowIn = 4'b0000;
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
