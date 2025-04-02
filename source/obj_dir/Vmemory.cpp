// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmemory__pch.h"

//============================================================
// Constructors

Vmemory::Vmemory(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmemory__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , mem_addr{vlSymsp->TOP.mem_addr}
    , we{vlSymsp->TOP.we}
    , oe{vlSymsp->TOP.oe}
    , mem_data{vlSymsp->TOP.mem_data}
    , data{vlSymsp->TOP.data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmemory::Vmemory(const char* _vcname__)
    : Vmemory(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmemory::~Vmemory() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmemory___024root___eval_debug_assertions(Vmemory___024root* vlSelf);
#endif  // VL_DEBUG
void Vmemory___024root___eval_static(Vmemory___024root* vlSelf);
void Vmemory___024root___eval_initial(Vmemory___024root* vlSelf);
void Vmemory___024root___eval_settle(Vmemory___024root* vlSelf);
void Vmemory___024root___eval(Vmemory___024root* vlSelf);

void Vmemory::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmemory::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmemory___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmemory___024root___eval_static(&(vlSymsp->TOP));
        Vmemory___024root___eval_initial(&(vlSymsp->TOP));
        Vmemory___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmemory___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmemory::eventsPending() { return false; }

uint64_t Vmemory::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmemory::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmemory___024root___eval_final(Vmemory___024root* vlSelf);

VL_ATTR_COLD void Vmemory::final() {
    Vmemory___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmemory::hierName() const { return vlSymsp->name(); }
const char* Vmemory::modelName() const { return "Vmemory"; }
unsigned Vmemory::threads() const { return 1; }
void Vmemory::prepareClone() const { contextp()->prepareClone(); }
void Vmemory::atClone() const {
    contextp()->threadPoolpOnClone();
}
