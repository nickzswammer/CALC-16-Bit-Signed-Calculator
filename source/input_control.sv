module input_control (
    input  logic clk,
    input  logic nRST,               // active-low reset
	
    input  logic [3:0] RowIn,        // keypad rows (pulled up)
    output logic [3:0] ColOut,       // keypad columns (drive low to scan)
	
    output logic read_input,            // signal to general controller
    input  logic key_read,             // signal from general controller

    output logic [3:0] keypad_input,     // 0–9 digits only
    output logic [2:0] operator_input,   // 3-bit operator code
	output logic key_pressed,
	output logic [2:0] input_state_FPGA,
    output logic equal_input             // 1-bit equal flag (*)
);

    //localparam DEBOUNCE_SIZE = 500_000; // Debounce Length (for 50 MHz clock this is 10ms)
    //localparam SCAN_DURATION = 50_000;  // scan length (50mHz clock this is 1 ms)
	localparam DEBOUNCE_SIZE = 500_000; // Debounce Length (for 50 MHz clock this is 10ms)
    localparam SCAN_DURATION = 50_000;  // scan length (50mHz clock this is 1 ms)
	
    typedef enum logic [2:0] {
      IDLE,         // 0                  // IDLE, but just pre state for SCAN_COL
		SCAN_COL,     // 1                 // drives columns low 1 by 1 every 10ms, transitions when detects key_pressed high
		WAIT_STABLE,  // 2                 // debounce state, waits until input is stable before processing in the confirm state
		CONFIRM,      // 3                 // encodes key, sets the output variables to respective outputs, waits until gencon confirms key_read
		WAIT_RELEASE, // 4                  // waits for button to be released IE when RowIn = 4'b1111
		WAIT_RELEASE_STABLE
    } state_t;

    state_t input_control_state, next_state;

	logic [1:0] col_index;           // current column being scanned, gets incremented every 1 ms (50,000 clock cycles)
	logic [18:0] debounce_cnt;       // how many clock cycles have elapsed, only reads when key_pressed asserted for 500,000 clock cycles
	// logic key_pressed;               // key pressed, turns high when there is a 0 detected in RowIn (always_comb)

    // to handle read_input states
	logic [3:0] decoded_key;         // (0-15) key_code to be decoded by the encoder always_comb case statement, represents positions on keypad
	logic [3:0] next_keypad_input;   // Set within combinational decoder block 
	logic [2:0] next_operator_input; // Set within combinational decoder block 
    logic next_equal_input;          // Set within combinational decoder block 

	logic read_input_flag;

	logic [19:0] scan_timer = 0;     // Scan Timer, goes up to 50,000

	logic [3:0] RowMid, RowSync;

    // synchronizer
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
	
	
    // Sequential logic with active-low reset
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            input_control_state <= IDLE;
            col_index <= 0;
            debounce_cnt <= 0;
            read_input <= 0;
            read_input_flag <= 0;
	    	decoded_key <= 4'd14;
			input_state_FPGA <= 0;

		// state logic
        end else begin
            input_control_state <= next_state;
			input_state_FPGA <= input_control_state;
	    	operator_input <= next_operator_input;
		

			// Scan Columns
			if (input_control_state == SCAN_COL && next_state == SCAN_COL) begin
				if(scan_timer == SCAN_DURATION) begin
					scan_timer <= 0;
					col_index <= (col_index == 3) ? 0 : col_index + 1;
				end
				else
					scan_timer <= scan_timer + 1;
			end

			// Debounce
			if (input_control_state == WAIT_STABLE) begin
				if (key_pressed && debounce_cnt < DEBOUNCE_SIZE)
						debounce_cnt <= debounce_cnt + 1;
				else if (debounce_cnt >= DEBOUNCE_SIZE)
						debounce_cnt <= 0;
			end

			// Encode key and send to Gencon
			if (input_control_state == CONFIRM) begin

				decoded_key <= encode_key(RowSync, col_index);
				
				// Decode in-place
				keypad_input <= next_keypad_input;
				//operator_input <= next_operator_input;
				equal_input <= next_equal_input;
		
				// Only raise read_input if it’s a digit and if flag is 1
				if ((decoded_key == 0 || decoded_key == 1 || decoded_key == 2 || decoded_key == 4 || decoded_key == 5 || decoded_key == 6 || 
				decoded_key == 8 || decoded_key == 9 || decoded_key == 10 || decoded_key == 13) && (next_operator_input == '0) && (next_equal_input == '0) && (!read_input_flag)) begin
					read_input <= 1;
					read_input_flag <= 1;
				end
				else
					read_input <= 0;
			end

			// Wait for key release
			if (input_control_state == WAIT_RELEASE && !key_pressed) begin
				keypad_input <= 0;
			end

			// debounce release	
			if (input_control_state == WAIT_RELEASE_STABLE) begin
				if (!key_pressed && debounce_cnt < DEBOUNCE_SIZE)
					debounce_cnt <= debounce_cnt + 1;
				else if (debounce_cnt >= DEBOUNCE_SIZE) begin
					debounce_cnt <= 0;
					keypad_input <= 0;
					operator_input <= 0;
					equal_input <= 0;
					decoded_key <= 4'hE;  // invalid / null key to suppress re-decoding
					read_input_flag <= 0;
				end
			end
        end
    end

    // Combinational next state logic
    always_comb begin
        next_state = input_control_state; //         IDLE, SCAN_COL, WAIT_STABLE, CONFIRM, WAIT_RELEASE

        case (input_control_state)
            IDLE:        next_state = SCAN_COL;
            SCAN_COL:    next_state = key_pressed ? WAIT_STABLE : SCAN_COL;
			WAIT_STABLE: next_state = (debounce_cnt >= DEBOUNCE_SIZE) ? CONFIRM : WAIT_STABLE;
            CONFIRM:     next_state = key_read ? WAIT_RELEASE : CONFIRM;
            WAIT_RELEASE:next_state = !key_pressed ? WAIT_RELEASE_STABLE : WAIT_RELEASE;
			WAIT_RELEASE_STABLE: next_state = (debounce_cnt >= DEBOUNCE_SIZE) ? IDLE : WAIT_RELEASE_STABLE;
	    	
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
        key_pressed = 0;
        for (int i = 0; i < 4; i++)
		if (RowSync[i] == 0)
            key_pressed = 1;
    end

	// Translate row and column index to keypad index 0–15
	function logic [3:0] encode_key(input logic [3:0] row, input logic [1:0] col);
		logic [3:0] idx;
		for (int r = 0; r < 4; r++) begin
			if (row[r] == 0) begin
				idx = (4'(r) << 2) | 4'(col); // explicitly cast to 4 bits
				return idx;
			end
		end
		return 4'hE;  // fallback if no row matched, return empty key (14)
	endfunction


    // Decode key_code into outputs
    always_comb begin
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
			4'hE: ;                             // pound symbol, nothing
			4'hF: next_operator_input = 3'b001; // minus symbol
			
			default: ;
		endcase
    end
endmodule
