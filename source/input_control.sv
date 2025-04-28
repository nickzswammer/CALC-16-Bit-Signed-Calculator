module input_control (
    input logic Reset,        
    input logic Clock,          
    input logic [3:0] RowIn,    // input from keypad rows - input all 1?
    output logic [3:0] ColOut,  // output to keypad columns 
    output logic LFSRReset,     // Reset (Linear Feedback Shift Register)
    input logic LFSRFlg,        // Flag from LFSR for readiness - input 0
    output logic KeyRdy,        // ready to be read
    input logic KeyRd,           // data read - input 0
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
	KeyRdy <=0;
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
                Number <= 4'b0000;
                Counter <= 0;
                Data <= 16'hFFFF;
                Sum <= 0;
            end
        endcase
    end
end

endmodule
