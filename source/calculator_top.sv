module calculator_top (
    input logic clk,
    input logic nRST,
    input logic [3:0] RowIn,  // from keypad rows
    output logic [3:0] ColOut,  // to keypad columns
    output logic [15:0] display_output,  // final calculation output
	output logic [2:0] input_state_FPGA,
	output logic key_pressed,
    output logic complete
);

    // Internal signals connecting input_control and gencon
    logic read_input;
    logic key_read;
    logic [3:0] keypad_input;
    logic [2:0] operator_input;
    logic equal_input;
	 
    // Instantiate input_control (handles keypad scanning & debouncing)
    input_control input_ctrl_inst (
        .clk(clk),
        .nRST(nRST),
        .RowIn(RowIn),
        .ColOut(ColOut),
        .read_input(read_input),      // output to general controller
        .key_read(key_read),          // input from general controller
        .keypad_input(keypad_input),  
        .operator_input(operator_input),
		.input_state_FPGA(input_state_FPGA),
		.key_pressed(key_pressed),
        .equal_input(equal_input)
    );

    // Instantiate general controller (calculator logic)
    gencon gencon_inst (
        .clk(clk),
        .nRST(nRST),
        .keypad_input(keypad_input),
        .read_input(read_input),
        .operator_input(operator_input),
        .equal_input(equal_input),
        .key_read(key_read),
        .complete(complete),
        .display_output(display_output)
    );

endmodule
