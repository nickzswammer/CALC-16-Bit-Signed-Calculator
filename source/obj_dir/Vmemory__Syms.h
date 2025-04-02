// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMEMORY__SYMS_H_
#define VERILATED_VMEMORY__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vmemory.h"

// INCLUDE MODULE CLASSES
#include "Vmemory___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vmemory__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmemory* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vmemory___024root              TOP;

    // CONSTRUCTORS
    Vmemory__Syms(VerilatedContext* contextp, const char* namep, Vmemory* modelp);
    ~Vmemory__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
