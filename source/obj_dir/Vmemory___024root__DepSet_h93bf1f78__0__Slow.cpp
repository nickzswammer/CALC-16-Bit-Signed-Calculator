// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmemory.h for the primary calling header

#include "Vmemory__pch.h"
#include "Vmemory___024root.h"

VL_ATTR_COLD void Vmemory___024root___eval_static(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmemory___024root___eval_initial(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vmemory___024root___eval_final(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmemory___024root___dump_triggers__stl(Vmemory___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmemory___024root___eval_phase__stl(Vmemory___024root* vlSelf);

VL_ATTR_COLD void Vmemory___024root___eval_settle(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vmemory___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("memory.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vmemory___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmemory___024root___dump_triggers__stl(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___dump_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vmemory___024root___ico_sequent__TOP__0(Vmemory___024root* vlSelf);

VL_ATTR_COLD void Vmemory___024root___eval_stl(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vmemory___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vmemory___024root___eval_triggers__stl(Vmemory___024root* vlSelf);

VL_ATTR_COLD bool Vmemory___024root___eval_phase__stl(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vmemory___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vmemory___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmemory___024root___dump_triggers__ico(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___dump_triggers__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmemory___024root___dump_triggers__act(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmemory___024root___dump_triggers__nba(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmemory___024root___ctor_var_reset(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->mem_addr = VL_RAND_RESET_I(4);
    vlSelf->mem_data = VL_RAND_RESET_I(16);
    vlSelf->data = VL_RAND_RESET_I(16);
    vlSelf->we = VL_RAND_RESET_I(1);
    vlSelf->oe = VL_RAND_RESET_I(1);
    vlSelf->memory__DOT__tmp_data = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->memory__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->memory__DOT____VdfgRegularize_h192772c8_0_0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
