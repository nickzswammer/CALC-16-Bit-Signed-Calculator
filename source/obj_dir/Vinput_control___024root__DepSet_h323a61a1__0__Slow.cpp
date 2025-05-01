// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinput_control.h for the primary calling header

#include "Vinput_control__pch.h"
#include "Vinput_control__Syms.h"
#include "Vinput_control___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput_control___024root___dump_triggers__stl(Vinput_control___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vinput_control___024root___eval_triggers__stl(Vinput_control___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control___024root___eval_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vinput_control___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
