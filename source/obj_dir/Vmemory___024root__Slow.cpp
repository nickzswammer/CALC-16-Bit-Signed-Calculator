// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmemory.h for the primary calling header

#include "Vmemory__pch.h"
#include "Vmemory__Syms.h"
#include "Vmemory___024root.h"

void Vmemory___024root___ctor_var_reset(Vmemory___024root* vlSelf);

Vmemory___024root::Vmemory___024root(Vmemory__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmemory___024root___ctor_var_reset(this);
}

void Vmemory___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vmemory___024root::~Vmemory___024root() {
}
