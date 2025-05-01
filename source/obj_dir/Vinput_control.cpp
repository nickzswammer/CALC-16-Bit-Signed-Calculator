// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vinput_control__pch.h"

//============================================================
// Constructors

Vinput_control::Vinput_control(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vinput_control__Syms(contextp(), _vcname__, this)}
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

Vinput_control::Vinput_control(const char* _vcname__)
    : Vinput_control(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vinput_control::~Vinput_control() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vinput_control___024root___eval_debug_assertions(Vinput_control___024root* vlSelf);
#endif  // VL_DEBUG
void Vinput_control___024root___eval_static(Vinput_control___024root* vlSelf);
void Vinput_control___024root___eval_initial(Vinput_control___024root* vlSelf);
void Vinput_control___024root___eval_settle(Vinput_control___024root* vlSelf);
void Vinput_control___024root___eval(Vinput_control___024root* vlSelf);

void Vinput_control::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vinput_control::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vinput_control___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vinput_control___024root___eval_static(&(vlSymsp->TOP));
        Vinput_control___024root___eval_initial(&(vlSymsp->TOP));
        Vinput_control___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vinput_control___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vinput_control::eventsPending() { return false; }

uint64_t Vinput_control::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vinput_control::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vinput_control___024root___eval_final(Vinput_control___024root* vlSelf);

VL_ATTR_COLD void Vinput_control::final() {
    Vinput_control___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vinput_control::hierName() const { return vlSymsp->name(); }
const char* Vinput_control::modelName() const { return "Vinput_control"; }
unsigned Vinput_control::threads() const { return 1; }
void Vinput_control::prepareClone() const { contextp()->prepareClone(); }
void Vinput_control::atClone() const {
    contextp()->threadPoolpOnClone();
}
