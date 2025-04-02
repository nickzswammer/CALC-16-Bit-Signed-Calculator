// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vgencon__Syms.h"


VL_ATTR_COLD void Vgencon___024root__trace_init_sub__TOP__0(Vgencon___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root__trace_init_sub__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+56,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"keypad_input",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+59,0,"operator_input",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"equal_input",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"complete",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+62,0,"display_output",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+63,0,"ALU_in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+64,0,"ALU_in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+65,0,"start_calc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+66,0,"ALU_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+67,0,"ALU_finish",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"oe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"mem_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+71,0,"mem_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+72,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("gencon", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+56,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"keypad_input",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+59,0,"operator_input",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"equal_input",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"complete",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+62,0,"display_output",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+63,0,"ALU_in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+64,0,"ALU_in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+65,0,"start_calc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+66,0,"ALU_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+67,0,"ALU_finish",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"oe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"mem_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+71,0,"mem_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+72,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+73,0,"current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+74,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+178,0,"operand1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+179,0,"operand2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("add_calc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+56,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"INn1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+64,0,"INn2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+180,0,"sub",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+66,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+67,0,"finish",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1,0,"next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+2,0,"n1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+3,0,"n2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+19,0,"diffSign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"sameSignVal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+181,0,"tempVal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+182,0,"writeTemp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"comp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+183,0,"Num",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+77,0,"adderOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+78,0,"adderCOut",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("complement", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+76,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+79,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+184,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+77,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+185,0,"sub",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("carry", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 15; ++i) {
        tracep->declBit(c+80+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("a0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+21,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+185,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[10]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+95,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[11]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+99,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[12]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+102,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[13]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+105,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[14]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+108,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+110,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+113,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+116,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[4]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+119,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[5]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+122,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[6]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+125,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+127,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[7]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+128,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[8]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+131,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[9]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+134,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("main", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+77,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+78,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+3,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+19,0,"sub",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("carry", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 15; ++i) {
        tracep->declBit(c+136+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("a0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+21,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[10]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+151,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[11]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+154,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[12]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+156,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[13]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+158,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+159,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[14]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+160,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+159,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+161,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+163,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+164,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+165,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+166,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+164,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[4]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+167,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+168,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+166,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[5]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+169,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+168,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[6]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+171,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+172,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[7]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+173,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+172,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[8]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+175,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("genblk1[9]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("thingy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+177,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"cOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"cIn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("mem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+56,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"mem_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+71,0,"mem_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+72,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+68,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"oe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"tmp_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("mem", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+40+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vgencon___024root__trace_init_top(Vgencon___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root__trace_init_top\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vgencon___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vgencon___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vgencon___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vgencon___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vgencon___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vgencon___024root__trace_register(Vgencon___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root__trace_register\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vgencon___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vgencon___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vgencon___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vgencon___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vgencon___024root__trace_const_0_sub_0(Vgencon___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vgencon___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root__trace_const_0\n"); );
    // Init
    Vgencon___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgencon___024root*>(voidSelf);
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vgencon___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vgencon___024root__trace_const_0_sub_0(Vgencon___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root__trace_const_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+178,(vlSelfRef.gencon__DOT__operand1),16);
    bufp->fullSData(oldp+179,(vlSelfRef.gencon__DOT__operand2),16);
    bufp->fullBit(oldp+180,(0U));
    bufp->fullSData(oldp+181,(vlSelfRef.gencon__DOT__add_calc__DOT__tempVal),15);
    bufp->fullBit(oldp+182,(vlSelfRef.gencon__DOT__add_calc__DOT__writeTemp));
    bufp->fullSData(oldp+183,(vlSelfRef.gencon__DOT__add_calc__DOT__Num),15);
    bufp->fullSData(oldp+184,(0U),15);
    bufp->fullBit(oldp+185,(1U));
}

VL_ATTR_COLD void Vgencon___024root__trace_full_0_sub_0(Vgencon___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vgencon___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root__trace_full_0\n"); );
    // Init
    Vgencon___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgencon___024root*>(voidSelf);
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vgencon___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vgencon___024root__trace_full_0_sub_0(Vgencon___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root__trace_full_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelfRef.gencon__DOT__add_calc__DOT__next),3);
    bufp->fullSData(oldp+2,(vlSelfRef.gencon__DOT__add_calc__DOT__n1),15);
    bufp->fullSData(oldp+3,(vlSelfRef.gencon__DOT__add_calc__DOT__n2),15);
    bufp->fullBit(oldp+4,((1U & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1))));
    bufp->fullBit(oldp+5,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                 >> 0xaU))));
    bufp->fullBit(oldp+6,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                 >> 0xbU))));
    bufp->fullBit(oldp+7,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                 >> 0xcU))));
    bufp->fullBit(oldp+8,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                 >> 0xdU))));
    bufp->fullBit(oldp+9,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                 >> 0xeU))));
    bufp->fullBit(oldp+10,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                  >> 1U))));
    bufp->fullBit(oldp+11,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                  >> 2U))));
    bufp->fullBit(oldp+12,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                  >> 3U))));
    bufp->fullBit(oldp+13,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                  >> 4U))));
    bufp->fullBit(oldp+14,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                  >> 5U))));
    bufp->fullBit(oldp+15,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                  >> 6U))));
    bufp->fullBit(oldp+16,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                  >> 7U))));
    bufp->fullBit(oldp+17,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                  >> 8U))));
    bufp->fullBit(oldp+18,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                  >> 9U))));
    bufp->fullBit(oldp+19,(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign));
    bufp->fullBit(oldp+20,(vlSelfRef.gencon__DOT__add_calc__DOT__sameSignVal));
    bufp->fullBit(oldp+21,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1));
    bufp->fullBit(oldp+22,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1)))));
    bufp->fullBit(oldp+23,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__a0____pinNumber2));
    bufp->fullBit(oldp+24,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__a0____pinNumber4));
    bufp->fullBit(oldp+25,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__10__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+26,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__11__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+27,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__12__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+28,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__13__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+29,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__14__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+30,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+31,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+32,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+33,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+34,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+35,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+36,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+37,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__8__KET____DOT__thingy____pinNumber4));
    bufp->fullBit(oldp+38,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__9__KET____DOT__thingy____pinNumber4));
    bufp->fullSData(oldp+39,(vlSelfRef.gencon__DOT__mem__DOT__tmp_data),16);
    bufp->fullSData(oldp+40,(vlSelfRef.gencon__DOT__mem__DOT__mem[0]),16);
    bufp->fullSData(oldp+41,(vlSelfRef.gencon__DOT__mem__DOT__mem[1]),16);
    bufp->fullSData(oldp+42,(vlSelfRef.gencon__DOT__mem__DOT__mem[2]),16);
    bufp->fullSData(oldp+43,(vlSelfRef.gencon__DOT__mem__DOT__mem[3]),16);
    bufp->fullSData(oldp+44,(vlSelfRef.gencon__DOT__mem__DOT__mem[4]),16);
    bufp->fullSData(oldp+45,(vlSelfRef.gencon__DOT__mem__DOT__mem[5]),16);
    bufp->fullSData(oldp+46,(vlSelfRef.gencon__DOT__mem__DOT__mem[6]),16);
    bufp->fullSData(oldp+47,(vlSelfRef.gencon__DOT__mem__DOT__mem[7]),16);
    bufp->fullSData(oldp+48,(vlSelfRef.gencon__DOT__mem__DOT__mem[8]),16);
    bufp->fullSData(oldp+49,(vlSelfRef.gencon__DOT__mem__DOT__mem[9]),16);
    bufp->fullSData(oldp+50,(vlSelfRef.gencon__DOT__mem__DOT__mem[10]),16);
    bufp->fullSData(oldp+51,(vlSelfRef.gencon__DOT__mem__DOT__mem[11]),16);
    bufp->fullSData(oldp+52,(vlSelfRef.gencon__DOT__mem__DOT__mem[12]),16);
    bufp->fullSData(oldp+53,(vlSelfRef.gencon__DOT__mem__DOT__mem[13]),16);
    bufp->fullSData(oldp+54,(vlSelfRef.gencon__DOT__mem__DOT__mem[14]),16);
    bufp->fullSData(oldp+55,(vlSelfRef.gencon__DOT__mem__DOT__mem[15]),16);
    bufp->fullBit(oldp+56,(vlSelfRef.clk));
    bufp->fullBit(oldp+57,(vlSelfRef.reset));
    bufp->fullCData(oldp+58,(vlSelfRef.keypad_input),4);
    bufp->fullBit(oldp+59,(vlSelfRef.operator_input));
    bufp->fullBit(oldp+60,(vlSelfRef.equal_input));
    bufp->fullBit(oldp+61,(vlSelfRef.complete));
    bufp->fullSData(oldp+62,(vlSelfRef.display_output),16);
    bufp->fullSData(oldp+63,(vlSelfRef.ALU_in1),16);
    bufp->fullSData(oldp+64,(vlSelfRef.ALU_in2),16);
    bufp->fullBit(oldp+65,(vlSelfRef.start_calc));
    bufp->fullSData(oldp+66,(vlSelfRef.ALU_out),16);
    bufp->fullBit(oldp+67,(vlSelfRef.ALU_finish));
    bufp->fullBit(oldp+68,(vlSelfRef.we));
    bufp->fullBit(oldp+69,(vlSelfRef.oe));
    bufp->fullCData(oldp+70,(vlSelfRef.mem_addr),4);
    bufp->fullSData(oldp+71,(vlSelfRef.mem_data),16);
    bufp->fullSData(oldp+72,(vlSelfRef.data),16);
    bufp->fullCData(oldp+73,(vlSelfRef.gencon__DOT__current_state),3);
    bufp->fullCData(oldp+74,(vlSelfRef.gencon__DOT__next_state),3);
    bufp->fullCData(oldp+75,(vlSelfRef.gencon__DOT__add_calc__DOT__state),3);
    bufp->fullSData(oldp+76,(((0x4000U ^ (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1) 
                                           ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2)) 
                                          << 0xeU)) 
                              | ((0x2000U ^ (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1) 
                                              ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2)) 
                                             << 0xdU)) 
                                 | ((0x1000U ^ (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber1) 
                                                 ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2)) 
                                                << 0xcU)) 
                                    | ((0x800U ^ (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber1) 
                                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2)) 
                                                  << 0xbU)) 
                                       | ((0x400U ^ 
                                           (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber1) 
                                             ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2)) 
                                            << 0xaU)) 
                                          | ((0x200U 
                                              ^ (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber1) 
                                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2)) 
                                                 << 9U)) 
                                             | ((0x100U 
                                                 ^ 
                                                 (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber1) 
                                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2)) 
                                                  << 8U)) 
                                                | ((0x80U 
                                                    ^ 
                                                    (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber1) 
                                                      ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2)) 
                                                     << 7U)) 
                                                   | ((0x40U 
                                                       ^ 
                                                       (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber1) 
                                                         ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2)) 
                                                        << 6U)) 
                                                      | ((0x20U 
                                                          ^ 
                                                          (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber1) 
                                                            ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2)) 
                                                           << 5U)) 
                                                         | ((0x10U 
                                                             ^ 
                                                             (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber1) 
                                                               ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2)) 
                                                              << 4U)) 
                                                            | ((8U 
                                                                ^ 
                                                                (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber1) 
                                                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2)) 
                                                                 << 3U)) 
                                                               | ((4U 
                                                                   ^ 
                                                                   (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber1) 
                                                                     ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2)) 
                                                                    << 2U)) 
                                                                  | ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber1) 
                                                                       ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1)) 
                                                                      << 1U) 
                                                                     | (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1)))))))))))))))),15);
    bufp->fullSData(oldp+77,((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1) 
                               << 0xeU) | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1) 
                                            << 0xdU) 
                                           | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber1) 
                                               << 0xcU) 
                                              | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber1) 
                                                  << 0xbU) 
                                                 | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber1) 
                                                     << 0xaU) 
                                                    | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber1) 
                                                        << 9U) 
                                                       | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber1) 
                                                           << 8U) 
                                                          | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber1) 
                                                              << 7U) 
                                                             | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber1) 
                                                                 << 6U) 
                                                                | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber1) 
                                                                    << 5U) 
                                                                   | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber1) 
                                                                       << 4U) 
                                                                      | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber1) 
                                                                          << 3U) 
                                                                         | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber1) 
                                                                             << 2U) 
                                                                            | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber1) 
                                                                                << 1U) 
                                                                               | (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1)))))))))))))))),15);
    bufp->fullBit(oldp+78,(vlSelfRef.gencon__DOT__add_calc__DOT__adderCOut));
    bufp->fullBit(oldp+79,(((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1)) 
                            & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2))));
    bufp->fullBit(oldp+80,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[0]));
    bufp->fullBit(oldp+81,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[1]));
    bufp->fullBit(oldp+82,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[2]));
    bufp->fullBit(oldp+83,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[3]));
    bufp->fullBit(oldp+84,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[4]));
    bufp->fullBit(oldp+85,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[5]));
    bufp->fullBit(oldp+86,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[6]));
    bufp->fullBit(oldp+87,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[7]));
    bufp->fullBit(oldp+88,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[8]));
    bufp->fullBit(oldp+89,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[9]));
    bufp->fullBit(oldp+90,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[10]));
    bufp->fullBit(oldp+91,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[11]));
    bufp->fullBit(oldp+92,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[12]));
    bufp->fullBit(oldp+93,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[13]));
    bufp->fullBit(oldp+94,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[14]));
    bufp->fullBit(oldp+95,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+96,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+97,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+98,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+99,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+100,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+101,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+102,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber1) 
                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+103,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+104,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+105,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1) 
                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+106,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+107,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+108,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1) 
                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+109,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+110,(((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber1) 
                             ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1))));
    bufp->fullBit(oldp+111,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+112,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+113,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber1) 
                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+114,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+115,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+116,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber1) 
                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+117,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+118,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+119,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber1) 
                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+120,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+121,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+122,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber1) 
                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+123,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+124,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+125,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber1) 
                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+126,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+127,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+128,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber1) 
                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+129,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+130,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+131,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber1) 
                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+132,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+133,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+134,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber1) 
                                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2)))));
    bufp->fullBit(oldp+135,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber1)))));
    bufp->fullBit(oldp+136,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[0]));
    bufp->fullBit(oldp+137,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[1]));
    bufp->fullBit(oldp+138,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[2]));
    bufp->fullBit(oldp+139,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[3]));
    bufp->fullBit(oldp+140,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[4]));
    bufp->fullBit(oldp+141,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[5]));
    bufp->fullBit(oldp+142,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[6]));
    bufp->fullBit(oldp+143,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[7]));
    bufp->fullBit(oldp+144,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[8]));
    bufp->fullBit(oldp+145,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[9]));
    bufp->fullBit(oldp+146,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[10]));
    bufp->fullBit(oldp+147,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[11]));
    bufp->fullBit(oldp+148,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[12]));
    bufp->fullBit(oldp+149,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[13]));
    bufp->fullBit(oldp+150,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[14]));
    bufp->fullBit(oldp+151,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+152,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+153,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+154,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+155,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+156,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+157,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+158,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+159,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+160,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+161,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+162,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+163,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+164,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+165,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+166,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+167,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+168,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+169,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+170,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+171,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+172,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+173,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+174,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+175,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber1));
    bufp->fullBit(oldp+176,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2));
    bufp->fullBit(oldp+177,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber1));
}
