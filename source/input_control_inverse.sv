module input__control_inverse (
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

    typedef enum logic [2:0] {
        IDLE, SCAN_COL, WAIT_STABLE, CONFIRM, WAIT_RELEASE
    } state_t;

    state_t state, next_state;

    logic [1:0] col_index;
    logic [3:0] debounce_cnt;
    logic [3:0] key_code;
    logic key_valid;

    int idx;
	
    // Sequential logic with active-low reset
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            state <= IDLE;
            col_index <= 0;
            debounce_cnt <= 0;
            read_input <= 0;
        end else begin
            state <= next_state;
		
	    if (state == SCAN_COL && next_state == SCAN_COL)
	        col_index <= (col_index == 3) ? 0 : col_index + 1;

            if (state == WAIT_STABLE) begin
                if (key_valid)
                    debounce_cnt <= debounce_cnt + 1;
                else
                    debounce_cnt <= 0;
            end

            if (state == CONFIRM && !read_input) begin
                read_input <= 1;
                key_code <= encode_key(RowIn, col_index);
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
            WAIT_STABLE: next_state = (debounce_cnt >= 4'd10) ? CONFIRM : WAIT_STABLE;
            CONFIRM:     next_state = key_read ? WAIT_RELEASE : CONFIRM;
            WAIT_RELEASE:next_state = !key_valid ? IDLE : WAIT_RELEASE;
	    default: next_state = IDLE;
        endcase
    end

    // Output the scanning column (drive low one at a time)
    always_comb begin
        ColOut = 4'b0000;
	ColOut[col_index] = 1'b1;
    end

    // Detect active-low key press
    always_comb begin
        key_valid = 0;
        for (int i = 0; i < 4; i++)
	    if (RowIn[i] == 1'b1)
                key_valid = 1;
    	    
    end

    // Translate row and column index to keypad index 0–15
	function logic [3:0] encode_key(input logic [3:0] row, input logic [1:0] col);
	    for (int r = 0; r < 4; r++) begin
		    if (row[r] == 1'b1) begin
			idx = r * 4 + {30'd0, col};
	            return idx[3:0];  // ✅ legal slice on named variable
	        end
	    end
	    return 4'hE;  // fallback if no row matched
	endfunction

    // Decode key_code into outputs
    always_comb begin
        keypad_input = 4'h0;
        operator_input = 3'b000;
        equal_input = 0;

        case (key_code)
            4'h0: keypad_input = 4'd1;
            4'h1: keypad_input = 4'd2;
            4'h2: keypad_input = 4'd3;
            4'h3: operator_input = 3'b010; // A → add
            4'h4: keypad_input = 4'd4;
            4'h5: keypad_input = 4'd5;
            4'h6: keypad_input = 4'd6;
            4'h7: operator_input = 3'b011; // B → sub
            4'h8: keypad_input = 4'd7;
            4'h9: keypad_input = 4'd8;
            4'hA: keypad_input = 4'd9;
            4'hB: operator_input = 3'b100; // C → mul
            4'hC: equal_input = 1;         // * → equal
            4'hD: keypad_input = 4'd0;
            4'hE: ; // '#' → ignore or custom
            4'hF: operator_input = 3'b001; // D → neg
            default: ;
        endcase
    end

endmodule
