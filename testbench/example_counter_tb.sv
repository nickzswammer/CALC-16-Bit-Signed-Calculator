// $Id: $
// File name:   example_counter_tb.sv
// Created:     2/20/2025
// Author:      Miguel Isrrael Teran
// Description: Test bench for example counter

`timescale 1ns / 10ps

module example_counter_tb ();

    // Local parameters
    localparam CLK_PERIOD = 10;  // Clock period is 10 ns

    // Test bench signals
    integer tb_check_count;
    integer tb_passed;
    
    // DUT portmap signals
    logic clk;
    logic n_rst;
    logic clear;
    logic count_enable;
    logic [3:0] rollover_val;
    logic [3:0] count_out;
    logic rollover_flag;

    // DUT Instance
    example_counter DUT (.*);

    // Signal Dump - this is needed for the waves!
    initial begin
        $dumpfile ("example_counter.vcd");
        $dumpvars;
    end

    // Clock generation
    always begin
        clk = 1'b0;
        #(CLK_PERIOD/2.0);
        clk = 1'b1;
        #(CLK_PERIOD/2.0);
    end

    // Reset DUT Task
    task reset_dut;
    begin
        n_rst = 1'b0;
        @(posedge clk);
        @(posedge clk);
        @(negedge clk);
        n_rst = 1'b1;
        @(negedge clk);
        @(negedge clk);
    end
    endtask

    // Task to check DUT output values
    task check_outputs (
        input logic [3:0] expected_count_out,
        input logic expected_rollover_flag
    );
        integer count_correct;
        integer flag_correct;
    begin

        // NOTE: Make sure you check away from the rising edge!!!
        count_correct = 0;
        flag_correct = 0;
        tb_check_count = tb_check_count + 1;

        // Check count_out
        if(expected_count_out == count_out) begin // Check passed
            count_correct = 1;
        end
        else begin // Check failed
            $display("Incorrect count_out during check #%1d. Expected: %1d, Actual: %1d", tb_check_count,
                    expected_count_out, count_out);
        end

        // Check flag
        if(expected_rollover_flag == rollover_flag) begin // Check passed
            flag_correct = 1;
        end
        else begin // Check failed
            $display("Incorrect rollover_flag during check #%1d. Expected: %1d, Actual: %1d", tb_check_count,
                    expected_rollover_flag, rollover_flag);
        end

        // Conditional increment of tb_passed
        if (count_correct == 1 && flag_correct == 1) tb_passed += 1;
    end
    endtask
    
    // Test bench main process
    initial begin
        // Initialize inputs
        n_rst  = 1'b1;
        clear = 1'b0;
        count_enable = 1'b0;
        rollover_val = 4'd3;  // Non-zero value

        // Initialize testbench signals
        tb_check_count = 0;
        tb_passed = 0;

        // Wait some time before starting first test case
        #(1);
        
        // ************************************************************************
        // Test Case #1: Power-on Reset of the DUT
        // ************************************************************************
        reset_dut();
        check_outputs(0, 0);
        

        // ************************************************************************
        // Test Case #2: Continuous counting and reaching rollover
        // ************************************************************************    
        count_enable = 1'b1;
        rollover_val = 4'd13;

        // Wait until count is 13 (rollover_flag should be high)
        repeat (13) @(negedge clk);
        check_outputs(13, 1);

        // Check it rolls over back to 1
        @(negedge clk);
        check_outputs(1, 0);
        

        // ************************************************************************
        // Test Case #3: Toggling clear and count_enable
        // ************************************************************************
        // Diable and reset
        count_enable = 1'b0;
        reset_dut();

        // Assign stimulus
        count_enable = 1'b1;
        rollover_val = 4'd9;

        // Count to 7
        repeat (7) @(negedge clk);
        check_outputs(7, 0);

        // Assert clear
        clear = 1'b1;
        @(negedge clk);
        check_outputs(0, 0);
        
        // Deassert clear
        clear = 1'b0;
        
        // Wait until rollover (9 clock cycles)
        repeat (9) @(negedge clk);
        check_outputs(9, 1);
        
        // Deactivate enable
        count_enable = 1'b0;

        // Wait some clock cycles and check
        repeat (5) @(negedge clk);

        // Check results
        check_outputs(9, 1);

        // Activate enable
        count_enable = 1'b1;
        repeat (4) @(negedge clk);
        check_outputs(4, 0);

        // Finish simulation
        $display("\nTest cases passed: %1d/%1d\n", tb_passed, tb_check_count);
        $finish;

    end

endmodule
