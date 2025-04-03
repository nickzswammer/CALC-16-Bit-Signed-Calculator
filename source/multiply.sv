module multiply
(
	input wire clk,
	input wire nRST,
	input logic [15 : 0] INn1,
	input logic [15 : 0] INn2,
	input wire start,

	output logic [15 : 0] out,
	output logic finish 
);

    typedef enum logic [3:0]
    {
    IDLE,
    SET,
    CHECKADD,
    ADD,
    FIN
    } state_t;

    state_t state, next;

    logic [14 : 0] n1;
    logic [14 : 0] n2;

    logic diffSign;	

    //main adder
    wire [14 : 0] adderOut;
    logic [14 : 0] adderSave;
    logic [14 : 0] adderIn;
    
    //counter
    wire [14 : 0] countOut;
    logic [14 : 0] countSave;
    logic [14 : 0] countIn;

    //complement counter
    wire stopCount;

    always_ff @(posedge clk, negedge nRST) begin
        if(!nRST) begin
            state <= IDLE;
        end else begin
            state <= next;
        end
    end

    always_comb begin : NEXT_STATE_LOGIC
        next = state;
        casez(state)

        IDLE: if(start) begin
            next = SET;
        end
        
        SET: begin
			if(INn2[14 : 0] == 15'b0) begin
				next = FIN;
			end else begin
            	next = CHECKADD;
			end
        end

        CHECKADD: if(stopCount) begin
            next = FIN;
        end else begin
            next = ADD;
        end
			

        ADD: begin
            next = CHECKADD;
        end
        
        FIN: if(!start) begin
            next = IDLE;
        end
		
		default:
			next = state;

        endcase
    end

    adder15 main(.sum(adderOut), .cOut(), .in1(n1), .in2(adderIn), .sub(1'b0));

    //counter
    adder15 count(.sum(countOut), .cOut(), .in1(countIn), .in2(15'b1), .sub(1'b0));
	
	//coutner for multiply
    adder15 compCount(.sum(), .cOut(stopCount), .in1(countOut), .in2(n2), .sub(1'b1)); 
        
    always_comb begin
        
	finish = 1'b0;

        casez(state)
            
            SET: begin
                	if(INn1[15] ^ INn2[15]) begin
                    	diffSign = 1;
                	end else begin
                    	diffSign = 0;
                	end

                	n2 [14 : 0] = INn2 [14 : 0];
                	n1 [14 : 0] = INn1 [14 : 0];

                	countSave = 15'b0;
                	countIn = 15'b0;

                	adderSave = 15'b0;
                	adderIn = 15'b0;
				end

            CHECKADD: begin
					//$display("cOut: %d, adderOut: %d", countOut, adderOut);
					
                	countSave = countOut; 
                	adderSave = adderOut;
				end

            ADD: begin
                	countIn = countSave;
                	adderIn = adderSave;
				end

            FIN: begin
               		out [14 : 0] =  adderSave [14 : 0];
                	out [15] = diffSign;
                	finish = 1'b1;
				end

			default:
				finish = 1'b0;

        endcase
    end

endmodule
