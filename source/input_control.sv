`timescale 1ns / 1ns

module input_control (
    input  logic clk,
    input  logic nRST,               // active-low reset
	
    input  logic [3:0] RowIn,        // keypad rows (pulled up)
    output logic [3:0] ColOut,       // keypad columns (drive low to scan)
	
    output logic read_input,            // signal to general controller
    input  logic key_read,             // signal from general controller

    output logic [3:0] keypad_input,     // 0–9 digits only
    output logic [2:0] operator_input,   // 3-bit operator code
    output logic equal_input             // 1-bit equal flag (*)
);

	localparam DEBOUNCE_SIZE = 500000;
		
    typedef enum logic [2:0] {
        IDLE, SCAN_COL, WAIT_STABLE, CONFIRM, WAIT_RELEASE
    } state_t;

    state_t state, next_state;

    logic [1:0] col_index;
	/// logic [18:0] debounce_cnt; for final
	//logic [18:0] debounce_cnt;

    logic [18:0] debounce_cnt;
    logic [3:0] key_code;
    logic key_valid;

    // to handle read_input states
    logic [3:0] decoded_key;
    logic [3:0] next_keypad_input;
    logic [2:0] next_operator_input;
    logic next_equal_input;

    logic [19:0] scan_timer = 0;

    logic [3:0] temp_key;

    int idx;

	//logic [3:0] RowMid, RowSync;

    // synchronizer
	/*
	always_ff @(posedge clk or negedge nRST) begin
		if (!nRST) begin
			RowMid <= 4'b1111;
			RowSync <= 4'b1111;
		end
		else begin
			RowMid <= RowIn;
			RowSync <= RowMid;
		end
	end
	*/
    // Sequential logic with active-low reset
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            state <= IDLE;
            col_index <= 0;
            debounce_cnt <= 0;
            read_input <= 0;
	    decoded_key <= 4'd14;
        end else begin
            state <= next_state;
	    operator_input <= next_operator_input;
		
	    if (state == SCAN_COL && next_state == SCAN_COL) begin
		    if(scan_timer == 99_999) begin
			scan_timer <= 0;
	        	col_index <= (col_index == 3) ? 0 : col_index + 1;
		    end
		    else
			scan_timer <= scan_timer + 1;
	    end

            if (state == WAIT_STABLE) begin
		    if (key_valid && debounce_cnt < DEBOUNCE_SIZE)
                    debounce_cnt <= debounce_cnt + 1;
		    else if (debounce_cnt == DEBOUNCE_SIZE)
                    debounce_cnt <= 0;
            end

	    if (state == CONFIRM) begin
		key_code = encode_key(RowIn, col_index);
		decoded_key <= key_code;
	        // Decode in-place
	        keypad_input <= next_keypad_input;
	        //operator_input <= next_operator_input;
	        equal_input <= next_equal_input;
	
	        // Only raise read_input if it’s a digit
		if ((decoded_key == 0 || decoded_key == 1 || decoded_key == 2 || decoded_key == 4 || decoded_key == 5 || decoded_key == 6 || 
			  decoded_key == 8 || decoded_key == 9 || decoded_key == 10 || decoded_key == 13)) begin
	            read_input <= 1;
	        end
	    end

            if (state == WAIT_RELEASE && !key_valid)
                read_input <= 0;
        end
    end

    // Combinational next state logic
    always_comb begin
        next_state = state; //         IDLE, SCAN_COL, WAIT_STABLE, CONFIRM, WAIT_RELEASE

        case (state)
            IDLE:        next_state = SCAN_COL;
            SCAN_COL:    next_state = key_valid ? WAIT_STABLE : SCAN_COL;
		WAIT_STABLE: next_state = (debounce_cnt >= DEBOUNCE_SIZE) ? CONFIRM : WAIT_STABLE;
            CONFIRM:     next_state = key_read ? WAIT_RELEASE : CONFIRM;
            WAIT_RELEASE:next_state = !key_valid ? IDLE : WAIT_RELEASE;
	    default: next_state = IDLE;
        endcase
    end

    // Output the scanning column (drive low one at a time)
    always_comb begin
        ColOut = 4'b1111;
        ColOut[col_index] = 1'b0;
    end

    // Detect active-low key press
    always_comb begin
        key_valid = 0;
        for (int i = 0; i < 4; i++)
		if (RowIn[i] == 0)
                	key_valid = 1;
    end

    // Translate row and column index to keypad index 0–15
    function logic [3:0] encode_key(input logic [3:0] row, input logic [1:0] col);
        for (int r = 0; r < 4; r++) begin
	    if (row[r] == 0) begin
		idx = r * 4 + {30'd0, col};
	        return idx[3:0];
	    end
        end
        return 4'hE;  // fallback if no row matched, return the empty key (14)
    endfunction

    // Decode key_code into outputs
    always_comb begin

	    /*
	key_code = 4'hE; // default to avoid latch
	    
	if (state == CONFIRM) begin
	    key_code = encode_key(RowIn, col_index);
	end
	    */

	next_keypad_input = 4'd0;
	next_operator_input = 3'b000;
	next_equal_input = 0;
	
	case (decoded_key)
	    4'h0: next_keypad_input = 4'd1;
	    4'h1: next_keypad_input = 4'd2;
	    4'h2: next_keypad_input = 4'd3;
	    4'h3: next_operator_input = 3'b010; // addition
	    4'h4: next_keypad_input = 4'd4;
	    4'h5: next_keypad_input = 4'd5;
	    4'h6: next_keypad_input = 4'd6;
	    4'h7: next_operator_input = 3'b011; // subtraction
	    4'h8: next_keypad_input = 4'd7;
	    4'h9: next_keypad_input = 4'd8;
	    4'hA: next_keypad_input = 4'd9;
	    4'hB: next_operator_input = 3'b100; // multiplication
	    4'hC: next_equal_input = 1;         // equals
	    4'hD: next_keypad_input = 4'd0;
	    4'hF: next_operator_input = 3'b001; // minus symbol
     	    default: ;
        endcase
    end
endmodule
