module read (
    input logic Reset,        
    input logic Clock,          
    input logic [3:0] RowIn,    // input from keypad rows - input all 1?
    output logic [3:0] ColOut,  // output to keypad columns 
    output logic LFSRReset,     // Reset (Linear Feedback Shift Register)
    input logic LFSRFlg,        // Flag from LFSR for readiness - input 0
    output logic [3:0] RowColVector, // 4-bit output 
    output logic KeyRdy,        // ready to be read
    input logic KeyRd           // data read - input 0
);

// This module scans a 4x4 matrix keypad by driving columns and reading rows.
// When a key is pressed, it sets KeyRdy high, outputs the key's position on RowColVector,
// and waits for KeyRd to resume scanning.

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
	KeyRdy <=0;
        RowColVector <= 4'b1101;    
        Counter <= 0;               // Reset counter
        Data <= 16'hFFFF;           
        Sum <= 0;                   
        ZeroChecker <= 0;           
        waitbit <= 0;               
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
                // num 0s in data
		 Sum <= !(Data[0] ^ Data[1] ^ Data[2] ^ Data[3] ^
      	 	Data[4] ^ Data[5] ^ Data[6] ^ Data[7] ^
     		  Data[8] ^ Data[9] ^ Data[10] ^ Data[11] ^
      		 Data[12] ^ Data[13] ^ Data[14] ^ Data[15]);
		
                State <= ANALYZE;                   
            end
            ANALYZE: begin
                if (ZeroChecker == 1'b1) begin //if the previous check had no key pressed
                    
                    if (Sum) begin // if only one key was pressed 
                        
                        Counter <= Counter + 1'b1;  // debouncing
                        if (Counter == 3'b100) begin
                            
                            case (Data)
                                16'hFFFE: RowColVector <= 4'b0000; // 1
                                16'hFFFD: RowColVector <= 4'b0100; // 4
                                16'hFFFB: RowColVector <= 4'b1000; // 7
                                16'hFFF7: RowColVector <= 4'b1100; // *
                                16'hFFEF: RowColVector <= 4'b0001; // 2
                                16'hFFDF: RowColVector <= 4'b0101; // 5
                                16'hFFBF: RowColVector <= 4'b1001; // 8
                                16'hFF7F: RowColVector <= 4'b1101; // 0
                                16'hFEFF: RowColVector <= 4'b0010; // 3
                                16'hFDFF: RowColVector <= 4'b0110; // 6
                                16'hFBFF: RowColVector <= 4'b1010; // 9
                                16'hF7FF: RowColVector <= 4'b1110; // #
                                16'hEFFF: RowColVector <= 4'b0011; // A
                                16'hDFFF: RowColVector <= 4'b0111; //B
                                16'hBFFF: RowColVector <= 4'b1011; // C
                                16'h7FFF: RowColVector <= 4'b1111; // D
                                default: RowColVector <= 4'b1101; // Default to 0
                            endcase
                            KeyRdy <= 1;                
                            State <= WAIT_FOR_READ;     
                            Counter <= 0;               
                            ZeroChecker <= 0;           
                        end
                    end
                    
                    else begin // multiple keys pressed  so restart the state machinee                       
                        ZeroChecker <= 1'b0;
                        Counter <= 0;
                        State <= SCAN;
                    end
                end
                else if (!Sum) begin // no button press
                    
                    ZeroChecker <= 1'b1;           
                    State <= SCAN;
                end
                else State <= SCAN;                 
            end
            WAIT_FOR_READ: begin
                if (KeyRd == 1) begin
                    
                    KeyRdy <= 0;                    
                    LFSRReset <= 0;                 
                    State <= SCAN;                  
                end
            end
            default: begin
                // Default state
                State <= SCAN;
                Col <= 4'b1110;
                LFSRReset <= 0;
                KeyRdy <= 1;
                RowColVector <= 4'b1111;
                Counter <= 0;
                Data <= 16'hFFFF;
                Sum <= 0;
            end
        endcase
    end
end

endmodule
