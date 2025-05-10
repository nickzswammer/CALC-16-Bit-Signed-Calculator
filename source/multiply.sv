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
	 logic next_finish;
	 logic [15:0] next_out;

    logic [14 : 0] n1, next_n1;
    logic [14 : 0] n2, next_n2;

    logic diffSign, next_diffSign;	

    //main adder
    wire [14 : 0] adderOut;
    logic [14 : 0] adderSave, next_adderSave;
    logic [14 : 0] adderIn, next_adderIn;
    
    //counter
    wire [14 : 0] countOut;
    logic [14 : 0] countSave, next_countSave;
    logic [14 : 0] countIn, next_countIn;

    //complement counter
    wire stopCount;

    always_ff @(posedge clk, negedge nRST) begin
        if(!nRST) begin
            state <= IDLE;
				finish <= 1'b0;
				diffSign <= 0;
				n1 <= 0;
				n2 <= 0;
				countSave <= 0;
				countIn <= 0;
				adderSave <= 0;
				adderIn <= 0;
				out <= 0;
        end else begin
            state <= next;
				finish <= next_finish;
				diffSign <= next_diffSign;
				n1 <= next_n1;
				n2 <= next_n2;
				countSave <= next_countSave;
				countIn <= next_countIn;
				adderSave <= next_adderSave;
				adderIn <= next_adderIn;
				out <= next_out;
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
/* verilator lint_off PINCONNECTEMPTY */
	adder15 main(.sum(adderOut), .cOut(), .in1(n1), .in2(adderIn), .sub(1'b0));

    //counter
	adder15 count(.sum(countOut), .cOut(), .in1(countIn), .in2(15'b1), .sub(1'b0));
	
	//coutner for multiply
	adder15 compCount(.sum(), .cOut(stopCount), .in1(countOut), .in2(n2), .sub(1'b1)); 
/* verilator lint_on PINCONNECTEMPTY */
    always_comb begin
        
	next_finish = finish;
	next_diffSign = diffSign;
	next_n1 = n1;
	next_n2 = n2;
	next_countSave = countSave;
	next_countIn = countIn;
	next_adderSave = adderSave;
	next_adderIn = adderIn;
	next_out = out;

        casez(state)
            
            SET: begin
                	if(INn1[15] ^ INn2[15]) begin
                    	next_diffSign = 1;
                	end else begin
                    	next_diffSign = 0;
                	end

                	next_n2 [14 : 0] = INn2 [14 : 0];
                	next_n1 [14 : 0] = INn1 [14 : 0];

                	next_countSave = 15'b0;
                	next_countIn = 15'b0;

                	next_adderSave = 15'b0;
                	next_adderIn = 15'b0;
				end

            CHECKADD: begin
					//$display("cOut: %d, adderOut: %d", countOut, adderOut);
					
                	next_countSave = countOut; 
                	next_adderSave = adderOut;
				end

            ADD: begin
                	next_countIn = countSave;
                	next_adderIn = adderSave;
				end

            FIN: begin
               		next_out [14 : 0] =  adderSave [14 : 0];
                	next_out [15] = diffSign;
                	next_finish = 1'b1;
				end

			default:
				next_finish = 1'b0;

        endcase
    end

endmodule
