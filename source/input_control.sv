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

		if (state == CONFIRM) begin
    logic [3:0] temp_key;
    temp_key = encode_key(RowIn, col_index);
    key_code <= temp_key; // 🔁 always latch the key

    // ✅ Only raise read_input if it's a digit
    if (!read_input) begin
        case (temp_key)
            4'h0, 4'h1, 4'h2, 4'h4, 4'h5, 4'h6, 4'h8, 4'h9, 4'hA, 4'hD:
                read_input <= 1;
            default:
                read_input <= 0; // or just leave unchanged
        endcase
    end
end
		/*
	    if (state == CONFIRM && !read_input) begin
    		key_code <= encode_key(RowIn, col_index);
		read_input <= 1;
    	    end
	 */

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


/*module input_control (
    input logic Reset,        
    input logic Clock,          
    input logic [3:0] RowIn,    // input from keypad rows - input all 1?
    output logic [3:0] ColOut,  // output to keypad columns 
    output logic LFSRReset,     // Reset (Linear Feedback Shift Register)
    input logic LFSRFlg,        // Flag from LFSR for readiness - input 0
    output logic read_input,        // ready to be read
    input logic key_read,           // data read - input 0
    output logic [3:0] Number,  //number to be output
    output logic [2:0] Operator, //operator output
    output logic EqualSign // equal sign 
);

// State machine
typedef enum logic [1:0] {
    SCAN = 2'b00,           //Scanning columns for key presses
    CALCULATE = 2'b01,      //  Calculating the number of pressed keys
    ANALYZE = 2'b10,        //Analyzing the key press data
    WAIT_FOR_READ = 2'b11   //Waiting for key data to be read
} state_t;

state_t State;              
logic [2:0] Counter;        // Counter for debouncing or timing purposes
logic [15:0] Data;          // row data from all columns
logic [3:0] Col;            //control active column
logic Sum;            //inverted Data bits to detect key presses
logic ZeroChecker;          //no-key-pressed condition
logic waitbit;              // timing for column scans

// creates a 'debouncing function'
assign ColOut[0] = Col[0] ? 1'bz : 1'b0; 
assign ColOut[1] = Col[1] ? 1'bz : 1'b0; 
assign ColOut[2] = Col[2] ? 1'bz : 1'b0; 
assign ColOut[3] = Col[3] ? 1'bz : 1'b0;

always_ff @(posedge Clock or negedge Reset) begin
    if (!Reset) begin
      
        State <= SCAN;             
        Col <= 4'b0111;             // Activate first column 
        LFSRReset <= 0;             
	read_input <=0;
        Number <= 4'b0000;    
        Counter <= 0;               // Reset counter
	EqualSign <= 0;
        Data <= 16'hFFFF;           
        Sum <= 0;                   
        ZeroChecker <= 0;           
        waitbit <= 0;
	Operator <= 0;               
    end
    else begin
        // State machine 
        case (State)
            SCAN: begin
                if (LFSRFlg == 1) begin
                   
                    case (Col)
                        4'b0111: begin 
                            if (waitbit == 1) begin
				    Data[15:12] <= RowIn;   // row data
                                Col <= 4'b1011;         // Move to next column
                                waitbit <= 0;           
                            end
                            else waitbit <= 1;          
                        end
                        4'b1011: begin  
                            if (waitbit == 1) begin
				    Data[11:8] <= RowIn;    
				Col <= 4'b1101;	
                                waitbit <= 0;
                            end
                            else waitbit <= 1;
                        end
                        4'b1101: begin  
                            if (waitbit == 1) begin
				    Data[7:4] <= RowIn;     
                                Col <= 4'b1110;         
                                waitbit <= 0;
                            end
                            else waitbit <= 1;
                        end
                        4'b1110: begin  
                            if (waitbit == 1) begin
				    Data[3:0] <= RowIn;     
                                Col <= 4'b0111;         
                                State <= CALCULATE;     
                                waitbit <= 0;
                            end
                            else waitbit <= 1;
                        end
                        default: begin
                            Col <= 4'b1110;         
                            Counter <= 0;           
                        end
                    endcase
                    LFSRReset <= 0;                 
                end
                else begin
                    LFSRReset <= 1;                 
                end
            end
			
	CALCULATE: begin
		Sum <= (!Data[0] ^ !Data[1] ^ !Data[2] ^ !Data[3] ^
			!Data[4] ^ !Data[5] ^ !Data[6] ^ !Data[7] ^
			!Data[8] ^ !Data[9] ^ !Data[10] ^ !Data[11] ^
			!Data[12] ^ !Data[13] ^ !Data[14] ^ !Data[15]);	

		Counter <= 0;
		
		State <= ANALYZE;
	end


            ANALYZE: begin
                    
                    if (Sum) begin // if only one key was pressed  
                        Counter <= Counter + 1'b1;  // debouncing
                        if (Counter == 3'b100) begin
				$display("After 4 Clock Cycles");
                            
                            case (Data)
                                16'hFFFE: Number <= 4'b0001; // 1
                                16'hFFFD: Number <= 4'b0100; // 4
                                16'hFFFB: Number <= 4'b1000; // 7
                                16'hFFF7: Operator <= 3'b100; // *(multiplication)
                                16'hFFEF: Number <= 4'b0010; // 2
                                16'hFFDF: Number <= 4'b0101; // 5
                                16'hFFBF: Number <= 4'b1000; // 8
                                16'hFF7F: Number <= 4'b0000; // 0
                                16'hFEFF: Number <= 4'b0011; // 3
                                16'hFDFF: Number <= 4'b0110; // 6
                                16'hFBFF: Number <= 4'b1001; // 9
                                16'hF7FF: Operator <= 3'b001; // # (change sign
                                16'hEFFF: Operator <= 3'b010; // A (Addition
                                16'hDFFF: Operator <= 3'b011; //B (subraction
                                16'hBFFF: EqualSign <= 1'b1; // C (equals)
                                16'h7FFF: Operator <= 3'b110; // D (NAN or operator)
                                default: Number <= 4'b0000; // Default to 0
                            endcase
                            read_input <= 1;                
                            State <= WAIT_FOR_READ;     
                            Counter <= 0;               
                            ZeroChecker <= 0;
                        end
			

                end
                else if (!Sum) begin // no button press
                    
                    ZeroChecker <= 1'b1;           
                    State <= SCAN;
                end
                else State <= SCAN;                 
            end
            WAIT_FOR_READ: begin
                if (key_read == 1) begin
                    
                    read_input <= 0;                    
                    LFSRReset <= 0;                 
                    State <= SCAN;                  
                end
            end
            default: begin
                // Default state
                State <= SCAN;
                Col <= 4'b1110;
                LFSRReset <= 0;
                read_input <= 1;
                Number <= 4'b0000;
                Data <= 16'hFFFF;
                Sum <= 0;
            end
        endcase
    end
end

endmodule
*/
