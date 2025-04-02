// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmemory.h for the primary calling header

#ifndef VERILATED_VMEMORY___024ROOT_H_
#define VERILATED_VMEMORY___024ROOT_H_  // guard

#include "verilated.h"


class Vmemory__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmemory___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(mem_addr,3,0);
    VL_IN8(we,0,0);
    VL_IN8(oe,0,0);
    CData/*0:0*/ memory__DOT____VdfgRegularize_h192772c8_0_0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(mem_data,15,0);
    VL_OUT16(data,15,0);
    SData/*15:0*/ memory__DOT__tmp_data;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 16> memory__DOT__mem;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmemory__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmemory___024root(Vmemory__Syms* symsp, const char* v__name);
    ~Vmemory___024root();
    VL_UNCOPYABLE(Vmemory___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
