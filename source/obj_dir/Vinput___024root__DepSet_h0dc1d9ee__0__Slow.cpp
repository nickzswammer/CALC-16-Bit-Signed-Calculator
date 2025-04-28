// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinput.h for the primary calling header

#include "Vinput__pch.h"
#include "Vinput___024root.h"

VL_ATTR_COLD void Vinput___024root___eval_static(Vinput___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vinput___024root___eval_initial__TOP(Vinput___024root* vlSelf);

VL_ATTR_COLD void Vinput___024root___eval_initial(Vinput___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vinput___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__Clock__0 = vlSelfRef.Clock;
    vlSelfRef.__Vtrigprevexpr___TOP__Reset__0 = vlSelfRef.Reset;
}

VL_ATTR_COLD void Vinput___024root___eval_initial__TOP(Vinput___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput___024root___eval_initial__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.read__DOT__ColOut__out__strong__out0 
        = (8U & (IData)(vlSelfRef.read__DOT__ColOut__out__strong__out0));
    vlSelfRef.read__DOT__ColOut__out__strong__out1 
        = (7U & (IData)(vlSelfRef.read__DOT__ColOut__out__strong__out1));
}

VL_ATTR_COLD void Vinput___024root___eval_final(Vinput___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput___024root___dump_triggers__stl(Vinput___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vinput___024root___eval_phase__stl(Vinput___024root* vlSelf);

VL_ATTR_COLD void Vinput___024root___eval_settle(Vinput___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput___024root___eval_settle\n"); );
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
            Vinput___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("input.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vinput___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput___024root___dump_triggers__stl(Vinput___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput___024root___dump_triggers__stl\n"); );
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

VL_ATTR_COLD void Vinput___024root___stl_sequent__TOP__0(Vinput___024root* vlSelf);

VL_ATTR_COLD void Vinput___024root___eval_stl(Vinput___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vinput___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vinput___024root___stl_sequent__TOP__0(Vinput___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ColOut = (((7U & (~ (IData)(vlSelfRef.read__DOT__Col))) 
                         | (8U & ((~ ((IData)(vlSelfRef.read__DOT__Col) 
                                      >> 3U)) << 3U))) 
                        & ((7U & ((IData)(vlSelfRef.read__DOT__ColOut__out__strong__out0) 
                                  & (~ (IData)(vlSelfRef.read__DOT__Col)))) 
                           | (8U & ((IData)(vlSelfRef.read__DOT__ColOut__out__strong__out1) 
                                    & ((~ ((IData)(vlSelfRef.read__DOT__Col) 
                                           >> 3U)) 
                                       << 3U)))));
}

VL_ATTR_COLD void Vinput___024root___eval_triggers__stl(Vinput___024root* vlSelf);

VL_ATTR_COLD bool Vinput___024root___eval_phase__stl(Vinput___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vinput___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vinput___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput___024root___dump_triggers__act(Vinput___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge Clock or negedge Reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput___024root___dump_triggers__nba(Vinput___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge Clock or negedge Reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vinput___024root___ctor_var_reset(Vinput___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->Reset = VL_RAND_RESET_I(1);
    vlSelf->Clock = VL_RAND_RESET_I(1);
    vlSelf->RowIn = VL_RAND_RESET_I(4);
    vlSelf->ColOut = VL_RAND_RESET_I(4);
    vlSelf->LFSRReset = VL_RAND_RESET_I(1);
    vlSelf->LFSRFlg = VL_RAND_RESET_I(1);
    vlSelf->KeyRdy = VL_RAND_RESET_I(1);
    vlSelf->KeyRd = VL_RAND_RESET_I(1);
    vlSelf->Number = VL_RAND_RESET_I(4);
    vlSelf->Operator = VL_RAND_RESET_I(3);
    vlSelf->EqualSign = VL_RAND_RESET_I(1);
    vlSelf->read__DOT__State = VL_RAND_RESET_I(2);
    vlSelf->read__DOT__Counter = VL_RAND_RESET_I(3);
    vlSelf->read__DOT__Data = VL_RAND_RESET_I(16);
    vlSelf->read__DOT__Col = VL_RAND_RESET_I(4);
    vlSelf->read__DOT__Sum = VL_RAND_RESET_I(1);
    vlSelf->read__DOT__ZeroChecker = VL_RAND_RESET_I(1);
    vlSelf->read__DOT__waitbit = VL_RAND_RESET_I(1);
    vlSelf->read__DOT__ColOut__out__strong__out0 = VL_RAND_RESET_I(4);
    vlSelf->read__DOT__ColOut__out__strong__out1 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigprevexpr___TOP__Clock__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__Reset__0 = VL_RAND_RESET_I(1);
}
