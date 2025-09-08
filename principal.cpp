#include <iostream>
#include <string>

#include "pila.h"
#include "lexico.h"
#include "Terminal.h"
#include "NoTerminal.h"
#include "Estado.h"

using namespace std;

// Tabla LR(1) para E -> id + E | id
int tablaLR[5][4] = {
    /* id   +   $   E */
    { 2,  0,  0,  1},  // estado 0
    { 0,  0, -1, 0},   // estado 1 (aceptación)
    { 0,  3, -2, 0},   // estado 2
    { 2,  0,  0,  4},  // estado 3
    { 0,  0, -1, 0}    // estado 4
};

// Reglas de producción
int idReglas[2] = {3, 3};   // columna del no terminal E en tablaLR
int lonReglas[2] = {3, 1};  // E->id+E = 3 elementos, E->id = 1 elemento

// Convierte tipo léxico a columna de tablaLR
int columnaLR(int tipo) {
    switch (tipo) {
        case TipoSimbolo::IDENTIFICADOR: return 0;
        case TipoSimbolo::OPADIC: return 1;
        case TipoSimbolo::PESOS: return 2;
        default: return -1;
    }
}

void ejemploRecursivo(string entrada) {
    Pila pila;
    Lexico lexico(entrada);

    // Inicialización
    pila.push(new Estado(0));
    lexico.sigSimbolo();

    bool aceptacion = false;
    while (!aceptacion) {
        Estado* estadoTop = dynamic_cast<Estado*>(pila.top());
        int fila = estadoTop->getNumero();
        int col = columnaLR(lexico.tipo);
        int accion = tablaLR[fila][col];

        pila.muestra();
        cout << "entrada: " << lexico.simbolo << "  accion: " << accion << endl;

        if (accion > 0) {
            // Desplazamiento (shift)
            pila.push(new Terminal(lexico.simbolo));
            pila.push(new Estado(accion));
            lexico.sigSimbolo();
        } 
        else if (accion < 0) {
            // Reducción
            int regla = -accion - 1; // -2 -> regla 1
            for (int i = 0; i < lonReglas[regla]*2; i++) pila.pop(); // quitar símbolos y estados

            // Estado después de la reducción
            Estado* eTop = dynamic_cast<Estado*>(pila.top());
            int nuevoEstado = tablaLR[eTop->getNumero()][idReglas[regla]];

            pila.push(new NoTerminal("E"));
            pila.push(new Estado(nuevoEstado));
        } 
        else {
            cout << "Error: acción inválida" << endl;
            break;
        }

        aceptacion = (accion == -1);
    }

    if (aceptacion) cout << "Cadena aceptada!" << endl;
}

int main() {
    ejemploRecursivo("a+b+c");
    return 0;
}
