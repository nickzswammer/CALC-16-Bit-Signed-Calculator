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
	  .input_state_FPGA(),
    .complete(complete),
	  .key_pressed()
  );

  // Clock generation
  always #5 clk = ~clk;

  task reset_dut();
    nRST = 0;
    @(negedge clk);
    @(negedge clk);

    @(negedge clk);  // reset pulse
    nRST = 1;
    @(posedge clk);
    
  endtask

  // simulates one key press
  task automatic press_key(input int key_index);
    int row = key_index / 4;
    int col = key_index % 4;

    // Wait for the right column to become active
    wait (ColOut == ~(4'b0001 << col));

    // Pull the correct row low (active low press)
    RowIn = ~(4'b0001 << row);

    wait(dut.input_ctrl_inst.input_control_state == 3);
    
    // Let gencon acknowledge
    wait (dut.gencon_inst.key_read == 1);
    @(posedge clk);
    @(posedge clk);

    // Release the key
    RowIn = 4'b1111;

    wait(dut.input_ctrl_inst.input_control_state == 0);
    @(posedge clk);
    
  endtask
  
 // press digits function basically extracts multiple digits and presses using press_key

  task automatic press_digits(input int val);
    int digits[10]; // support up to 10 digits
    int len = 0;

    // Extract digits in reverse
    do begin
        digits[len] = val % 10;
        val = val / 10;
        len++;
    end while (val > 0);

    // Press digits in forward order
    for (int i = len - 1; i >= 0; i--) begin
        press_key(get_digit_key(digits[i]));
    end
endtask

// high level function runs test cases given simple expression

  task automatic run_calc_sequence(
      input bit neg_op1,
      input int op1_val,
      input int operator_key,      // use KEY_ADD, KEY_SUB, KEY_MULT
      input bit neg_op2,
      input int op2_val,
      input int expected_result
  );

      saw_complete = 0;

      reset_dut();

      $display("\nStarting Calc: %0s%0d %0s %0s%0d",
          (neg_op1 ? "-" : ""), op1_val,
          (operator_key == KEY_ADD)  ? "+" :
          (operator_key == KEY_SUB)  ? "-" :
          (operator_key == KEY_MULT) ? "*" : "?",
          (neg_op2 ? "-" : ""), op2_val
      );

      if (neg_op1) press_key(KEY_NEG);
      press_digits(op1_val);

      press_key(operator_key);

      if (neg_op2) press_key(KEY_NEG);
      press_digits(op2_val);

      press_key(KEY_EQ);

      wait (saw_complete == 1);
      $display("\n✅ Completed. DUT Output: %0d (Expected: %0d)\n", display_output, expected_result);
      #20;
  endtask

  // function to return the keypad mapping for a specific digit

  function int get_digit_key(input int digit);
      case (digit)
          0: return 13; // KEY_0
          1: return 0;
          2: return 1;
          3: return 2;
          4: return 4;
          5: return 5;
          6: return 6;
          7: return 8;
          8: return 9;
          9: return 10;
          default: return 13; // fallback to KEY_0
      endcase
  endfunction

  // Map: keypad index for 3 + 4 =
  localparam KEY_ADD = 3; // A (Add)
  localparam KEY_SUB = 7; // B (Subtract)
  localparam KEY_MULT = 11; // C (Multiply)
  localparam KEY_NEG = 15; // D (Equal)
  localparam KEY_EQ = 12; // * (Equal)

  logic saw_complete = 0;

  always @(posedge clk) begin
      if (complete)
          saw_complete <= 1;
  end

  initial begin
    $monitor("Output: %b", display_output);
    $dumpfile("calculator_top.vcd");
    $dumpvars();

    clk = 0;
    nRST = 1;
    RowIn = 4'b1111;
    @(posedge clk);

    /*
      run_calc_sequence(
        input bit neg_op1,
        input int op1_val,
        input int operator_key,      // use KEY_ADD, KEY_SUB, KEY_MULT
        input bit neg_op2,
        input int op2_val,
        input int expected_result
      );
    */

    run_calc_sequence(1, 3, KEY_MULT, 1, 4, 12); // -3 * -4 = 12
    run_calc_sequence(0, 3, KEY_MULT, 0, 4, 12); // 3 * 4 = 12
    run_calc_sequence(0, 123, KEY_ADD, 0, 45, 168); // 123 + 45 = 168
    run_calc_sequence(0, 123, KEY_SUB, 0, 45, 78); // 123 - 45 = 78
    run_calc_sequence(0, 0, KEY_SUB, 0, 0, 0); // 0 - 0 = 0
    
    $finish;
  end

  initial begin
	repeat (10000) @(posedge clk);
	$display("TIMEOUT!!");
	$finish;
  end

endmodule
