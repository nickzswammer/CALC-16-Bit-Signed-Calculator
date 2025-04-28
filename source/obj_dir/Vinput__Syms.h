// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VINPUT__SYMS_H_
#define VERILATED_VINPUT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vinput.h"

// INCLUDE MODULE CLASSES
#include "Vinput___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vinput__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vinput* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vinput___024root               TOP;

    // CONSTRUCTORS
    Vinput__Syms(VerilatedContext* contextp, const char* namep, Vinput* modelp);
    ~Vinput__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
