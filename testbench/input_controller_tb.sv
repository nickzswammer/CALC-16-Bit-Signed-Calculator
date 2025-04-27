`timescale 1ns/1ps

module input_controller_tb;

    logic clk;
    logic nRST;
    logic [3:0] row;
    logic [3:0] col;

    logic [3:0] keypad_input;
    logic read_input;
    logic [2:0] operator_input;
    logic equal_input;

    // Instantiate the DUT (Device Under Test)
    input_controller dut (
        .clk(clk),
        .nRST(nRST),
        .row(row),
        .col(col),
        .keypad_input(keypad_input),
        .read_input(read_input),
        .operator_input(operator_input),
        .equal_input(equal_input)
    );

    // Clock generation (100 MHz -> 10 ns period)
    initial clk = 0;
    always #5 clk = ~clk;

    // Test sequence
    initial begin
        // Initialize
        nRST = 0;
        row = 4'b1111;
        #(100); // Wait 100 ns
        nRST = 1;
    
        // Press '2' key (column 1, row 0)
        simulate_keypress(2'd1, 2'd0); // Col1, Row0
        wait_for_read();
    
        row = 4'b1111;
        #(500_000); // 5ms gap
    
        // Press 'Addition' key (column 3, row 0)
        simulate_keypress(2'd3, 2'd0); // Col3, Row0
        wait_for_read();
    
        row = 4'b1111;
        #(500_000);
    
        // Press '*' key (Equal input) (column 0, row 3)
        simulate_keypress(2'd0, 2'd3); // Col0, Row3
        wait_for_read();
    
        row = 4'b1111;
        #(1_000_000);
    
        $finish;
    end


    // Task: Simulate pressing a key (by setting rows during the correct column active)
    task simulate_keypress(input logic [1:0] col_idx, input logic [1:0] row_idx);
        begin
            // Wait until DUT is scanning the correct column
            while (dut.scan_col !== col_idx) @(posedge clk);
            @(posedge clk); // Synchronize
    
            // Now press the key
            row = ~(4'b0001 << row_idx);
    
            // Hold key down long enough for debounce
            #(2_100_000); // Hold for 21ms
    
            // Release key immediately after hold
            row = 4'b1111;
            @(posedge clk); // Synchronize after release
        end
    endtask


    // Task: Wait for read_input signal
    task wait_for_read();
        begin
            @(posedge read_input);
            $display("[%0t ns] Key Press Detected: keypad_input=%0d, operator_input=%0d, equal_input=%0b",
                     $time, keypad_input, operator_input, equal_input);
        end
    endtask


endmodule
