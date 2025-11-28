#include <systemc.h>
#include "memoria.h"

int sc_main(int argc, char* argv[]) {
    // Señales del sistema
    sc_clock clk("clk", 10, SC_NS);  // Reloj de 10 ns de periodo
    sc_signal<bool> enable;
    sc_signal<bool> write;
    sc_signal<sc_uint<8>> address;
    sc_signal<sc_uint<8>> data_in;
    sc_signal<sc_uint<8>> data_out;

    // Instanciar el módulo de memoria
    Memoria memoria("memoria_instancia");
    
    // Conectar las señales
    memoria.clk(clk);
    memoria.enable(enable);
    memoria.write(write);
    memoria.address(address);
    memoria.data_in(data_in);
    memoria.data_out(data_out);

    // Archivo de trazas (VCD) para visualización
    sc_trace_file *tf = sc_create_vcd_trace_file("memoria_trace");
    sc_trace(tf, clk, "clk");
    sc_trace(tf, enable, "enable");
    sc_trace(tf, write, "write");
    sc_trace(tf, address, "address");
    sc_trace(tf, data_in, "data_in");
    sc_trace(tf, data_out, "data_out");

    cout << "==========================================" << endl;
    cout << "Iniciando simulación de memoria RAM 256x8" << endl;
    cout << "==========================================" << endl;

    // Inicializar señales
    enable = 0;
    write = 0;
    address = 0;
    data_in = 0;
    
    // Ciclo 1: Deshabilitar memoria
    cout << "\n--- Ciclo 1: Memoria deshabilitada ---" << endl;
    sc_start(10, SC_NS);

    // Habilitar memoria
    enable = 1;

    // Ciclo 2: Escritura de datos
    cout << "\n--- Ciclo 2: Operaciones de escritura ---" << endl;
    
    // Escribir primer valor
    write = 1;  // Modo escritura
    address = 0x10;
    data_in = 0xAA;
    sc_start(10, SC_NS);

    // Escribir segundo valor
    address = 0x20;
    data_in = 0x55;
    sc_start(10, SC_NS);

    // Escribir tercer valor
    address = 0x30;
    data_in = 0xFF;
    sc_start(10, SC_NS);

    // Ciclo 3: Lectura de datos
    cout << "\n--- Ciclo 3: Operaciones de lectura ---" << endl;
    
    write = 0;  // Modo lectura

    // Leer primer valor
    address = 0x10;
    sc_start(10, SC_NS);
    cout << ">>> Dato leído de 0x10: 0x" << hex << data_out.read() << endl;

    // Leer segundo valor
    address = 0x20;
    sc_start(10, SC_NS);
    cout << ">>> Dato leído de 0x20: 0x" << hex << data_out.read() << endl;

    // Leer tercer valor
    address = 0x30;
    sc_start(10, SC_NS);
    cout << ">>> Dato leído de 0x30: 0x" << hex << data_out.read() << endl;

    // Ciclo 4: Verificación adicional
    cout << "\n--- Ciclo 4: Verificación adicional ---" << endl;
    
    // Escribir en otra dirección
    write = 1;
    address = 0x40;
    data_in = 0x99;
    sc_start(10, SC_NS);

    // Leer de la nueva dirección
    write = 0;
    sc_start(10, SC_NS);
    cout << ">>> Dato leído de 0x40: 0x" << hex << data_out.read() << endl;

    // Verificar que los datos anteriores siguen intactos
    address = 0x10;
    sc_start(10, SC_NS);
    cout << ">>> Verificación - Dato en 0x10: 0x" << hex << data_out.read() << endl;

    // Finalizar simulación
    cout << "\n==========================================" << endl;
    cout << "Simulación completada exitosamente" << endl;
    cout << "==========================================" << endl;

    // Cerrar archivo de trazas
    sc_close_vcd_trace_file(tf);
    
    return 0;
}