// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmemory.h for the primary calling header

#include "Vmemory__pch.h"
#include "Vmemory___024root.h"

void Vmemory___024root___ico_sequent__TOP__0(Vmemory___024root* vlSelf);

void Vmemory___024root___eval_ico(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vmemory___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vmemory___024root___ico_sequent__TOP__0(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.memory__DOT____VdfgRegularize_h192772c8_0_0 
        = ((~ (IData)(vlSelfRef.we)) & (IData)(vlSelfRef.oe));
    vlSelfRef.data = (((IData)(vlSelfRef.memory__DOT____VdfgRegularize_h192772c8_0_0)
                        ? 0xffffU : 0U) & (((IData)(vlSelfRef.memory__DOT____VdfgRegularize_h192772c8_0_0)
                                             ? (IData)(vlSelfRef.memory__DOT__tmp_data)
                                             : 0U) 
                                           & ((IData)(vlSelfRef.memory__DOT____VdfgRegularize_h192772c8_0_0)
                                               ? 0xffffU
                                               : 0U)));
}

void Vmemory___024root___eval_triggers__ico(Vmemory___024root* vlSelf);

bool Vmemory___024root___eval_phase__ico(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vmemory___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vmemory___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vmemory___024root___eval_act(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vmemory___024root___nba_sequent__TOP__0(Vmemory___024root* vlSelf);

void Vmemory___024root___eval_nba(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vmemory___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vmemory___024root___nba_sequent__TOP__0(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __VdlyVal__memory__DOT__mem__v0;
    __VdlyVal__memory__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__memory__DOT__mem__v0;
    __VdlyDim0__memory__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__memory__DOT__mem__v0;
    __VdlySet__memory__DOT__mem__v0 = 0;
    // Body
    __VdlySet__memory__DOT__mem__v0 = 0U;
    if (vlSelfRef.we) {
        __VdlyVal__memory__DOT__mem__v0 = vlSelfRef.mem_data;
        __VdlyDim0__memory__DOT__mem__v0 = vlSelfRef.mem_addr;
        __VdlySet__memory__DOT__mem__v0 = 1U;
    }
    if ((1U & (~ (IData)(vlSelfRef.we)))) {
        vlSelfRef.memory__DOT__tmp_data = vlSelfRef.memory__DOT__mem
            [vlSelfRef.mem_addr];
    }
    if (__VdlySet__memory__DOT__mem__v0) {
        vlSelfRef.memory__DOT__mem[__VdlyDim0__memory__DOT__mem__v0] 
            = __VdlyVal__memory__DOT__mem__v0;
    }
    vlSelfRef.data = (((IData)(vlSelfRef.memory__DOT____VdfgRegularize_h192772c8_0_0)
                        ? 0xffffU : 0U) & (((IData)(vlSelfRef.memory__DOT____VdfgRegularize_h192772c8_0_0)
                                             ? (IData)(vlSelfRef.memory__DOT__tmp_data)
                                             : 0U) 
                                           & ((IData)(vlSelfRef.memory__DOT____VdfgRegularize_h192772c8_0_0)
                                               ? 0xffffU
                                               : 0U)));
}

void Vmemory___024root___eval_triggers__act(Vmemory___024root* vlSelf);

bool Vmemory___024root___eval_phase__act(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vmemory___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vmemory___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vmemory___024root___eval_phase__nba(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vmemory___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmemory___024root___dump_triggers__ico(Vmemory___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmemory___024root___dump_triggers__nba(Vmemory___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmemory___024root___dump_triggers__act(Vmemory___024root* vlSelf);
#endif  // VL_DEBUG

void Vmemory___024root___eval(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vmemory___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("memory.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vmemory___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vmemory___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("memory.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vmemory___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("memory.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vmemory___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vmemory___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vmemory___024root___eval_debug_assertions(Vmemory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmemory___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.mem_addr & 0xf0U))) {
        Verilated::overWidthError("mem_addr");}
    if (VL_UNLIKELY((vlSelfRef.we & 0xfeU))) {
        Verilated::overWidthError("we");}
    if (VL_UNLIKELY((vlSelfRef.oe & 0xfeU))) {
        Verilated::overWidthError("oe");}
}
#endif  // VL_DEBUG
