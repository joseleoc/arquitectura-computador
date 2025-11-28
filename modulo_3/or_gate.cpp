#include <systemc.h>

SC_MODULE(OrGate) {
    sc_in<bool> a, b;
    sc_out<bool> y;

    void do_or() {
        y.write(a.read() || b.read());
    }

    SC_CTOR(OrGate) {
        SC_METHOD(do_or);
        sensitive << a << b;
    }
};