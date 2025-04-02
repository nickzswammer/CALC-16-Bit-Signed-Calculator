// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vgencon__Syms.h"


void Vgencon___024root__trace_chg_0_sub_0(Vgencon___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vgencon___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root__trace_chg_0\n"); );
    // Init
    Vgencon___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgencon___024root*>(voidSelf);
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vgencon___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vgencon___024root__trace_chg_0_sub_0(Vgencon___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [5U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.gencon__DOT__add_calc__DOT__next),3);
        bufp->chgSData(oldp+1,(vlSelfRef.gencon__DOT__add_calc__DOT__n1),15);
        bufp->chgSData(oldp+2,(vlSelfRef.gencon__DOT__add_calc__DOT__n2),15);
        bufp->chgBit(oldp+3,((1U & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1))));
        bufp->chgBit(oldp+4,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                    >> 0xaU))));
        bufp->chgBit(oldp+5,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                    >> 0xbU))));
        bufp->chgBit(oldp+6,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                    >> 0xcU))));
        bufp->chgBit(oldp+7,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                    >> 0xdU))));
        bufp->chgBit(oldp+8,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                    >> 0xeU))));
        bufp->chgBit(oldp+9,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                    >> 1U))));
        bufp->chgBit(oldp+10,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                     >> 2U))));
        bufp->chgBit(oldp+11,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                     >> 3U))));
        bufp->chgBit(oldp+12,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                     >> 4U))));
        bufp->chgBit(oldp+13,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                     >> 5U))));
        bufp->chgBit(oldp+14,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                     >> 6U))));
        bufp->chgBit(oldp+15,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                     >> 7U))));
        bufp->chgBit(oldp+16,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                     >> 8U))));
        bufp->chgBit(oldp+17,((1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                                     >> 9U))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [3U]) | vlSelfRef.__Vm_traceActivity
                     [6U]))) {
        bufp->chgBit(oldp+18,(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign));
        bufp->chgBit(oldp+19,(vlSelfRef.gencon__DOT__add_calc__DOT__sameSignVal));
        bufp->chgBit(oldp+20,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1));
        bufp->chgBit(oldp+21,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1)))));
        bufp->chgBit(oldp+22,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__a0____pinNumber2));
        bufp->chgBit(oldp+23,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__a0____pinNumber4));
        bufp->chgBit(oldp+24,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__10__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+25,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__11__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+26,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__12__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+27,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__13__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+28,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__14__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+29,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+30,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+31,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+32,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+33,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+34,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+35,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+36,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__8__KET____DOT__thingy____pinNumber4));
        bufp->chgBit(oldp+37,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__9__KET____DOT__thingy____pinNumber4));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[4U])) {
        bufp->chgSData(oldp+38,(vlSelfRef.gencon__DOT__mem__DOT__tmp_data),16);
        bufp->chgSData(oldp+39,(vlSelfRef.gencon__DOT__mem__DOT__mem[0]),16);
        bufp->chgSData(oldp+40,(vlSelfRef.gencon__DOT__mem__DOT__mem[1]),16);
        bufp->chgSData(oldp+41,(vlSelfRef.gencon__DOT__mem__DOT__mem[2]),16);
        bufp->chgSData(oldp+42,(vlSelfRef.gencon__DOT__mem__DOT__mem[3]),16);
        bufp->chgSData(oldp+43,(vlSelfRef.gencon__DOT__mem__DOT__mem[4]),16);
        bufp->chgSData(oldp+44,(vlSelfRef.gencon__DOT__mem__DOT__mem[5]),16);
        bufp->chgSData(oldp+45,(vlSelfRef.gencon__DOT__mem__DOT__mem[6]),16);
        bufp->chgSData(oldp+46,(vlSelfRef.gencon__DOT__mem__DOT__mem[7]),16);
        bufp->chgSData(oldp+47,(vlSelfRef.gencon__DOT__mem__DOT__mem[8]),16);
        bufp->chgSData(oldp+48,(vlSelfRef.gencon__DOT__mem__DOT__mem[9]),16);
        bufp->chgSData(oldp+49,(vlSelfRef.gencon__DOT__mem__DOT__mem[10]),16);
        bufp->chgSData(oldp+50,(vlSelfRef.gencon__DOT__mem__DOT__mem[11]),16);
        bufp->chgSData(oldp+51,(vlSelfRef.gencon__DOT__mem__DOT__mem[12]),16);
        bufp->chgSData(oldp+52,(vlSelfRef.gencon__DOT__mem__DOT__mem[13]),16);
        bufp->chgSData(oldp+53,(vlSelfRef.gencon__DOT__mem__DOT__mem[14]),16);
        bufp->chgSData(oldp+54,(vlSelfRef.gencon__DOT__mem__DOT__mem[15]),16);
    }
    bufp->chgBit(oldp+55,(vlSelfRef.clk));
    bufp->chgBit(oldp+56,(vlSelfRef.reset));
    bufp->chgCData(oldp+57,(vlSelfRef.keypad_input),4);
    bufp->chgBit(oldp+58,(vlSelfRef.operator_input));
    bufp->chgBit(oldp+59,(vlSelfRef.equal_input));
    bufp->chgBit(oldp+60,(vlSelfRef.complete));
    bufp->chgSData(oldp+61,(vlSelfRef.display_output),16);
    bufp->chgSData(oldp+62,(vlSelfRef.ALU_in1),16);
    bufp->chgSData(oldp+63,(vlSelfRef.ALU_in2),16);
    bufp->chgBit(oldp+64,(vlSelfRef.start_calc));
    bufp->chgSData(oldp+65,(vlSelfRef.ALU_out),16);
    bufp->chgBit(oldp+66,(vlSelfRef.ALU_finish));
    bufp->chgBit(oldp+67,(vlSelfRef.we));
    bufp->chgBit(oldp+68,(vlSelfRef.oe));
    bufp->chgCData(oldp+69,(vlSelfRef.mem_addr),4);
    bufp->chgSData(oldp+70,(vlSelfRef.mem_data),16);
    bufp->chgSData(oldp+71,(vlSelfRef.data),16);
    bufp->chgCData(oldp+72,(vlSelfRef.gencon__DOT__current_state),3);
    bufp->chgCData(oldp+73,(vlSelfRef.gencon__DOT__next_state),3);
    bufp->chgCData(oldp+74,(vlSelfRef.gencon__DOT__add_calc__DOT__state),3);
    bufp->chgSData(oldp+75,(((0x4000U ^ (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1) 
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
                                                ^ (
                                                   ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber1) 
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
    bufp->chgSData(oldp+76,((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1) 
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
    bufp->chgBit(oldp+77,(vlSelfRef.gencon__DOT__add_calc__DOT__adderCOut));
    bufp->chgBit(oldp+78,(((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1)) 
                           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2))));
    bufp->chgBit(oldp+79,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[0]));
    bufp->chgBit(oldp+80,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[1]));
    bufp->chgBit(oldp+81,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[2]));
    bufp->chgBit(oldp+82,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[3]));
    bufp->chgBit(oldp+83,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[4]));
    bufp->chgBit(oldp+84,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[5]));
    bufp->chgBit(oldp+85,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[6]));
    bufp->chgBit(oldp+86,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[7]));
    bufp->chgBit(oldp+87,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[8]));
    bufp->chgBit(oldp+88,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[9]));
    bufp->chgBit(oldp+89,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[10]));
    bufp->chgBit(oldp+90,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[11]));
    bufp->chgBit(oldp+91,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[12]));
    bufp->chgBit(oldp+92,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[13]));
    bufp->chgBit(oldp+93,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT__carry[14]));
    bufp->chgBit(oldp+94,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber1) 
                                 ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+95,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+96,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+97,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+98,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber1) 
                                 ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+99,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+100,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+101,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+102,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+103,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+104,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+105,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+106,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+107,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+108,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+109,(((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber1) 
                            ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1))));
    bufp->chgBit(oldp+110,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+111,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+112,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+113,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+114,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+115,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+116,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+117,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+118,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+119,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+120,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+121,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+122,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+123,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+124,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+125,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+126,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+127,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+128,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+129,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+130,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+131,(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+132,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+133,((1U ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber1) 
                                  ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2)))));
    bufp->chgBit(oldp+134,((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber1)))));
    bufp->chgBit(oldp+135,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[0]));
    bufp->chgBit(oldp+136,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[1]));
    bufp->chgBit(oldp+137,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[2]));
    bufp->chgBit(oldp+138,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[3]));
    bufp->chgBit(oldp+139,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[4]));
    bufp->chgBit(oldp+140,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[5]));
    bufp->chgBit(oldp+141,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[6]));
    bufp->chgBit(oldp+142,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[7]));
    bufp->chgBit(oldp+143,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[8]));
    bufp->chgBit(oldp+144,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[9]));
    bufp->chgBit(oldp+145,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[10]));
    bufp->chgBit(oldp+146,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[11]));
    bufp->chgBit(oldp+147,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[12]));
    bufp->chgBit(oldp+148,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[13]));
    bufp->chgBit(oldp+149,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT__carry[14]));
    bufp->chgBit(oldp+150,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+151,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+152,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+153,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+154,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+155,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+156,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+157,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+158,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+159,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+160,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+161,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+162,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+163,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+164,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+165,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+166,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+167,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+168,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+169,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+170,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+171,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+172,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+173,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+174,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber1));
    bufp->chgBit(oldp+175,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2));
    bufp->chgBit(oldp+176,(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber1));
}

void Vgencon___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root__trace_cleanup\n"); );
    // Init
    Vgencon___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgencon___024root*>(voidSelf);
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
