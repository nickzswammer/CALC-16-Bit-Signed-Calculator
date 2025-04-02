// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgencon.h for the primary calling header

#include "Vgencon__pch.h"
#include "Vgencon__Syms.h"
#include "Vgencon___024root.h"

void Vgencon___024root___ctor_var_reset(Vgencon___024root* vlSelf);

Vgencon___024root::Vgencon___024root(Vgencon__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vgencon___024root___ctor_var_reset(this);
}

void Vgencon___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vgencon___024root::~Vgencon___024root() {
}
