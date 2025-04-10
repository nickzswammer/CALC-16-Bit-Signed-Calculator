// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vread.h for the primary calling header

#include "Vread__pch.h"
#include "Vread__Syms.h"
#include "Vread___024root.h"

void Vread___024root___ctor_var_reset(Vread___024root* vlSelf);

Vread___024root::Vread___024root(Vread__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vread___024root___ctor_var_reset(this);
}

void Vread___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vread___024root::~Vread___024root() {
}
