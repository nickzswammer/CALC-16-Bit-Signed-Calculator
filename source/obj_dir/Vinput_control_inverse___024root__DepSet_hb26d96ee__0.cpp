// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinput_control_inverse.h for the primary calling header

#include "Vinput_control_inverse__pch.h"
#include "Vinput_control_inverse___024root.h"

void Vinput_control_inverse___024root___ico_sequent__TOP__0(Vinput_control_inverse___024root* vlSelf);

void Vinput_control_inverse___024root___eval_ico(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vinput_control_inverse___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*0:0*/, 16> Vinput_control_inverse__ConstPool__TABLE_h567ddd7c_0;
extern const VlUnpacked<CData/*2:0*/, 512> Vinput_control_inverse__ConstPool__TABLE_hbedfc904_0;

VL_INLINE_OPT void Vinput_control_inverse___024root___ico_sequent__TOP__0(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    __Vtableidx2 = vlSelfRef.RowIn;
    vlSelfRef.input_inverse__DOT__key_valid = Vinput_control_inverse__ConstPool__TABLE_h567ddd7c_0
        [__Vtableidx2];
    __Vtableidx1 = (((IData)(vlSelfRef.input_inverse__DOT__debounce_cnt) 
                     << 5U) | (((IData)(vlSelfRef.key_read) 
                                << 4U) | (((IData)(vlSelfRef.input_inverse__DOT__key_valid) 
                                           << 3U) | (IData)(vlSelfRef.input_inverse__DOT__state))));
    vlSelfRef.input_inverse__DOT__next_state = Vinput_control_inverse__ConstPool__TABLE_hbedfc904_0
        [__Vtableidx1];
}

void Vinput_control_inverse___024root___eval_triggers__ico(Vinput_control_inverse___024root* vlSelf);

bool Vinput_control_inverse___024root___eval_phase__ico(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vinput_control_inverse___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vinput_control_inverse___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vinput_control_inverse___024root___eval_act(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vinput_control_inverse___024root___nba_sequent__TOP__0(Vinput_control_inverse___024root* vlSelf);

void Vinput_control_inverse___024root___eval_nba(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vinput_control_inverse___024root___nba_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*3:0*/, 16> Vinput_control_inverse__ConstPool__TABLE_hd7f945ba_0;
extern const VlUnpacked<CData/*2:0*/, 16> Vinput_control_inverse__ConstPool__TABLE_h8575d62c_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vinput_control_inverse__ConstPool__TABLE_h7a78fcbd_0;

VL_INLINE_OPT void Vinput_control_inverse___024root___nba_sequent__TOP__0(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __Vfunc_input_inverse__DOT__encode_key__0__Vfuncout;
    __Vfunc_input_inverse__DOT__encode_key__0__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_input_inverse__DOT__encode_key__0__row;
    __Vfunc_input_inverse__DOT__encode_key__0__row = 0;
    CData/*1:0*/ __Vfunc_input_inverse__DOT__encode_key__0__col;
    __Vfunc_input_inverse__DOT__encode_key__0__col = 0;
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*2:0*/ __Vdly__input_inverse__DOT__state;
    __Vdly__input_inverse__DOT__state = 0;
    CData/*1:0*/ __Vdly__input_inverse__DOT__col_index;
    __Vdly__input_inverse__DOT__col_index = 0;
    // Body
    __Vdly__input_inverse__DOT__col_index = vlSelfRef.input_inverse__DOT__col_index;
    __Vdly__input_inverse__DOT__state = vlSelfRef.input_inverse__DOT__state;
    if (vlSelfRef.nRST) {
        __Vdly__input_inverse__DOT__state = vlSelfRef.input_inverse__DOT__next_state;
        if (((1U == (IData)(vlSelfRef.input_inverse__DOT__state)) 
             & (1U == (IData)(vlSelfRef.input_inverse__DOT__next_state)))) {
            __Vdly__input_inverse__DOT__col_index = 
                ((3U == (IData)(vlSelfRef.input_inverse__DOT__col_index))
                  ? 0U : (3U & ((IData)(1U) + (IData)(vlSelfRef.input_inverse__DOT__col_index))));
        }
        if ((2U == (IData)(vlSelfRef.input_inverse__DOT__state))) {
            vlSelfRef.input_inverse__DOT__debounce_cnt 
                = ((IData)(vlSelfRef.input_inverse__DOT__key_valid)
                    ? (0xfU & ((IData)(1U) + (IData)(vlSelfRef.input_inverse__DOT__debounce_cnt)))
                    : 0U);
        }
        if (((3U == (IData)(vlSelfRef.input_inverse__DOT__state)) 
             & (~ (IData)(vlSelfRef.read_input)))) {
            vlSelfRef.read_input = 1U;
            __Vfunc_input_inverse__DOT__encode_key__0__col 
                = vlSelfRef.input_inverse__DOT__col_index;
            __Vfunc_input_inverse__DOT__encode_key__0__row 
                = vlSelfRef.RowIn;
            {
                if ((1U & (IData)(__Vfunc_input_inverse__DOT__encode_key__0__row))) {
                    vlSelfRef.input_inverse__DOT__idx 
                        = __Vfunc_input_inverse__DOT__encode_key__0__col;
                    __Vfunc_input_inverse__DOT__encode_key__0__Vfuncout 
                        = (0xfU & vlSelfRef.input_inverse__DOT__idx);
                    goto __Vlabel1;
                }
                if ((2U & (IData)(__Vfunc_input_inverse__DOT__encode_key__0__row))) {
                    vlSelfRef.input_inverse__DOT__idx 
                        = ((IData)(4U) + (IData)(__Vfunc_input_inverse__DOT__encode_key__0__col));
                    __Vfunc_input_inverse__DOT__encode_key__0__Vfuncout 
                        = (0xfU & vlSelfRef.input_inverse__DOT__idx);
                    goto __Vlabel1;
                }
                if ((4U & (IData)(__Vfunc_input_inverse__DOT__encode_key__0__row))) {
                    vlSelfRef.input_inverse__DOT__idx 
                        = ((IData)(8U) + (IData)(__Vfunc_input_inverse__DOT__encode_key__0__col));
                    __Vfunc_input_inverse__DOT__encode_key__0__Vfuncout 
                        = (0xfU & vlSelfRef.input_inverse__DOT__idx);
                    goto __Vlabel1;
                }
                if ((8U & (IData)(__Vfunc_input_inverse__DOT__encode_key__0__row))) {
                    vlSelfRef.input_inverse__DOT__idx 
                        = ((IData)(0xcU) + (IData)(__Vfunc_input_inverse__DOT__encode_key__0__col));
                    __Vfunc_input_inverse__DOT__encode_key__0__Vfuncout 
                        = (0xfU & vlSelfRef.input_inverse__DOT__idx);
                    goto __Vlabel1;
                }
                __Vfunc_input_inverse__DOT__encode_key__0__Vfuncout = 0xeU;
                __Vlabel1: ;
            }
            vlSelfRef.input_inverse__DOT__key_code 
                = __Vfunc_input_inverse__DOT__encode_key__0__Vfuncout;
        }
        if (((4U == (IData)(vlSelfRef.input_inverse__DOT__state)) 
             & (~ (IData)(vlSelfRef.input_inverse__DOT__key_valid)))) {
            vlSelfRef.read_input = 0U;
        }
    } else {
        __Vdly__input_inverse__DOT__state = 0U;
        __Vdly__input_inverse__DOT__col_index = 0U;
        vlSelfRef.input_inverse__DOT__debounce_cnt = 0U;
        vlSelfRef.read_input = 0U;
    }
    vlSelfRef.input_inverse__DOT__col_index = __Vdly__input_inverse__DOT__col_index;
    vlSelfRef.input_inverse__DOT__state = __Vdly__input_inverse__DOT__state;
    vlSelfRef.ColOut = 0U;
    vlSelfRef.ColOut = ((IData)(vlSelfRef.ColOut) | 
                        (0xfU & ((IData)(1U) << (IData)(vlSelfRef.input_inverse__DOT__col_index))));
    __Vtableidx1 = (((IData)(vlSelfRef.input_inverse__DOT__debounce_cnt) 
                     << 5U) | (((IData)(vlSelfRef.key_read) 
                                << 4U) | (((IData)(vlSelfRef.input_inverse__DOT__key_valid) 
                                           << 3U) | (IData)(vlSelfRef.input_inverse__DOT__state))));
    vlSelfRef.input_inverse__DOT__next_state = Vinput_control_inverse__ConstPool__TABLE_hbedfc904_0
        [__Vtableidx1];
    __Vtableidx3 = vlSelfRef.input_inverse__DOT__key_code;
    vlSelfRef.keypad_input = Vinput_control_inverse__ConstPool__TABLE_hd7f945ba_0
        [__Vtableidx3];
    vlSelfRef.operator_input = Vinput_control_inverse__ConstPool__TABLE_h8575d62c_0
        [__Vtableidx3];
    vlSelfRef.equal_input = Vinput_control_inverse__ConstPool__TABLE_h7a78fcbd_0
        [__Vtableidx3];
}

void Vinput_control_inverse___024root___eval_triggers__act(Vinput_control_inverse___024root* vlSelf);

bool Vinput_control_inverse___024root___eval_phase__act(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vinput_control_inverse___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vinput_control_inverse___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vinput_control_inverse___024root___eval_phase__nba(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vinput_control_inverse___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput_control_inverse___024root___dump_triggers__ico(Vinput_control_inverse___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput_control_inverse___024root___dump_triggers__nba(Vinput_control_inverse___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput_control_inverse___024root___dump_triggers__act(Vinput_control_inverse___024root* vlSelf);
#endif  // VL_DEBUG

void Vinput_control_inverse___024root___eval(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval\n"); );
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
            Vinput_control_inverse___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("input_control_inverse.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vinput_control_inverse___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vinput_control_inverse___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("input_control_inverse.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vinput_control_inverse___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("input_control_inverse.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vinput_control_inverse___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vinput_control_inverse___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vinput_control_inverse___024root___eval_debug_assertions(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.nRST & 0xfeU))) {
        Verilated::overWidthError("nRST");}
    if (VL_UNLIKELY((vlSelfRef.RowIn & 0xf0U))) {
        Verilated::overWidthError("RowIn");}
    if (VL_UNLIKELY((vlSelfRef.key_read & 0xfeU))) {
        Verilated::overWidthError("key_read");}
}
#endif  // VL_DEBUG
