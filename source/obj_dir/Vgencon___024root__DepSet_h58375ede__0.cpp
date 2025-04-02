// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgencon.h for the primary calling header

#include "Vgencon__pch.h"
#include "Vgencon___024root.h"

void Vgencon___024root___ico_sequent__TOP__0(Vgencon___024root* vlSelf);

void Vgencon___024root___eval_ico(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vgencon___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*2:0*/, 64> Vgencon__ConstPool__TABLE_hd3087ef2_0;

VL_INLINE_OPT void Vgencon___024root___ico_sequent__TOP__0(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = ((((~ (IData)(vlSelfRef.gencon__DOT__prev_operator)) 
                      & (IData)(vlSelfRef.operator_input)) 
                     << 5U) | ((((~ (IData)(vlSelfRef.gencon__DOT__prev_equal)) 
                                 & (IData)(vlSelfRef.equal_input)) 
                                << 4U) | (((IData)(vlSelfRef.ALU_finish) 
                                           << 3U) | (IData)(vlSelfRef.gencon__DOT__current_state))));
    vlSelfRef.gencon__DOT__next_state = Vgencon__ConstPool__TABLE_hd3087ef2_0
        [__Vtableidx1];
}

void Vgencon___024root___eval_triggers__ico(Vgencon___024root* vlSelf);

bool Vgencon___024root___eval_phase__ico(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vgencon___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vgencon___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vgencon___024root___act_sequent__TOP__0(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__1(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__2(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__3(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__4(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__5(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__6(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__7(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__8(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__9(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__10(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__11(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__12(Vgencon___024root* vlSelf);
void Vgencon___024root___act_sequent__TOP__13(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__0(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__1(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__2(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__3(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__4(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__5(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__6(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__7(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__8(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__9(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__10(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__11(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__12(Vgencon___024root* vlSelf);
void Vgencon___024root___act_comb__TOP__13(Vgencon___024root* vlSelf);

void Vgencon___024root___eval_act(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__3(vlSelf);
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__4(vlSelf);
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__5(vlSelf);
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__6(vlSelf);
    }
    if ((0x200ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__7(vlSelf);
    }
    if ((0x400ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__8(vlSelf);
    }
    if ((0x800ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__9(vlSelf);
    }
    if ((0x1000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__10(vlSelf);
    }
    if ((0x2000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__11(vlSelf);
    }
    if ((0x4000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__12(vlSelf);
    }
    if ((0x8000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__13(vlSelf);
    }
    if ((0x8002ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__0(vlSelf);
    }
    if ((0xc002ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__1(vlSelf);
    }
    if ((0xe002ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__2(vlSelf);
    }
    if ((0xf002ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__3(vlSelf);
    }
    if ((0xf802ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__4(vlSelf);
    }
    if ((0xfc02ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__5(vlSelf);
    }
    if ((0xfe02ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__6(vlSelf);
    }
    if ((0xff02ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__7(vlSelf);
    }
    if ((0xff82ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__8(vlSelf);
    }
    if ((0xffc2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__9(vlSelf);
    }
    if ((0xffe2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__10(vlSelf);
    }
    if ((0xfff2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__11(vlSelf);
    }
    if ((0xfffaULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__12(vlSelf);
    }
    if ((0xffffULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__13(vlSelf);
    }
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__0(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 0xeU) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__14__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__14__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 0xeU))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1 
        = (IData)(((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                     >> 0xeU) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2)) 
                   ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__14__KET____DOT__thingy____pinNumber4)));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__1(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 0xdU) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__13__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__13__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 0xdU))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 0xdU) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2) 
                              ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__13__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__2(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 0xcU) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__12__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__12__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 0xcU))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 0xcU) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2) 
                              ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__12__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__3(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 0xbU) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__11__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__11__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 0xbU))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 0xbU) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2) 
                              ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__11__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__4(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 0xaU) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__10__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__10__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 0xaU))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 0xaU) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2) 
                              ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__10__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__5(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__5\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 9U) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__9__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__9__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 9U))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 9U) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2) 
                            ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__9__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__6(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__6\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 8U) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__8__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__8__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 8U))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 8U) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2) 
                            ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__8__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__7(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__7\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 7U) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 7U))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 7U) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2) 
                            ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__8(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__8\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 6U) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 6U))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 6U) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2) 
                            ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__9(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__9\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 5U) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 5U))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 5U) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2) 
                            ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__10(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__10\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 4U) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 4U))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 4U) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2) 
                            ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__11(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__11\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 3U) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 3U))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 3U) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2) 
                            ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__12(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__12\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 2U) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 2U))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 2U) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2) 
                            ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_sequent__TOP__13(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_sequent__TOP__13\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2 
        = ((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
             >> 1U) & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__thingy____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__a0____pinNumber2) 
              & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__thingy____pinNumber4) 
                 | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                    >> 1U))));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber1 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                  >> 1U) ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__a0____pinNumber2) 
                            ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__thingy____pinNumber4))));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__0(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2 
        = (1U & ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber1)) 
                 & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1))));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__1(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2 
        = ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber1)) 
           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__2(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2 
        = ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber1)) 
           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__3(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2 
        = ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber1)) 
           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__4(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2 
        = ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber1)) 
           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__5(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__5\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2 
        = ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber1)) 
           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__6(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__6\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2 
        = ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber1)) 
           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__7(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__7\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2 
        = ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber1)) 
           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__8(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__8\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2 
        = ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber1)) 
           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__9(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__9\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2 
        = ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber1)) 
           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__10(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__10\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2 
        = ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber1)) 
           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__11(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__11\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2 
        = ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber1)) 
           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__12(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__12\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2 
        = ((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1)) 
           & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2));
}

