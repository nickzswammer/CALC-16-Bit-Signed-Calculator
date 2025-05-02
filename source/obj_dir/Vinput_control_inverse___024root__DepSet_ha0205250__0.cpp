// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinput_control_inverse.h for the primary calling header

#include "Vinput_control_inverse__pch.h"
#include "Vinput_control_inverse__Syms.h"
#include "Vinput_control_inverse___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput_control_inverse___024root___dump_triggers__ico(Vinput_control_inverse___024root* vlSelf);
#endif  // VL_DEBUG

void Vinput_control_inverse___024root___eval_triggers__ico(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_triggers__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vinput_control_inverse___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput_control_inverse___024root___dump_triggers__act(Vinput_control_inverse___024root* vlSelf);
#endif  // VL_DEBUG

void Vinput_control_inverse___024root___eval_triggers__act(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, (((IData)(vlSelfRef.clk) 
                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))) 
                                       | ((~ (IData)(vlSelfRef.nRST)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__nRST__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__nRST__0 = vlSelfRef.nRST;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vinput_control_inverse___024root___dump_triggers__act(vlSelf);
    }
#endif
}
