module adder(
	/* verilator lint_off UNOPTFLAT */	
	output sum,
	output cOut,
	

	input in1,
	input in2,
	input cIn
	/* verilator lint_on UNOPTFLAT */

);
	assign sum = in1 ^ in2 ^ cIn;
	assign cOut = (in1 & in2) | (in2 & cIn) | (cIn & in1);	
endmodule

module adder15(
	
	/* verilator lint_off UNOPTFLAT */
	output [14:0] sum,
	output cOut,

	input [14:0] in1,
	input [14:0] in2,
	input sub
	/* verilator lint_on UNOPTFLAT */
	
);
	wire carry[14:0];

	adder a0(sum[0], carry[0], in1[0], in2[0] ^ sub, sub);
	
	genvar i;
	generate for (i = 1; i < 15; i = i + 1) begin
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

    logic [14 : 0] n1;
    logic [14 : 0] n2;

    logic diffSign;
	logic sameSignVal;	

    logic [14 : 0] tempVal;
    logic writeTemp;

    wire [14 : 0] comp;
    logic [14 : 0] Num;

    wire [14 : 0] adderOut;
    wire adderCOut;

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

    adder15 main(.sum(adderOut), .cOut(adderCOut), .in1(n1), .in2(n2), .sub(diffSign)); 
    adder15 complement(.sum(comp), .cOut(), .in1(15'b0), .in2(adderOut), .sub(1'b1));
        
    always_comb begin
        
	finish = 1'b0;

        casez(state)
            
            SET:
                if(INn1[15] ^ (INn2[15] ^ sub)) begin
                    diffSign = 1;

                    if(INn1[15] == 1) begin
                        n2 [14 : 0] = INn1 [14 : 0];
                        n1 [14 : 0] = INn2 [14 : 0];
                    end else begin
                        n2 [14 : 0] = INn2 [14 : 0];
                        n1 [14 : 0] = INn1 [14 : 0];
                    end	
                end else begin
                    diffSign = 0;

					sameSignVal = INn1[15];

                    n2 [14 : 0] = INn2 [14 : 0];
                    n1 [14 : 0] = INn1 [14 : 0];
                end

            ADD:
                if(!adderCOut && diffSign) begin
                    out [14 : 0] = comp [14 : 0];
                    out [15] = 1'b1;
                end else begin
                    out [14 : 0] = adderOut [14 : 0];
                    if(diffSign) begin
                        out [15] = 1'b0;
                    end else begin 
                        out [15] = sameSignVal;
                    end
                end
            
            FIN:
                finish = 1'b1;
			default:
				finish = 1'b0;
        endcase
    end
endmodule
