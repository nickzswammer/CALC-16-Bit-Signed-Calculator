// gencon_defs.sv
`ifndef GENCON_DEFS_SV
`define GENCON_DEFS_SV

typedef enum logic [3:0] {
    SEND_MULT_OP1_START = 4'b0000,  // 0
    WAIT_MULT_OP1       = 4'b0001,  // 1
    GET_FIRST_NUM       = 4'b0010,  // 2
    SEND_MULT_OP2_START = 4'b0011,  // 3
    WAIT_MULT_OP2       = 4'b0100,  // 4
    GET_SECOND_NUM      = 4'b0101,  // 5
    SEND_TO_ALU         = 4'b0110,  // 6
    WAIT_ALU            = 4'b0111,  // 7
    SHOW_RESULT_ALU     = 4'b1000,  // 8
    SHOW_RESULT_MULT    = 4'b1001   // 9
} state_t;

`endif
