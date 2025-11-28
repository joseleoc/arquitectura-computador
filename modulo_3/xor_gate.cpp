#include <systemc.h>

SC_MODULE(XorGate) {
    sc_in<bool> a, b;
    sc_out<bool> y;

    void do_xor() {
        y.write(a.read() != b.read());
    }

    SC_CTOR(XorGate) {
        SC_METHOD(do_xor);
        sensitive << a << b;
    }
};