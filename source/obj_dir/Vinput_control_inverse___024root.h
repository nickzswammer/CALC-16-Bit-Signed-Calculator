// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vinput_control_inverse.h for the primary calling header

#ifndef VERILATED_VINPUT_CONTROL_INVERSE___024ROOT_H_
#define VERILATED_VINPUT_CONTROL_INVERSE___024ROOT_H_  // guard

#include "verilated.h"


class Vinput_control_inverse__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vinput_control_inverse___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(nRST,0,0);
    VL_IN8(RowIn,3,0);
    VL_OUT8(ColOut,3,0);
    VL_OUT8(read_input,0,0);
    VL_IN8(key_read,0,0);
    VL_OUT8(keypad_input,3,0);
    VL_OUT8(operator_input,2,0);
    VL_OUT8(equal_input,0,0);
    CData/*2:0*/ input_inverse__DOT__state;
    CData/*2:0*/ input_inverse__DOT__next_state;
    CData/*1:0*/ input_inverse__DOT__col_index;
    CData/*3:0*/ input_inverse__DOT__debounce_cnt;
    CData/*3:0*/ input_inverse__DOT__key_code;
    CData/*0:0*/ input_inverse__DOT__key_valid;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__nRST__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ input_inverse__DOT__idx;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vinput_control_inverse__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vinput_control_inverse___024root(Vinput_control_inverse__Syms* symsp, const char* v__name);
    ~Vinput_control_inverse___024root();
    VL_UNCOPYABLE(Vinput_control_inverse___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
