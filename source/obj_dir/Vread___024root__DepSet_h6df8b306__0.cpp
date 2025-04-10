// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vread.h for the primary calling header

#include "Vread__pch.h"
#include "Vread___024root.h"

void Vread___024root___eval_act(Vread___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vread__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vread___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vread___024root___nba_sequent__TOP__0(Vread___024root* vlSelf);

void Vread___024root___eval_nba(Vread___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vread__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vread___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vread___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vread___024root___nba_sequent__TOP__0(Vread___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vread__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vread___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vdly__read__DOT__State;
    __Vdly__read__DOT__State = 0;
    CData/*2:0*/ __Vdly__read__DOT__Counter;
    __Vdly__read__DOT__Counter = 0;
    CData/*3:0*/ __Vdly__read__DOT__Col;
    __Vdly__read__DOT__Col = 0;
    CData/*0:0*/ __Vdly__read__DOT__waitbit;
    __Vdly__read__DOT__waitbit = 0;
    // Body
    __Vdly__read__DOT__waitbit = vlSelfRef.read__DOT__waitbit;
    __Vdly__read__DOT__Counter = vlSelfRef.read__DOT__Counter;
    __Vdly__read__DOT__State = vlSelfRef.read__DOT__State;
    __Vdly__read__DOT__Col = vlSelfRef.read__DOT__Col;
    if (vlSelfRef.Reset) {
        if ((2U & (IData)(vlSelfRef.read__DOT__State))) {
            if ((1U & (IData)(vlSelfRef.read__DOT__State))) {
                if (vlSelfRef.KeyRd) {
                    vlSelfRef.KeyRdy = 0U;
                    vlSelfRef.LFSRReset = 0U;
                    __Vdly__read__DOT__State = 0U;
                }
            } else if (vlSelfRef.read__DOT__ZeroChecker) {
                if (vlSelfRef.read__DOT__Sum) {
                    __Vdly__read__DOT__Counter = (7U 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.read__DOT__Counter)));
                    if ((4U == (IData)(vlSelfRef.read__DOT__Counter))) {
                        vlSelfRef.RowColVector = ((
                                                   (((((((0xfffeU 
                                                          == (IData)(vlSelfRef.read__DOT__Data)) 
                                                         | (0xfffdU 
                                                            == (IData)(vlSelfRef.read__DOT__Data))) 
                                                        | (0xfffbU 
                                                           == (IData)(vlSelfRef.read__DOT__Data))) 
                                                       | (0xfff7U 
                                                          == (IData)(vlSelfRef.read__DOT__Data))) 
                                                      | (0xffefU 
                                                         == (IData)(vlSelfRef.read__DOT__Data))) 
                                                     | (0xffdfU 
                                                        == (IData)(vlSelfRef.read__DOT__Data))) 
                                                    | (0xffbfU 
                                                       == (IData)(vlSelfRef.read__DOT__Data))) 
                                                   | (0xff7fU 
                                                      == (IData)(vlSelfRef.read__DOT__Data)))
                                                   ? 
                                                  ((0xfffeU 
                                                    == (IData)(vlSelfRef.read__DOT__Data))
                                                    ? 0U
                                                    : 
                                                   ((0xfffdU 
                                                     == (IData)(vlSelfRef.read__DOT__Data))
                                                     ? 4U
                                                     : 
                                                    ((0xfffbU 
                                                      == (IData)(vlSelfRef.read__DOT__Data))
                                                      ? 8U
                                                      : 
                                                     ((0xfff7U 
                                                       == (IData)(vlSelfRef.read__DOT__Data))
                                                       ? 0xcU
                                                       : 
                                                      ((0xffefU 
                                                        == (IData)(vlSelfRef.read__DOT__Data))
                                                        ? 1U
                                                        : 
                                                       ((0xffdfU 
                                                         == (IData)(vlSelfRef.read__DOT__Data))
                                                         ? 5U
                                                         : 
                                                        ((0xffbfU 
                                                          == (IData)(vlSelfRef.read__DOT__Data))
                                                          ? 9U
                                                          : 0xdU)))))))
                                                   : 
                                                  (((((((((0xfeffU 
                                                           == (IData)(vlSelfRef.read__DOT__Data)) 
                                                          | (0xfdffU 
                                                             == (IData)(vlSelfRef.read__DOT__Data))) 
                                                         | (0xfbffU 
                                                            == (IData)(vlSelfRef.read__DOT__Data))) 
                                                        | (0xf7ffU 
                                                           == (IData)(vlSelfRef.read__DOT__Data))) 
                                                       | (0xefffU 
                                                          == (IData)(vlSelfRef.read__DOT__Data))) 
                                                      | (0xdfffU 
                                                         == (IData)(vlSelfRef.read__DOT__Data))) 
                                                     | (0xbfffU 
                                                        == (IData)(vlSelfRef.read__DOT__Data))) 
                                                    | (0x7fffU 
                                                       == (IData)(vlSelfRef.read__DOT__Data)))
                                                    ? 
                                                   ((0xfeffU 
                                                     == (IData)(vlSelfRef.read__DOT__Data))
                                                     ? 2U
                                                     : 
                                                    ((0xfdffU 
                                                      == (IData)(vlSelfRef.read__DOT__Data))
                                                      ? 6U
                                                      : 
                                                     ((0xfbffU 
                                                       == (IData)(vlSelfRef.read__DOT__Data))
                                                       ? 0xaU
                                                       : 
                                                      ((0xf7ffU 
                                                        == (IData)(vlSelfRef.read__DOT__Data))
                                                        ? 0xeU
                                                        : 
                                                       ((0xefffU 
                                                         == (IData)(vlSelfRef.read__DOT__Data))
                                                         ? 3U
                                                         : 
                                                        ((0xdfffU 
                                                          == (IData)(vlSelfRef.read__DOT__Data))
                                                          ? 7U
                                                          : 
                                                         ((0xbfffU 
                                                           == (IData)(vlSelfRef.read__DOT__Data))
                                                           ? 0xbU
                                                           : 0xfU)))))))
                                                    : 0xdU));
                        vlSelfRef.KeyRdy = 1U;
                        __Vdly__read__DOT__State = 3U;
                        __Vdly__read__DOT__Counter = 0U;
                        vlSelfRef.read__DOT__ZeroChecker = 0U;
                    }
                } else {
                    vlSelfRef.read__DOT__ZeroChecker = 0U;
                    __Vdly__read__DOT__Counter = 0U;
                    __Vdly__read__DOT__State = 0U;
                }
            } else if (vlSelfRef.read__DOT__Sum) {
                __Vdly__read__DOT__State = 0U;
            } else {
                vlSelfRef.read__DOT__ZeroChecker = 1U;
                __Vdly__read__DOT__State = 0U;
            }
        } else if ((1U & (IData)(vlSelfRef.read__DOT__State))) {
            vlSelfRef.read__DOT__Sum = (1U & (~ (1U 
                                                 & VL_REDXOR_16(vlSelfRef.read__DOT__Data))));
            __Vdly__read__DOT__State = 2U;
        } else if (vlSelfRef.LFSRFlg) {
            if ((8U & (IData)(vlSelfRef.read__DOT__Col))) {
                if ((4U & (IData)(vlSelfRef.read__DOT__Col))) {
                    if ((2U & (IData)(vlSelfRef.read__DOT__Col))) {
                        if ((1U & (IData)(vlSelfRef.read__DOT__Col))) {
                            __Vdly__read__DOT__Col = 0xeU;
                            __Vdly__read__DOT__Counter = 0U;
                        } else if (vlSelfRef.read__DOT__waitbit) {
                            vlSelfRef.read__DOT__Data 
                                = ((0xfff0U & (IData)(vlSelfRef.read__DOT__Data)) 
                                   | (IData)(vlSelfRef.RowIn));
                            __Vdly__read__DOT__Col = 7U;
                            __Vdly__read__DOT__State = 1U;
                            __Vdly__read__DOT__waitbit = 0U;
                        } else {
                            __Vdly__read__DOT__waitbit = 1U;
                        }
                    } else if ((1U & (IData)(vlSelfRef.read__DOT__Col))) {
                        if (vlSelfRef.read__DOT__waitbit) {
                            vlSelfRef.read__DOT__Data 
                                = ((0xff0fU & (IData)(vlSelfRef.read__DOT__Data)) 
                                   | ((IData)(vlSelfRef.RowIn) 
                                      << 4U));
                            __Vdly__read__DOT__Col = 0xeU;
                            __Vdly__read__DOT__waitbit = 0U;
                        } else {
                            __Vdly__read__DOT__waitbit = 1U;
                        }
                    } else {
                        __Vdly__read__DOT__Col = 0xeU;
                        __Vdly__read__DOT__Counter = 0U;
                    }
                } else if ((2U & (IData)(vlSelfRef.read__DOT__Col))) {
                    if ((1U & (IData)(vlSelfRef.read__DOT__Col))) {
                        if (vlSelfRef.read__DOT__waitbit) {
                            vlSelfRef.read__DOT__Data 
                                = ((0xf0ffU & (IData)(vlSelfRef.read__DOT__Data)) 
                                   | ((IData)(vlSelfRef.RowIn) 
                                      << 8U));
                            __Vdly__read__DOT__Col = 0xdU;
                            __Vdly__read__DOT__waitbit = 0U;
                        } else {
                            __Vdly__read__DOT__waitbit = 1U;
                        }
                    } else {
                        __Vdly__read__DOT__Col = 0xeU;
                        __Vdly__read__DOT__Counter = 0U;
                    }
                } else {
                    __Vdly__read__DOT__Col = 0xeU;
                    __Vdly__read__DOT__Counter = 0U;
                }
            } else if ((4U & (IData)(vlSelfRef.read__DOT__Col))) {
                if ((2U & (IData)(vlSelfRef.read__DOT__Col))) {
                    if ((1U & (IData)(vlSelfRef.read__DOT__Col))) {
                        if (vlSelfRef.read__DOT__waitbit) {
                            vlSelfRef.read__DOT__Data 
                                = ((0xfffU & (IData)(vlSelfRef.read__DOT__Data)) 
                                   | ((IData)(vlSelfRef.RowIn) 
                                      << 0xcU));
                            __Vdly__read__DOT__Col = 0xbU;
                            __Vdly__read__DOT__waitbit = 0U;
                        } else {
                            __Vdly__read__DOT__waitbit = 1U;
                        }
                    } else {
                        __Vdly__read__DOT__Col = 0xeU;
                        __Vdly__read__DOT__Counter = 0U;
                    }
                } else {
                    __Vdly__read__DOT__Col = 0xeU;
                    __Vdly__read__DOT__Counter = 0U;
                }
            } else {
                __Vdly__read__DOT__Col = 0xeU;
                __Vdly__read__DOT__Counter = 0U;
            }
            vlSelfRef.LFSRReset = 0U;
        } else {
            vlSelfRef.LFSRReset = 1U;
        }
    } else {
        __Vdly__read__DOT__State = 0U;
        __Vdly__read__DOT__Col = 7U;
        vlSelfRef.LFSRReset = 0U;
        vlSelfRef.KeyRdy = 0U;
        vlSelfRef.RowColVector = 0xdU;
        __Vdly__read__DOT__Counter = 0U;
        vlSelfRef.read__DOT__Data = 0xffffU;
        vlSelfRef.read__DOT__Sum = 0U;
        vlSelfRef.read__DOT__ZeroChecker = 0U;
        __Vdly__read__DOT__waitbit = 0U;
    }
    vlSelfRef.read__DOT__State = __Vdly__read__DOT__State;
    vlSelfRef.read__DOT__Counter = __Vdly__read__DOT__Counter;
    vlSelfRef.read__DOT__waitbit = __Vdly__read__DOT__waitbit;
    vlSelfRef.read__DOT__Col = __Vdly__read__DOT__Col;
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

void Vread___024root___eval_triggers__act(Vread___024root* vlSelf);

bool Vread___024root___eval_phase__act(Vread___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vread__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vread___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vread___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vread___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vread___024root___eval_phase__nba(Vread___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vread__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vread___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vread___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vread___024root___dump_triggers__nba(Vread___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vread___024root___dump_triggers__act(Vread___024root* vlSelf);
#endif  // VL_DEBUG

void Vread___024root___eval(Vread___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vread__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vread___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vread___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("input.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vread___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("input.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vread___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vread___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vread___024root___eval_debug_assertions(Vread___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vread__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vread___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.Reset & 0xfeU))) {
        Verilated::overWidthError("Reset");}
    if (VL_UNLIKELY((vlSelfRef.Clock & 0xfeU))) {
        Verilated::overWidthError("Clock");}
    if (VL_UNLIKELY((vlSelfRef.RowIn & 0xf0U))) {
        Verilated::overWidthError("RowIn");}
    if (VL_UNLIKELY((vlSelfRef.LFSRFlg & 0xfeU))) {
        Verilated::overWidthError("LFSRFlg");}
    if (VL_UNLIKELY((vlSelfRef.KeyRd & 0xfeU))) {
        Verilated::overWidthError("KeyRd");}
}
#endif  // VL_DEBUG
