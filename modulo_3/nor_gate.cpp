#include <systemc.h>

SC_MODULE(NorGate) {
    sc_in<bool> a, b;
    sc_out<bool> y;

    void do_nor() {
        y.write(!(a.read() || b.read()));
    }

    SC_CTOR(NorGate) {
        SC_METHOD(do_nor);
        sensitive << a << b;
    }
};