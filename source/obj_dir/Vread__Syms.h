// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VREAD__SYMS_H_
#define VERILATED_VREAD__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vread.h"

// INCLUDE MODULE CLASSES
#include "Vread___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vread__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vread* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vread___024root                TOP;

    // CONSTRUCTORS
    Vread__Syms(VerilatedContext* contextp, const char* namep, Vread* modelp);
    ~Vread__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
