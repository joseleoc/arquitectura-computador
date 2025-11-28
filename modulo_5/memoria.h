#ifndef MEMORIA_H
#define MEMORIA_H

#include <systemc.h>

SC_MODULE(Memoria) {
    // Puertos de entrada
    sc_in<bool> clk;
    sc_in<bool> enable;
    sc_in<bool> write;
    sc_in<sc_uint<8>> address;
    sc_in<sc_uint<8>> data_in;
    
    // Puerto de salida
    sc_out<sc_uint<8>> data_out;

    // Memoria interna: 256 posiciones de 8 bits
    sc_uint<8> mem[256];

    // Proceso para operaciones de lectura/escritura
    void operar_memoria() {
        if (enable.read()) {
            if (write.read()) {
                // Operación de escritura
                mem[address.read()] = data_in.read();
                cout << "[" << sc_time_stamp() << "] ESCRIBIENDO: Dirección 0x" 
                     << hex << address.read() << " -> Dato 0x" << data_in.read() << endl;
            } else {
                // Operación de lectura
                data_out.write(mem[address.read()]);
                cout << "[" << sc_time_stamp() << "] LEYENDO: Dirección 0x" 
                     << hex << address.read() << " -> Dato 0x" << mem[address.read()] << endl;
            }
        } else {
            // Memoria deshabilitada
            data_out.write(0);
        }
    }

    SC_CTOR(Memoria) {
        // Inicializar memoria a cero
        for (int i = 0; i < 256; i++) {
            mem[i] = 0;
        }
        
        // Registrar el proceso sensible al flanco positivo del reloj
        SC_METHOD(operar_memoria);
        sensitive << clk.pos();
    }
};

#endif // MEMORIA_H