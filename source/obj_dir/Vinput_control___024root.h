// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vinput_control.h for the primary calling header

#ifndef VERILATED_VINPUT_CONTROL___024ROOT_H_
#define VERILATED_VINPUT_CONTROL___024ROOT_H_  // guard

#include "verilated.h"


class Vinput_control__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vinput_control___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(Reset,0,0);
    VL_IN8(Clock,0,0);
    VL_IN8(RowIn,3,0);
    VL_OUT8(ColOut,3,0);
    VL_OUT8(LFSRReset,0,0);
    VL_IN8(LFSRFlg,0,0);
    VL_OUT8(KeyRdy,0,0);
    VL_IN8(KeyRd,0,0);
    VL_OUT8(Number,3,0);
    VL_OUT8(Operator,2,0);
    VL_OUT8(EqualSign,0,0);
    CData/*1:0*/ input_control__DOT__State;
    CData/*2:0*/ input_control__DOT__Counter;
    CData/*3:0*/ input_control__DOT__Col;
    CData/*0:0*/ input_control__DOT__Sum;
    CData/*0:0*/ input_control__DOT__ZeroChecker;
    CData/*0:0*/ input_control__DOT__waitbit;
    CData/*3:0*/ input_control__DOT__ColOut__out__strong__out0;
    CData/*3:0*/ input_control__DOT__ColOut__out__strong__out1;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__Clock__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__Reset__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ input_control__DOT__Data;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vinput_control__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vinput_control___024root(Vinput_control__Syms* symsp, const char* v__name);
    ~Vinput_control___024root();
    VL_UNCOPYABLE(Vinput_control___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