VL_INLINE_OPT void Vgencon___024root___act_comb__TOP__13(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___act_comb__TOP__13\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__a0____pinNumber4;
    gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__a0____pinNumber4 = 0;
    // Body
    if ((1U == (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__state))) {
        if ((0x8000U & ((IData)(vlSelfRef.ALU_in1) 
                        ^ (IData)(vlSelfRef.ALU_in2)))) {
            vlSelfRef.gencon__DOT__add_calc__DOT__diffSign = 1U;
        } else {
            vlSelfRef.gencon__DOT__add_calc__DOT__diffSign = 0U;
            vlSelfRef.gencon__DOT__add_calc__DOT__sameSignVal 
                = (1U & ((IData)(vlSelfRef.ALU_in1) 
                         >> 0xfU));
        }
    } else if ((2U == (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__state))) {
        vlSelfRef.ALU_out = (((~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber2)) 
                              & (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign))
                              ? (0x8000U | ((0x4000U 
                                             ^ (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1) 
                                                 ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2)) 
                                                << 0xeU)) 
                                            | ((0x2000U 
                                                ^ (
                                                   ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1) 
                                                    ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2)) 
                                                   << 0xdU)) 
                                               | ((0x1000U 
                                                   ^ 
                                                   (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber1) 
                                                     ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2)) 
                                                    << 0xcU)) 
                                                  | ((0x800U 
                                                      ^ 
                                                      (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber1) 
                                                        ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2)) 
                                                       << 0xbU)) 
                                                     | ((0x400U 
                                                         ^ 
                                                         (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber1) 
                                                           ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2)) 
                                                          << 0xaU)) 
                                                        | ((0x200U 
                                                            ^ 
                                                            (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber1) 
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
                                                                                | (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1))))))))))))))))
                              : ((((1U & (~ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign))) 
                                   && (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__sameSignVal)) 
                                  << 0xfU) | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1) 
                                               << 0xeU) 
                                              | (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1) 
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
                                                                                | (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1)))))))))))))))));
    }
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 1U) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 2U) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 3U) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 4U) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 5U) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 6U) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 7U) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__8__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 8U) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__9__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 9U) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__10__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 0xaU) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__11__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 0xbU) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__12__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 0xcU) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__13__KET____DOT__thingy____pinNumber4 
        = (1U & (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                  >> 0xdU) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__14__KET____DOT__thingy____pinNumber4 
        = (IData)((((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                    >> 0xeU) ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__a0____pinNumber4 
        = (1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n2) 
                 ^ (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign)));
    vlSelfRef.gencon__DOT__add_calc__DOT__main__DOT____Vcellout__a0____pinNumber2 
        = (((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
            & (IData)(gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__a0____pinNumber4)) 
           | ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign) 
              & ((IData)(gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__a0____pinNumber4) 
                 | (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1))));
    vlSelfRef.gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1 
        = (1U & ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__n1) 
                 ^ ((IData)(vlSelfRef.gencon__DOT__add_calc__DOT__diffSign) 
                    ^ (IData)(gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__a0____pinNumber4))));
}

