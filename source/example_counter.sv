// $Id: $
// File name:   example_counter.sv
// Created:     2/20/2025
// Author:      Miguel Isrrael Teran
// Description: Example Counter

`timescale 1ns / 10ps

module example_counter # (
    parameter SIZE = 4
)(
    input logic clk, n_rst,
    input logic count_enable, clear,
    input logic [SIZE-1:0] rollover_val,
    output logic [SIZE-1:0] count_out,
    output logic rollover_flag
);
    // Internal signals
    logic [SIZE-1:0] next_count;  // next count
    logic next_flag;  // next flag

    // Count and Flag Registers
    always_ff @(posedge clk, negedge n_rst) begin
        if (~n_rst) begin
            count_out <= '0;
            rollover_flag <= 1'b0;
        end else begin
            count_out <= next_count;
            rollover_flag <= next_flag;
        end
    end

    // Next Count & Next Flag Logic
    always_comb begin
        // Next count logic
        next_count = count_out;
        if (clear)
            next_count = '0;
        else if (count_enable) begin
            if (count_out >= rollover_val)
                next_count = 1;  // counter rolls over back to 1
            else
                next_count = count_out + 1; 
        end

        // Next flag logic
        if (next_count == rollover_val)
            next_flag = 1;
        else
            next_flag = 0;
    end

endmodule
