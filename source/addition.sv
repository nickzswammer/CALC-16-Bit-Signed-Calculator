module adder(
	output sum,
	output cOut,
	

	input in1,
	input in2,
	input cIn
);
	assign sum = in1 ^ in2 ^ cIn;
	assign cOut = (in1 & in2) | (in2 & cIn) | (cIn & in1);	
endmodule

module adder15(
	output [14:0] sum,
	output cOut,

	input [14:0] in1,
	input [14:0] in2,
	input sub
);
	wire carry[14:0];

	adder a0(sum[0], carry[0], in1[0], in2[0] ^ sub, sub);
	
	genvar i;
	generate for (i = 1; i < 15; i = i + 1) begin: GENERATE_ADDER
    		adder thingy(sum[i], carry[i], in1[i], in2[i] ^ sub, carry[i - 1]);
	end endgenerate
	
	assign cOut = carry[14];
	

endmodule

module addition
(
	input wire clk,
	input wire nRST,
	input logic [15 : 0] INn1,
	input logic [15 : 0] INn2,
	input logic sub,
	input wire start,

	output logic [15 : 0] out,
	output logic finish 
);

    typedef enum logic [2:0]
    {
    IDLE,
    SET,
    ADD,
    FIN
    } state_t;

    state_t state, next;
	 logic next_finish;
	 logic [15:0] next_out;

    logic [14 : 0] n1, next_n1;
    logic [14 : 0] n2, next_n2;

    logic diffSign, next_diffSign;
	logic sameSignVal, next_sameSignVal;	

    wire [14 : 0] comp;

    wire [14 : 0] adderOut;
    wire adderCOut;

    always_ff @(posedge clk, negedge nRST) begin
        if(!nRST) begin
            state <= IDLE;
				finish <= 1'b0;
				diffSign <= 0;
				n2 <= 0;
				n1 <= 0;
				sameSignVal <= 0;
				out <= 0;
        end else begin
            state <= next;
				finish <= next_finish;
				diffSign <= next_diffSign;
				n2 <= next_n2;
				n1 <= next_n1;
				sameSignVal <= next_sameSignVal;
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
            next = ADD;
        end

        ADD: begin
            next = FIN;
        end
        
        FIN: if(!start) begin
            next = IDLE;
        end
		
		default:
			next = state;

        endcase
    end

/* verilator lint_off PINCONNECTEMPTY */
    adder15 main(.sum(adderOut), .cOut(adderCOut), .in1(n1), .in2(n2), .sub(diffSign)); 
	adder15 complement(.sum(comp), .cOut(), .in1(15'b0), .in2(adderOut), .sub(1'b1));
	/* verilator lint_on PINCONNECTEMPTY */
        
    always_comb begin
        
		next_finish = finish;
		next_diffSign = diffSign;
		next_n2 = n2;
		next_n1 = n1;
		next_sameSignVal = sameSignVal;
		next_out = out;

        casez(state)
            
            SET:
                if(INn1[15] ^ (INn2[15] ^ sub)) begin
                    next_diffSign = 1;

                    if(INn1[15] == 1) begin
                        next_n2 [14 : 0] = INn1 [14 : 0];
                        next_n1 [14 : 0] = INn2 [14 : 0];
                    end else begin
                        next_n2 [14 : 0] = INn2 [14 : 0];
                        next_n1 [14 : 0] = INn1 [14 : 0];
                    end	
                end else begin
                    next_diffSign = 0;

					next_sameSignVal = INn1[15];

                    next_n2 [14 : 0] = INn2 [14 : 0];
                    next_n1 [14 : 0] = INn1 [14 : 0];
                end

            ADD:
                if(!adderCOut && diffSign) begin
                    next_out [14 : 0] = comp [14 : 0];
                    next_out [15] = 1'b1;
                end else begin
                    next_out [14 : 0] = adderOut [14 : 0];
                    if(diffSign) begin
                        next_out [15] = 1'b0;
                    end else begin 
                        next_out [15] = sameSignVal;
                    end
                end
            
            FIN:
                next_finish = 1'b1;
			default:
				next_finish = 1'b0;
				
        endcase
    end
endmodule
