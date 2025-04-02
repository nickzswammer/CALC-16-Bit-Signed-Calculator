module KeyPadScanner (
    input logic Reset,
    input logic Clock,
    input logic [3:0] RowIn,
    output logic [3:0] ColOut,
    output logic LFSRReset,
    input logic LFSRFlg,
    output logic [3:0] RowColVector,
    output logic KeyRdy,
    input logic KeyRd
);

// State machine enumeration
typedef enum logic [1:0] {
    SCAN = 2'b00,
    CALCULATE = 2'b01,
    ANALYZE = 2'b10,
    WAIT_FOR_READ = 2'b11
} state_t;

state_t State;
logic [2:0] Counter;
logic [15:0] Data;
logic [3:0] Col;
logic [3:0] Sum;
logic ZeroChecker;
logic waitbit;

// Tri-state column outputs
assign ColOut[0] = Col[0] ? 1'bz : 1'b0;
assign ColOut[1] = Col[1] ? 1'bz : 1'b0;
assign ColOut[2] = Col[2] ? 1'bz : 1'b0;
assign ColOut[3] = Col[3] ? 1'bz : 1'b0;

always_ff @(posedge Clock or negedge Reset) begin
    if (!Reset) begin
        	State <= SCAN;
        Col <= 4'b0111;
        LFSRReset <= 0;
        KeyRdy <= 0;
        RowColVector <= 4'b1101;
        Counter <= 0;
        Data <= 16'hFFFF;
        Sum <= 0;
        ZeroChecker <= 0;
        waitbit <= 0;
    end
    else begin
        case (State)
            SCAN: begin
                if (LFSRFlg == 1) begin
                    case (Col)
                        4'b0111: begin
                            if (waitbit == 1) begin
                                Data[15:12] <= RowIn;
                                Col <= 4'b1011;
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
                Sum <= ~Data[0] + ~Data[1] + ~Data[2] + ~Data[3] +
                       ~Data[4] + ~Data[5] + ~Data[6] + ~Data[7] +
                       ~Data[8] + ~Data[9] + ~Data[10] + ~Data[11] +
                       ~Data[12] + ~Data[13] + ~Data[14] + ~Data[15];
                State <= ANALYZE;
            end
            ANALYZE: begin
                if (ZeroChecker == 1'b1) begin
                    if (Sum == 4'b0001) begin
                        Counter <= Counter + 1'b1;
                        if (Counter == 3'b100) begin
                            case (Data)
                                16'hFFFE: RowColVector <= 4'b0000;
                                16'hFFFD: RowColVector <= 4'b0100;
                                16'hFFFB: RowColVector <= 4'b1000;
                                16'hFFF7: RowColVector <= 4'b1100;
                                16'hFFEF: RowColVector <= 4'b0001;
                                16'hFFDF: RowColVector <= 4'b0101;
                                16'hFFBF: RowColVector <= 4'b1001;
                                16'hFF7F: RowColVector <= 4'b1101;
                                16'hFEFF: RowColVector <= 4'b0010;
                                16'hFDFF: RowColVector <= 4'b0110;
                                16'hFBFF: RowColVector <= 4'b1010;
                                16'hF7FF: RowColVector <= 4'b1110;
                                16'hEFFF: RowColVector <= 4'b0011;
                                16'hDFFF: RowColVector <= 4'b0111;
                                16'hBFFF: RowColVector <= 4'b1011;
                                16'h7FFF: RowColVector <= 4'b1111;
                                default:  RowColVector <= 4'b0000;
                            endcase
                            KeyRdy <= 1;
                            State <= WAIT_FOR_READ;
                            Counter <= 0;
                            ZeroChecker <= 0;
                        end
                    end
                    else if (Sum == 4'b0000) begin
                        Counter <= 0;
                        State <= SCAN;
                    end
                    else begin
                        ZeroChecker <= 1'b0;
                        Counter <= 0;
                        State <= SCAN;
                    end
                end
                else if (Sum == 4'b0000) begin
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


module(
	
);
