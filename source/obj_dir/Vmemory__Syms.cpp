// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vmemory__pch.h"
#include "Vmemory.h"
#include "Vmemory___024root.h"

// FUNCTIONS
Vmemory__Syms::~Vmemory__Syms()
{
}

Vmemory__Syms::Vmemory__Syms(VerilatedContext* contextp, const char* namep, Vmemory* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(33);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
