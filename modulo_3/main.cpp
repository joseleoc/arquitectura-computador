#include <systemc.h>
#include "or_gate.cpp"
#include "xor_gate.cpp"
#include "nand_gate.cpp"
#include "nor_gate.cpp"
#include "xnor_gate.cpp"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> A, B;
    sc_signal<bool> Y_or, Y_xor, Y_nand, Y_nor, Y_xnor;

    OrGate or1("or1");
    XorGate xor1("xor1");
    NandGate nand1("nand1");
    NorGate nor1("nor1");
    XnorGate xnor1("xnor1");

    // Conexiones para OR
    or1.a(A); 
    or1.b(B); 
    or1.y(Y_or);
    
    // Conexiones para XOR
    xor1.a(A); 
    xor1.b(B); 
    xor1.y(Y_xor);
    
    // Conexiones para NAND
    nand1.a(A); 
    nand1.b(B); 
    nand1.y(Y_nand);
    
    // Conexiones para NOR
    nor1.a(A); 
    nor1.b(B); 
    nor1.y(Y_nor);
    
    // Conexiones para XNOR
    xnor1.a(A); 
    xnor1.b(B); 
    xnor1.y(Y_xnor);

    cout << "A B | OR XOR NAND NOR XNOR" << endl;
    cout << "---------------------------" << endl;

    // Probar todas las combinaciones posibles de A y B
    for (int i = 0; i < 4; i++) {
        A = (i >> 1) & 1;  // Bit más significativo (A)
        B = i & 1;         // Bit menos significativo (B)
        
        sc_start(1, SC_NS);  // Ejecutar por 1 nanosegundo
        
        cout << A.read() << " " << B.read() << " |  "
             << Y_or.read() << "   "
             << Y_xor.read() << "    "
             << Y_nand.read() << "     "
             << Y_nor.read() << "    "
             << Y_xnor.read() << endl;
    }

    return 0;
}