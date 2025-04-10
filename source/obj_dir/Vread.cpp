// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vread__pch.h"

//============================================================
// Constructors

Vread::Vread(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vread__Syms(contextp(), _vcname__, this)}
    , Reset{vlSymsp->TOP.Reset}
    , Clock{vlSymsp->TOP.Clock}
    , RowIn{vlSymsp->TOP.RowIn}
    , ColOut{vlSymsp->TOP.ColOut}
    , LFSRReset{vlSymsp->TOP.LFSRReset}
    , LFSRFlg{vlSymsp->TOP.LFSRFlg}
    , RowColVector{vlSymsp->TOP.RowColVector}
    , KeyRdy{vlSymsp->TOP.KeyRdy}
    , KeyRd{vlSymsp->TOP.KeyRd}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vread::Vread(const char* _vcname__)
    : Vread(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vread::~Vread() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vread___024root___eval_debug_assertions(Vread___024root* vlSelf);
#endif  // VL_DEBUG
void Vread___024root___eval_static(Vread___024root* vlSelf);
void Vread___024root___eval_initial(Vread___024root* vlSelf);
void Vread___024root___eval_settle(Vread___024root* vlSelf);
void Vread___024root___eval(Vread___024root* vlSelf);

void Vread::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vread::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vread___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vread___024root___eval_static(&(vlSymsp->TOP));
        Vread___024root___eval_initial(&(vlSymsp->TOP));
        Vread___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vread___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vread::eventsPending() { return false; }

uint64_t Vread::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vread::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vread___024root___eval_final(Vread___024root* vlSelf);

VL_ATTR_COLD void Vread::final() {
    Vread___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vread::hierName() const { return vlSymsp->name(); }
const char* Vread::modelName() const { return "Vread"; }
unsigned Vread::threads() const { return 1; }
void Vread::prepareClone() const { contextp()->prepareClone(); }
void Vread::atClone() const {
    contextp()->threadPoolpOnClone();
}
