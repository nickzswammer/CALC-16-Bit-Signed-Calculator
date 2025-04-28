// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vinput__pch.h"

//============================================================
// Constructors

Vinput::Vinput(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vinput__Syms(contextp(), _vcname__, this)}
    , Reset{vlSymsp->TOP.Reset}
    , Clock{vlSymsp->TOP.Clock}
    , RowIn{vlSymsp->TOP.RowIn}
    , ColOut{vlSymsp->TOP.ColOut}
    , LFSRReset{vlSymsp->TOP.LFSRReset}
    , LFSRFlg{vlSymsp->TOP.LFSRFlg}
    , KeyRdy{vlSymsp->TOP.KeyRdy}
    , KeyRd{vlSymsp->TOP.KeyRd}
    , Number{vlSymsp->TOP.Number}
    , Operator{vlSymsp->TOP.Operator}
    , EqualSign{vlSymsp->TOP.EqualSign}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vinput::Vinput(const char* _vcname__)
    : Vinput(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vinput::~Vinput() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vinput___024root___eval_debug_assertions(Vinput___024root* vlSelf);
#endif  // VL_DEBUG
void Vinput___024root___eval_static(Vinput___024root* vlSelf);
void Vinput___024root___eval_initial(Vinput___024root* vlSelf);
void Vinput___024root___eval_settle(Vinput___024root* vlSelf);
void Vinput___024root___eval(Vinput___024root* vlSelf);

void Vinput::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vinput::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vinput___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vinput___024root___eval_static(&(vlSymsp->TOP));
        Vinput___024root___eval_initial(&(vlSymsp->TOP));
        Vinput___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vinput___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vinput::eventsPending() { return false; }

uint64_t Vinput::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vinput::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vinput___024root___eval_final(Vinput___024root* vlSelf);

VL_ATTR_COLD void Vinput::final() {
    Vinput___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vinput::hierName() const { return vlSymsp->name(); }
const char* Vinput::modelName() const { return "Vinput"; }
unsigned Vinput::threads() const { return 1; }
void Vinput::prepareClone() const { contextp()->prepareClone(); }
void Vinput::atClone() const {
    contextp()->threadPoolpOnClone();
}
