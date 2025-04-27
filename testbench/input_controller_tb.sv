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

        // Press '2' key (column 0, row 1)
        simulate_keypress(0, 1);
        wait_for_read();

        // Release
        row = 4'b1111;
        #(500_000); // Wait ~5 ms between presses

        // Press 'Addition' key (column 0, row 3)
        simulate_keypress(0, 3);
        wait_for_read();

        row = 4'b1111;
        #(500_000);

        // Press 'Equal' key (column 2, row 2)
        simulate_keypress(2, 2);
        wait_for_read();

        row = 4'b1111;
        #(1_000_000); // Let simulation run a bit

        $finish;
    end

    // Task: Simulate pressing a key (by setting rows during the correct column active)
    task simulate_keypress(input int col_idx, input int row_idx);
        begin
            // Wait until the correct column is selected
            wait (dut.scan_col == col_idx);
            // Simulate row active (active low)
            row = ~(4'b0001 << row_idx);
            // Hold key down enough time for debounce
            #(2_100_000); // slightly longer than debounce (~21ms)
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
