// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vgencon__pch.h"

//============================================================
// Constructors

Vgencon::Vgencon(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vgencon__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , keypad_input{vlSymsp->TOP.keypad_input}
    , operator_input{vlSymsp->TOP.operator_input}
    , equal_input{vlSymsp->TOP.equal_input}
    , complete{vlSymsp->TOP.complete}
    , start_calc{vlSymsp->TOP.start_calc}
    , ALU_finish{vlSymsp->TOP.ALU_finish}
    , we{vlSymsp->TOP.we}
    , oe{vlSymsp->TOP.oe}
    , mem_addr{vlSymsp->TOP.mem_addr}
    , display_output{vlSymsp->TOP.display_output}
    , ALU_in1{vlSymsp->TOP.ALU_in1}
    , ALU_in2{vlSymsp->TOP.ALU_in2}
    , ALU_out{vlSymsp->TOP.ALU_out}
    , mem_data{vlSymsp->TOP.mem_data}
    , data{vlSymsp->TOP.data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vgencon::Vgencon(const char* _vcname__)
    : Vgencon(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vgencon::~Vgencon() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vgencon___024root___eval_debug_assertions(Vgencon___024root* vlSelf);
#endif  // VL_DEBUG
void Vgencon___024root___eval_static(Vgencon___024root* vlSelf);
void Vgencon___024root___eval_initial(Vgencon___024root* vlSelf);
void Vgencon___024root___eval_settle(Vgencon___024root* vlSelf);
void Vgencon___024root___eval(Vgencon___024root* vlSelf);

void Vgencon::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vgencon::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vgencon___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vgencon___024root___eval_static(&(vlSymsp->TOP));
        Vgencon___024root___eval_initial(&(vlSymsp->TOP));
        Vgencon___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vgencon___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vgencon::eventsPending() { return false; }

uint64_t Vgencon::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vgencon::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vgencon___024root___eval_final(Vgencon___024root* vlSelf);

VL_ATTR_COLD void Vgencon::final() {
    Vgencon___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vgencon::hierName() const { return vlSymsp->name(); }
const char* Vgencon::modelName() const { return "Vgencon"; }
unsigned Vgencon::threads() const { return 1; }
void Vgencon::prepareClone() const { contextp()->prepareClone(); }
void Vgencon::atClone() const {
    contextp()->threadPoolpOnClone();
}
