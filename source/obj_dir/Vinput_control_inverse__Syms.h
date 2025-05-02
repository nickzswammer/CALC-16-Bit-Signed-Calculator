// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VINPUT_CONTROL_INVERSE__SYMS_H_
#define VERILATED_VINPUT_CONTROL_INVERSE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vinput_control_inverse.h"

// INCLUDE MODULE CLASSES
#include "Vinput_control_inverse___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vinput_control_inverse__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vinput_control_inverse* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vinput_control_inverse___024root TOP;

    // CONSTRUCTORS
    Vinput_control_inverse__Syms(VerilatedContext* contextp, const char* namep, Vinput_control_inverse* modelp);
    ~Vinput_control_inverse__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