void Vgencon___024root___nba_sequent__TOP__0(Vgencon___024root* vlSelf);

void Vgencon___024root___eval_nba(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x10000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x10004ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((0x10008ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((0x10010ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((0x10020ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__3(vlSelf);
    }
    if ((0x10040ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__4(vlSelf);
    }
    if ((0x10080ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__5(vlSelf);
    }
    if ((0x10100ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__6(vlSelf);
    }
    if ((0x10200ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__7(vlSelf);
    }
    if ((0x10400ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__8(vlSelf);
    }
    if ((0x10800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__9(vlSelf);
    }
    if ((0x11000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__10(vlSelf);
    }
    if ((0x12000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__11(vlSelf);
    }
    if ((0x14000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__12(vlSelf);
    }
    if ((0x18000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_sequent__TOP__13(vlSelf);
    }
    if ((0x18002ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__0(vlSelf);
    }
    if ((0x1c002ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__1(vlSelf);
    }
    if ((0x1e002ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__2(vlSelf);
    }
    if ((0x1f002ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__3(vlSelf);
    }
    if ((0x1f802ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__4(vlSelf);
    }
    if ((0x1fc02ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__5(vlSelf);
    }
    if ((0x1fe02ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__6(vlSelf);
    }
    if ((0x1ff02ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__7(vlSelf);
    }
    if ((0x1ff82ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__8(vlSelf);
    }
    if ((0x1ffc2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__9(vlSelf);
    }
    if ((0x1ffe2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__10(vlSelf);
    }
    if ((0x1fff2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__11(vlSelf);
    }
    if ((0x1fffaULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__12(vlSelf);
    }
    if ((0x1ffffULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vgencon___024root___act_comb__TOP__13(vlSelf);
    }
}

extern const VlUnpacked<CData/*2:0*/, 16> Vgencon__ConstPool__TABLE_heec4b55b_0;

VL_INLINE_OPT void Vgencon___024root___nba_sequent__TOP__0(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    SData/*15:0*/ __Vdly__gencon__DOT__operand1;
    __Vdly__gencon__DOT__operand1 = 0;
    SData/*15:0*/ __Vdly__gencon__DOT__operand2;
    __Vdly__gencon__DOT__operand2 = 0;
    // Body
    __Vdly__gencon__DOT__operand2 = vlSelfRef.gencon__DOT__operand2;
    __Vdly__gencon__DOT__operand1 = vlSelfRef.gencon__DOT__operand1;
    vlSelfRef.oe = 0U;
    vlSelfRef.gencon__DOT__prev_equal = ((1U & (~ (IData)(vlSelfRef.reset))) 
                                         && (IData)(vlSelfRef.equal_input));
    vlSelfRef.gencon__DOT__prev_operator = ((1U & (~ (IData)(vlSelfRef.reset))) 
                                            && (IData)(vlSelfRef.operator_input));
    if (vlSelfRef.reset) {
        vlSelfRef.complete = 0U;
        vlSelfRef.we = 0U;
        vlSelfRef.mem_addr = 0U;
        vlSelfRef.start_calc = 0U;
        vlSelfRef.display_output = 0U;
        vlSelfRef.gencon__DOT__add_calc__DOT__state = 0U;
        __Vdly__gencon__DOT__operand1 = 0U;
        __Vdly__gencon__DOT__operand2 = 0U;
        vlSelfRef.mem_data = 0U;
        vlSelfRef.ALU_in1 = 0U;
        vlSelfRef.ALU_in2 = 0U;
        vlSelfRef.gencon__DOT__current_state = 0U;
    } else {
        vlSelfRef.complete = 0U;
        vlSelfRef.we = 0U;
        if ((0U == (IData)(vlSelfRef.gencon__DOT__current_state))) {
            if ((0U != (IData)(vlSelfRef.keypad_input))) {
                vlSelfRef.we = 1U;
                vlSelfRef.mem_addr = 0U;
                __Vdly__gencon__DOT__operand1 = (0xffffU 
                                                 & (((IData)(0xaU) 
                                                     * (IData)(vlSelfRef.gencon__DOT__operand1)) 
                                                    + (IData)(vlSelfRef.keypad_input)));
                vlSelfRef.mem_data = (0xffffU & (((IData)(0xaU) 
                                                  * (IData)(vlSelfRef.gencon__DOT__operand1)) 
                                                 + (IData)(vlSelfRef.keypad_input)));
            }
        } else if ((1U == (IData)(vlSelfRef.gencon__DOT__current_state))) {
            if ((0U != (IData)(vlSelfRef.keypad_input))) {
                vlSelfRef.we = 1U;
                vlSelfRef.mem_addr = 1U;
                __Vdly__gencon__DOT__operand2 = (0xffffU 
                                                 & (((IData)(0xaU) 
                                                     * (IData)(vlSelfRef.gencon__DOT__operand2)) 
                                                    + (IData)(vlSelfRef.keypad_input)));
                vlSelfRef.mem_data = (0xffffU & (((IData)(0xaU) 
                                                  * (IData)(vlSelfRef.gencon__DOT__operand2)) 
                                                 + (IData)(vlSelfRef.keypad_input)));
            }
        } else {
            if ((2U != (IData)(vlSelfRef.gencon__DOT__current_state))) {
                if ((3U != (IData)(vlSelfRef.gencon__DOT__current_state))) {
                    if ((4U == (IData)(vlSelfRef.gencon__DOT__current_state))) {
                        vlSelfRef.we = 1U;
                        vlSelfRef.mem_addr = 2U;
                    }
                }
            }
            if ((2U == (IData)(vlSelfRef.gencon__DOT__current_state))) {
                vlSelfRef.ALU_in1 = vlSelfRef.gencon__DOT__operand1;
                vlSelfRef.ALU_in2 = vlSelfRef.gencon__DOT__operand2;
            } else if ((3U != (IData)(vlSelfRef.gencon__DOT__current_state))) {
                if ((4U == (IData)(vlSelfRef.gencon__DOT__current_state))) {
                    vlSelfRef.mem_data = vlSelfRef.ALU_out;
                    __Vdly__gencon__DOT__operand1 = 0U;
                    __Vdly__gencon__DOT__operand2 = 0U;
                }
            }
        }
        vlSelfRef.start_calc = 0U;
        if ((0U != (IData)(vlSelfRef.gencon__DOT__current_state))) {
            if ((1U != (IData)(vlSelfRef.gencon__DOT__current_state))) {
                if ((2U != (IData)(vlSelfRef.gencon__DOT__current_state))) {
                    if ((3U != (IData)(vlSelfRef.gencon__DOT__current_state))) {
                        if ((4U == (IData)(vlSelfRef.gencon__DOT__current_state))) {
                            vlSelfRef.complete = 1U;
                            vlSelfRef.display_output 
                                = vlSelfRef.ALU_out;
                        }
                    }
                }
                if ((2U == (IData)(vlSelfRef.gencon__DOT__current_state))) {
                    vlSelfRef.start_calc = 1U;
                } else if ((3U == (IData)(vlSelfRef.gencon__DOT__current_state))) {
                    vlSelfRef.start_calc = 0U;
                }
            }
        }
        vlSelfRef.gencon__DOT__add_calc__DOT__state 
            = vlSelfRef.gencon__DOT__add_calc__DOT__next;
        vlSelfRef.gencon__DOT__current_state = vlSelfRef.gencon__DOT__next_state;
    }
    vlSelfRef.gencon__DOT__operand1 = __Vdly__gencon__DOT__operand1;
    vlSelfRef.gencon__DOT__operand2 = __Vdly__gencon__DOT__operand2;
    __Vtableidx2 = (((IData)(vlSelfRef.start_calc) 
                     << 3U) | (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__state));
    vlSelfRef.gencon__DOT__add_calc__DOT__next = Vgencon__ConstPool__TABLE_heec4b55b_0
        [__Vtableidx2];
    vlSelfRef.ALU_finish = 0U;
    if ((1U != (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__state))) {
        if ((2U != (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__state))) {
            vlSelfRef.ALU_finish = (3U == (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__state));
        }
    }
    if ((1U == (IData)(vlSelfRef.gencon__DOT__add_calc__DOT__state))) {
        if ((0x8000U & ((IData)(vlSelfRef.ALU_in1) 
                        ^ (IData)(vlSelfRef.ALU_in2)))) {
            if ((0x8000U & (IData)(vlSelfRef.ALU_in1))) {
                vlSelfRef.gencon__DOT__add_calc__DOT__n2 
                    = (0x7fffU & (IData)(vlSelfRef.ALU_in1));
                vlSelfRef.gencon__DOT__add_calc__DOT__n1 
                    = (0x7fffU & (IData)(vlSelfRef.ALU_in2));
            } else {
                vlSelfRef.gencon__DOT__add_calc__DOT__n2 
                    = (0x7fffU & (IData)(vlSelfRef.ALU_in2));
                vlSelfRef.gencon__DOT__add_calc__DOT__n1 
                    = (0x7fffU & (IData)(vlSelfRef.ALU_in1));
            }
        } else {
            vlSelfRef.gencon__DOT__add_calc__DOT__n2 
                = (0x7fffU & (IData)(vlSelfRef.ALU_in2));
            vlSelfRef.gencon__DOT__add_calc__DOT__n1 
                = (0x7fffU & (IData)(vlSelfRef.ALU_in1));
        }
    }
    __Vtableidx1 = ((((~ (IData)(vlSelfRef.gencon__DOT__prev_operator)) 
                      & (IData)(vlSelfRef.operator_input)) 
                     << 5U) | ((((~ (IData)(vlSelfRef.gencon__DOT__prev_equal)) 
                                 & (IData)(vlSelfRef.equal_input)) 
                                << 4U) | (((IData)(vlSelfRef.ALU_finish) 
                                           << 3U) | (IData)(vlSelfRef.gencon__DOT__current_state))));
    vlSelfRef.gencon__DOT__next_state = Vgencon__ConstPool__TABLE_hd3087ef2_0
        [__Vtableidx1];
}

void Vgencon___024root___eval_triggers__act(Vgencon___024root* vlSelf);

bool Vgencon___024root___eval_phase__act(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<17> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vgencon___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vgencon___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vgencon___024root___eval_phase__nba(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vgencon___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vgencon___024root___dump_triggers__ico(Vgencon___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vgencon___024root___dump_triggers__nba(Vgencon___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vgencon___024root___dump_triggers__act(Vgencon___024root* vlSelf);
#endif  // VL_DEBUG

void Vgencon___024root___eval(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___eval\n"); );
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
            Vgencon___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("gencon.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vgencon___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vgencon___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("gencon.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vgencon___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("gencon.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vgencon___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vgencon___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vgencon___024root___eval_debug_assertions(Vgencon___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vgencon__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgencon___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelfRef.keypad_input & 0xf0U))) {
        Verilated::overWidthError("keypad_input");}
    if (VL_UNLIKELY((vlSelfRef.operator_input & 0xfeU))) {
        Verilated::overWidthError("operator_input");}
    if (VL_UNLIKELY((vlSelfRef.equal_input & 0xfeU))) {
        Verilated::overWidthError("equal_input");}
    if (VL_UNLIKELY((vlSelfRef.__pinNumber17 & 0xfeU))) {
        Verilated::overWidthError("__pinNumber17");}
}
#endif  // VL_DEBUG
