// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VINPUT_CONTROL__SYMS_H_
#define VERILATED_VINPUT_CONTROL__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vinput_control.h"

// INCLUDE MODULE CLASSES
#include "Vinput_control___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vinput_control__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vinput_control* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vinput_control___024root       TOP;

    // CONSTRUCTORS
    Vinput_control__Syms(VerilatedContext* contextp, const char* namep, Vinput_control* modelp);
    ~Vinput_control__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
