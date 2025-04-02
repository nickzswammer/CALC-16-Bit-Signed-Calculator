module KeyPadScanner (
    input logic Reset,        
    input logic Clock,          
    input logic [3:0] RowIn,    // 4-bit input from keypad rows
    output logic [3:0] ColOut,  // 4-bit output to keypad columns 
    output logic LFSRReset,     // Reset signal for an external (Linear Feedback Shift Register)
    input logic LFSRFlg,        // Flag from LFSR for readiness
    output logic [3:0] RowColVector, // 4-bit output representing the pressed key's row-column code
    output logic KeyRdy,        // Signal indicating a key press is detected and ready to be read
    input logic KeyRd           // Input signal to key data has been read
);

// This module scans a 4x4 matrix keypad by driving columns and reading rows.
// When a key is pressed, it sets KeyRdy high, outputs the key's position on RowColVector,
// and waits for KeyRd to resume scanning.

// State machine
typedef enum logic [1:0] {
    SCAN = 2'b00,           // State: Scanning columns for key presses
    CALCULATE = 2'b01,      // State: Calculating the number of pressed keys
    ANALYZE = 2'b10,        // State: Analyzing the key press data
    WAIT_FOR_READ = 2'b11   // State: Waiting for key data to be read
} state_t;

// Internal signals
state_t State;              
logic [2:0] Counter;        // Counter for debouncing or timing purposes
logic [15:0] Data;          // 16-bit register to store row data from all columns
logic [3:0] Col;            // 4-bit register to control active column
logic [3:0] Sum;            // Sum of inverted Data bits to detect key presses
logic ZeroChecker;          // Flag to handle no-key-pressed condition
logic waitbit;              // Wait flag for timing column scans

// Tri-state column outputs: High-Z when Col bit is 1, 0 when Col bit is 0
assign ColOut[0] = Col[0] ? 1'bz : 1'b0; 
assign ColOut[1] = Col[1] ? 1'bz : 1'b0; 
assign ColOut[2] = Col[2] ? 1'bz : 1'b0; 
assign ColOut[3] = Col[3] ? 1'bz : 1'b0;

