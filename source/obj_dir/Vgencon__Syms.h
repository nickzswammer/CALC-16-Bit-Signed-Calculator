// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VGENCON__SYMS_H_
#define VERILATED_VGENCON__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vgencon.h"

// INCLUDE MODULE CLASSES
#include "Vgencon___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vgencon__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vgencon* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vgencon___024root              TOP;

    // CONSTRUCTORS
    Vgencon__Syms(VerilatedContext* contextp, const char* namep, Vgencon* modelp);
    ~Vgencon__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
