// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vread.h for the primary calling header

#include "Vread__pch.h"
#include "Vread__Syms.h"
#include "Vread___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vread___024root___dump_triggers__act(Vread___024root* vlSelf);
#endif  // VL_DEBUG

void Vread___024root___eval_triggers__act(Vread___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vread__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vread___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, (((IData)(vlSelfRef.Clock) 
                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__Clock__0))) 
                                       | ((~ (IData)(vlSelfRef.Reset)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__Reset__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__Clock__0 = vlSelfRef.Clock;
    vlSelfRef.__Vtrigprevexpr___TOP__Reset__0 = vlSelfRef.Reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vread___024root___dump_triggers__act(vlSelf);
    }
#endif
}
