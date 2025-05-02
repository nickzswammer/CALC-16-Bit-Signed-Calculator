// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vinput_control_inverse__pch.h"

//============================================================
// Constructors

Vinput_control_inverse::Vinput_control_inverse(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vinput_control_inverse__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , nRST{vlSymsp->TOP.nRST}
    , RowIn{vlSymsp->TOP.RowIn}
    , ColOut{vlSymsp->TOP.ColOut}
    , read_input{vlSymsp->TOP.read_input}
    , key_read{vlSymsp->TOP.key_read}
    , keypad_input{vlSymsp->TOP.keypad_input}
    , operator_input{vlSymsp->TOP.operator_input}
    , equal_input{vlSymsp->TOP.equal_input}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vinput_control_inverse::Vinput_control_inverse(const char* _vcname__)
    : Vinput_control_inverse(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vinput_control_inverse::~Vinput_control_inverse() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vinput_control_inverse___024root___eval_debug_assertions(Vinput_control_inverse___024root* vlSelf);
#endif  // VL_DEBUG
void Vinput_control_inverse___024root___eval_static(Vinput_control_inverse___024root* vlSelf);
void Vinput_control_inverse___024root___eval_initial(Vinput_control_inverse___024root* vlSelf);
void Vinput_control_inverse___024root___eval_settle(Vinput_control_inverse___024root* vlSelf);
void Vinput_control_inverse___024root___eval(Vinput_control_inverse___024root* vlSelf);

void Vinput_control_inverse::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vinput_control_inverse::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vinput_control_inverse___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vinput_control_inverse___024root___eval_static(&(vlSymsp->TOP));
        Vinput_control_inverse___024root___eval_initial(&(vlSymsp->TOP));
        Vinput_control_inverse___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vinput_control_inverse___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vinput_control_inverse::eventsPending() { return false; }

uint64_t Vinput_control_inverse::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vinput_control_inverse::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vinput_control_inverse___024root___eval_final(Vinput_control_inverse___024root* vlSelf);

VL_ATTR_COLD void Vinput_control_inverse::final() {
    Vinput_control_inverse___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vinput_control_inverse::hierName() const { return vlSymsp->name(); }
const char* Vinput_control_inverse::modelName() const { return "Vinput_control_inverse"; }
unsigned Vinput_control_inverse::threads() const { return 1; }
void Vinput_control_inverse::prepareClone() const { contextp()->prepareClone(); }
void Vinput_control_inverse::atClone() const {
    contextp()->threadPoolpOnClone();
}
