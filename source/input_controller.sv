`timescale 1ns/1ps

module input_controller (
    input logic clk,           // system clock
    input logic nRST,          // active low reset
    input logic [3:0] row,     // input rows from keypad
    output logic [3:0] col,    // output columns to keypad

    output logic [3:0] keypad_input,  // number pressed (0-9)
    output logic read_input,          // asserted when a number is pressed
    output logic [2:0] operator_input, // 3-bit operator (addition, subtraction, etc.)
    output logic equal_input           // asserted when '=' key pressed (in this case '*')
);

    typedef enum logic [1:0] {
        IDLE,
        SCAN,
        DEBOUNCE,
        PROCESS
    } state_t;

    state_t current_state, next_state;

    logic [1:0] scan_col;           // which column is currently active
    logic [15:0] key_matrix;        // full key matrix
    logic [15:0] debounced_matrix;  // debounced version

    logic [15:0] key_pressed;       // detected keypress
    logic [15:0] prev_key_pressed;  // previous keypress (for debouncing)

    logic [19:0] debounce_counter;  // debounce timer (adjust width depending on your clock speed)
    logic debounce_done;

    // Column drive
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST)
            col <= 4'b1111;
        else
            col <= ~(4'b0001 << scan_col); // one-hot active low
    end

    // Row read and key matrix capture
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST)
            key_matrix <= 16'b0;
        else begin
            key_matrix[scan_col*4 +: 4] <= ~row; // active low row
        end
    end

    // State Machine
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST)
            current_state <= IDLE;
        else
            current_state <= next_state;
    end

    always_comb begin
        next_state = current_state;
        case (current_state)
            IDLE: begin
                next_state = SCAN;
            end
            SCAN: begin
                if (|key_matrix)
                    next_state = DEBOUNCE;
            end
            DEBOUNCE: begin
                if (debounce_done)
                    next_state = PROCESS;
            end
            PROCESS: begin
                next_state = SCAN;
            end
        endcase
    end

    // Debounce Timer
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            debounce_counter <= 0;
            debounce_done <= 0;
        end else if (current_state == DEBOUNCE) begin
            if (debounce_counter == 20'd999_999) begin // adjust this for debounce timing
                debounce_done <= 1;
            end else begin
                debounce_counter <= debounce_counter + 1;
                debounce_done <= 0;
            end
        end else begin
            debounce_counter <= 0;
            debounce_done <= 0;
        end
    end

    // Key decoding (map matrix to values)
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            keypad_input <= 4'd0;
            read_input <= 0;
            operator_input <= 3'd0;
            equal_input <= 0;
            key_pressed <= 16'b0;
            prev_key_pressed <= 16'b0;
        end else begin
            read_input <= 0;
            equal_input <= 0;
            if (current_state == PROCESS) begin
                key_pressed <= key_matrix & ~prev_key_pressed; // only new press

                // Map key
                casez (key_pressed)
                    16'b0000_0000_0000_0001: keypad_input <= 4'd1;
                    16'b0000_0000_0000_0010: keypad_input <= 4'd2;
                    16'b0000_0000_0000_0100: keypad_input <= 4'd3;
                    16'b0000_0000_0000_1000: operator_input <= 3'b010; // Addition (A)

                    16'b0000_0000_0001_0000: keypad_input <= 4'd4;
                    16'b0000_0000_0010_0000: keypad_input <= 4'd5;
                    16'b0000_0000_0100_0000: keypad_input <= 4'd6;
                    16'b0000_0000_1000_0000: operator_input <= 3'b011; // Subtraction (B)

                    16'b0000_0001_0000_0000: keypad_input <= 4'd7;
                    16'b0000_0010_0000_0000: keypad_input <= 4'd8;
                    16'b0000_0100_0000_0000: keypad_input <= 4'd9;
                    16'b0000_1000_0000_0000: operator_input <= 3'b100; // Multiplication (C)

                    16'b0001_0000_0000_0000: operator_input <= 3'b001; // Negative sign (D)
                    16'b0010_0000_0000_0000: keypad_input <= 4'd0;
                    16'b0100_0000_0000_0000: equal_input <= 1; // '*' as Equal

                    default: ; // no action
                endcase

                // Detect if it was number or operator
                if (|keypad_input)
                    read_input <= 1;
            end

            // Save current key state for debouncing
            if (current_state == PROCESS)
                prev_key_pressed <= key_matrix;
        end
    end

    // Column scan advance
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST)
            scan_col <= 0;
        else if (current_state == SCAN)
            scan_col <= scan_col + 1;
    end

endmodule
