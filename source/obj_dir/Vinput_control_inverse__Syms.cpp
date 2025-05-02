// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vinput_control_inverse__pch.h"
#include "Vinput_control_inverse.h"
#include "Vinput_control_inverse___024root.h"

// FUNCTIONS
Vinput_control_inverse__Syms::~Vinput_control_inverse__Syms()
{
}

Vinput_control_inverse__Syms::Vinput_control_inverse__Syms(VerilatedContext* contextp, const char* namep, Vinput_control_inverse* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(55);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
