# Simulación de Memoria RAM en SystemC

## Descripción

Implementación de una memoria RAM de 256x8 bits en SystemC con operaciones de lectura y escritura sincronizadas por reloj.

## Características

- Tamaño: 256 posiciones de 8 bits cada una
- Señales de control: enable, write, clk
- Direccionamiento: 8 bits
- Operaciones sincronizadas con flanco positivo del reloj

## Estructura del proyecto

memoria_systemc/
├── memoria.h # Módulo de memoria
├── memoria_tb.cpp # Testbench de simulación
├── Makefile # Script de compilación
└── README.md # Este archivo

## Compilación y ejecución

### Compilación manual:

```bash
g++ memoria_tb.cpp -I /usr/local/systemc/include -L /usr/local/systemc/lib-linux -lsystemc -lm -o memoria_sim
```
