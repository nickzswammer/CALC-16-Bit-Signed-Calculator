// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinput_control_inverse.h for the primary calling header

#include "Vinput_control_inverse__pch.h"
#include "Vinput_control_inverse___024root.h"

VL_ATTR_COLD void Vinput_control_inverse___024root___eval_static(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vinput_control_inverse___024root___eval_initial(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__nRST__0 = vlSelfRef.nRST;
}

VL_ATTR_COLD void Vinput_control_inverse___024root___eval_final(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput_control_inverse___024root___dump_triggers__stl(Vinput_control_inverse___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vinput_control_inverse___024root___eval_phase__stl(Vinput_control_inverse___024root* vlSelf);

VL_ATTR_COLD void Vinput_control_inverse___024root___eval_settle(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_settle\n"); );
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
            Vinput_control_inverse___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("input_control_inverse.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vinput_control_inverse___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput_control_inverse___024root___dump_triggers__stl(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___dump_triggers__stl\n"); );
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

VL_ATTR_COLD void Vinput_control_inverse___024root___stl_sequent__TOP__0(Vinput_control_inverse___024root* vlSelf);

VL_ATTR_COLD void Vinput_control_inverse___024root___eval_stl(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vinput_control_inverse___024root___stl_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*3:0*/, 16> Vinput_control_inverse__ConstPool__TABLE_hd7f945ba_0;
extern const VlUnpacked<CData/*2:0*/, 16> Vinput_control_inverse__ConstPool__TABLE_h8575d62c_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vinput_control_inverse__ConstPool__TABLE_h7a78fcbd_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vinput_control_inverse__ConstPool__TABLE_h567ddd7c_0;
extern const VlUnpacked<CData/*2:0*/, 512> Vinput_control_inverse__ConstPool__TABLE_hbedfc904_0;

VL_ATTR_COLD void Vinput_control_inverse___024root___stl_sequent__TOP__0(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    vlSelfRef.ColOut = 0U;
    vlSelfRef.ColOut = ((IData)(vlSelfRef.ColOut) | 
                        (0xfU & ((IData)(1U) << (IData)(vlSelfRef.input_inverse__DOT__col_index))));
    __Vtableidx3 = vlSelfRef.input_inverse__DOT__key_code;
    vlSelfRef.keypad_input = Vinput_control_inverse__ConstPool__TABLE_hd7f945ba_0
        [__Vtableidx3];
    vlSelfRef.operator_input = Vinput_control_inverse__ConstPool__TABLE_h8575d62c_0
        [__Vtableidx3];
    vlSelfRef.equal_input = Vinput_control_inverse__ConstPool__TABLE_h7a78fcbd_0
        [__Vtableidx3];
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

VL_ATTR_COLD void Vinput_control_inverse___024root___eval_triggers__stl(Vinput_control_inverse___024root* vlSelf);

VL_ATTR_COLD bool Vinput_control_inverse___024root___eval_phase__stl(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vinput_control_inverse___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vinput_control_inverse___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput_control_inverse___024root___dump_triggers__ico(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vinput_control_inverse___024root___dump_triggers__act(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge nRST)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinput_control_inverse___024root___dump_triggers__nba(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge nRST)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vinput_control_inverse___024root___ctor_var_reset(Vinput_control_inverse___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vinput_control_inverse__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinput_control_inverse___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->nRST = VL_RAND_RESET_I(1);
    vlSelf->RowIn = VL_RAND_RESET_I(4);
    vlSelf->ColOut = VL_RAND_RESET_I(4);
    vlSelf->read_input = VL_RAND_RESET_I(1);
    vlSelf->key_read = VL_RAND_RESET_I(1);
    vlSelf->keypad_input = VL_RAND_RESET_I(4);
    vlSelf->operator_input = VL_RAND_RESET_I(3);
    vlSelf->equal_input = VL_RAND_RESET_I(1);
    vlSelf->input_inverse__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->input_inverse__DOT__next_state = VL_RAND_RESET_I(3);
    vlSelf->input_inverse__DOT__col_index = VL_RAND_RESET_I(2);
    vlSelf->input_inverse__DOT__debounce_cnt = VL_RAND_RESET_I(4);
    vlSelf->input_inverse__DOT__key_code = VL_RAND_RESET_I(4);
    vlSelf->input_inverse__DOT__key_valid = VL_RAND_RESET_I(1);
    vlSelf->input_inverse__DOT__idx = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__nRST__0 = VL_RAND_RESET_I(1);
}
