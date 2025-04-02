// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmemory.h for the primary calling header

#include "Vmemory__pch.h"
#include "Vmemory__Syms.h"
#include "Vmemory___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmemory___024root___dump_triggers__ico(Vmemory___024root* vlSelf);
#endif  // VL_DEBUG

void Vmemory___024root___eval_triggers__ico(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_triggers__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmemory___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmemory___024root___dump_triggers__act(Vmemory___024root* vlSelf);
#endif  // VL_DEBUG

void Vmemory___024root___eval_triggers__act(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmemory___024root___dump_triggers__act(vlSelf);
    }
#endif
}