// Sequential logic block triggered on positive clock edge or negative reset edge
always_ff @(posedge Clock or negedge Reset) begin
    if (!Reset) begin
        // Reset condition: Initialize all signals to default values
        State <= SCAN;              // Start in SCAN state
        Col <= 4'b0111;             // Activate first column (Col0 low, others high-Z)
        LFSRReset <= 0;             // Deassert LFSR reset
        KeyRdy <= 0;                // No key ready
        RowColVector <= 4'b1101;    // Default key code (arbitrary initial value)
        Counter <= 0;               // Reset counter
        Data <= 16'hFFFF;           // Initialize Data to all 1s (no key pressed)
        Sum <= 0;                   // Reset sum
        ZeroChecker <= 0;           // Reset zero checker flag
        waitbit <= 0;               // Reset wait flag
    end
    else begin
        // State machine logic
        case (State)
            SCAN: begin
                if (LFSRFlg == 1) begin
                    // LFSR flag is high, proceed with column scanning
                    case (Col)
                        4'b0111: begin  // Column 0 active
                            if (waitbit == 1) begin
                                Data[15:12] <= RowIn;   // Store row data for Col0
                                Col <= 4'b1011;         // Move to next column (Col1)
                                waitbit <= 0;           // Clear wait flag
                            end
                            else waitbit <= 1;          // Set wait flag for next cycle
                        end
                        4'b1011: begin  // Column 1 active
                            if (waitbit == 1) begin
                                Data[11:8] <= RowIn;    // Store row data for Col1
                                Col <= 4'b1101;         // Move to next column (Col2)
                                waitbit <= 0;
                            end
                            else waitbit <= 1;
                        end
                        4'b1101: begin  // Column 2 active
                            if (waitbit == 1) begin
                                Data[7:4] <= RowIn;     // Store row data for Col2
                                Col <= 4'b1110;         // Move to next column (Col3)
                                waitbit <= 0;
                            end
                            else waitbit <= 1;
                        end
                        4'b1110: begin  // Column 3 active
                            if (waitbit == 1) begin
                                Data[3:0] <= RowIn;     // Store row data for Col3
                                Col <= 4'b0111;         // Return to first column
                                State <= CALCULATE;     // Move to calculate state
                                waitbit <= 0;
                            end
                            else waitbit <= 1;
                        end
                        default: begin
                            Col <= 4'b1110;         // Default to last column
                            Counter <= 0;           // Reset counter
                        end
                    endcase
                    LFSRReset <= 0;                 // Keep LFSR running
                end
                else begin
                    LFSRReset <= 1;                 // Reset LFSR if flag is low
                end
            end
            CALCULATE: begin
                // Calculate the number of 0s in Data (inverted bits indicate key presses)
                Sum <= ~Data[0] + ~Data[1] + ~Data[2] + ~Data[3] +
                       ~Data[4] + ~Data[5] + ~Data[6] + ~Data[7] +
                       ~Data[8] + ~Data[9] + ~Data[10] + ~Data[11] +
                       ~Data[12] + ~Data[13] + ~Data[14] + ~Data[15];
                State <= ANALYZE;                   // Move to analyze state
            end
            ANALYZE: begin
                if (ZeroChecker == 1'b1) begin
                    // Previous scan had no keys pressed
                    if (Sum == 4'b0001) begin
                        // Exactly one key pressed
                        Counter <= Counter + 1'b1;  // Increment counter for debouncing
                        if (Counter == 3'b100) begin
                            // After 4 cycles (debounce), map Data to key code
                            case (Data)
                                16'hFFFE: RowColVector <= 4'b0000; // Key 0
                                16'hFFFD: RowColVector <= 4'b0100; // Key 1
                                16'hFFFB: RowColVector <= 4'b1000; // Key 2
                                16'hFFF7: RowColVector <= 4'b1100; // Key 3
                                16'hFFEF: RowColVector <= 4'b0001; // Key 4
                                16'hFFDF: RowColVector <= 4'b0101; // Key 5
                                16'hFFBF: RowColVector <= 4'b1001; // Key 6
                                16'hFF7F: RowColVector <= 4'b1101; // Key 7
                                16'hFEFF: RowColVector <= 4'b0010; // Key 8
                                16'hFDFF: RowColVector <= 4'b0110; // Key 9
                                16'hFBFF: RowColVector <= 4'b1010; // Key A
                                16'hF7FF: RowColVector <= 4'b1110; // Key B
                                16'hEFFF: RowColVector <= 4'b0011; // Key C
                                16'hDFFF: RowColVector <= 4'b0111; // Key D
                                16'hBFFF: RowColVector <= 4'b1011; // Key E
                                16'h7FFF: RowColVector <= 4'b1111; // Key F
                                default:  RowColVector <= 4'b0000; // Default to 0
                            endcase
                            KeyRdy <= 1;                // Signal key is ready
                            State <= WAIT_FOR_READ;     // Wait for read acknowledgment
                            Counter <= 0;               // Reset counter
                            ZeroChecker <= 0;           // Clear zero checker
                        end
                    end
                    else if (Sum == 4'b0000) begin
                        // No keys pressed
                        Counter <= 0;
                        State <= SCAN;                  // Return to scanning
                    end
                    else begin
                        // Multiple keys pressed (invalid)
                        ZeroChecker <= 1'b0;
                        Counter <= 0;
                        State <= SCAN;
                    end
                end
                else if (Sum == 4'b0000) begin
                    // No keys pressed in this scan
                    ZeroChecker <= 1'b1;            // Set flag for next scan
                    State <= SCAN;
                end
                else State <= SCAN;                 // Any other case, keep scanning
            end
            WAIT_FOR_READ: begin
                if (KeyRd == 1) begin
                    // Key data has been read
                    KeyRdy <= 0;                    // Clear key ready signal
                    LFSRReset <= 0;                 // Ensure LFSR is running
                    State <= SCAN;                  // Resume scanning
                end
            end
            default: begin
                // Default state: Reset to known values
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
