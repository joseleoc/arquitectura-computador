#include <systemc.h>

SC_MODULE(NandGate) {
    sc_in<bool> a, b;
    sc_out<bool> y;

    void do_nand() {
        y.write(!(a.read() && b.read()));
    }

    SC_CTOR(NandGate) {
        SC_METHOD(do_nand);
        sensitive << a << b;
    }
};