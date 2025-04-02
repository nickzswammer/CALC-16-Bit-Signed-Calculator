// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vgencon.h for the primary calling header

#ifndef VERILATED_VGENCON___024ROOT_H_
#define VERILATED_VGENCON___024ROOT_H_  // guard

#include "verilated.h"


class Vgencon__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vgencon___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(keypad_input,3,0);
        VL_IN8(operator_input,0,0);
        VL_IN8(equal_input,0,0);
        VL_OUT8(complete,0,0);
        VL_OUT8(start_calc,0,0);
        VL_OUT8(ALU_finish,0,0);
        VL_OUT8(we,0,0);
        VL_OUT8(oe,0,0);
        VL_OUT8(mem_addr,3,0);
        VL_IN8(__pinNumber17,0,0);
        CData/*2:0*/ gencon__DOT__current_state;
        CData/*2:0*/ gencon__DOT__next_state;
        CData/*0:0*/ gencon__DOT__prev_operator;
        CData/*0:0*/ gencon__DOT__prev_equal;
        CData/*2:0*/ gencon__DOT__add_calc__DOT__state;
        CData/*2:0*/ gencon__DOT__add_calc__DOT__next;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__diffSign;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__sameSignVal;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__a0____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__8__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__9__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__10__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__11__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__12__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__13__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__14__KET____DOT__thingy____pinNumber4;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber1;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1;
    };
    struct {
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__14__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__13__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__12__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__11__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__10__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__9__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__8__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__a0____pinNumber2__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__thingy____pinNumber4__0;
        CData/*0:0*/ __VstlDidInit;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__14__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__complement__DOT____Vcellout__a0____pinNumber1__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__13__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__14__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__12__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__13__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__11__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__12__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__10__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__11__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__9__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__10__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__8__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__9__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__7__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__8__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__6__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__thingy____pinNumber4__1;
    };
    struct {
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__5__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__4__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__3__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__2__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__genblk1__BRA__1__KET____DOT__thingy____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellout__a0____pinNumber2__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__gencon__DOT__add_calc__DOT__main__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__thingy____pinNumber4__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        VL_OUT16(display_output,15,0);
        VL_OUT16(ALU_in1,15,0);
        VL_OUT16(ALU_in2,15,0);
        VL_OUT16(ALU_out,15,0);
        VL_OUT16(mem_data,15,0);
        SData/*15:0*/ gencon__DOT__operand1;
        SData/*15:0*/ gencon__DOT__operand2;
        SData/*14:0*/ gencon__DOT__add_calc__DOT__n1;
        SData/*14:0*/ gencon__DOT__add_calc__DOT__n2;
        IData/*31:0*/ __VactIterCount;
    };
    VlTriggerVec<17> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<17> __VactTriggered;
    VlTriggerVec<17> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vgencon__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vgencon___024root(Vgencon__Syms* symsp, const char* v__name);
    ~Vgencon___024root();
    VL_UNCOPYABLE(Vgencon___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
