// gencon_defs.sv
typedef enum logic [3:0] {
    SEND_MULT_OP1_START = 4'b0000,
    WAIT_MULT_OP1       = 4'b0001,
    GET_FIRST_NUM       = 4'b0010,
    SEND_MULT_OP2_START = 4'b0011,
    WAIT_MULT_OP2       = 4'b0100,
    GET_SECOND_NUM      = 4'b0101,
    SEND_TO_ALU         = 4'b0110,
    WAIT_ALU            = 4'b0111,
    SHOW_RESULT_ALU     = 4'b1000,
    SHOW_RESULT_MULT    = 4'b1001
} state_t;
