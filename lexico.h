#ifndef _LEXICO
#define _LEXICO

#include <iostream>
#include <string>
using namespace std;

class TipoSimbolo {
public:
    static const int ERROR = -1;
    static const int IDENTIFICADOR = 0; // columna 0 → id
    static const int OPADIC = 1;        // columna 1 → +
    static const int PESOS = 2;         // columna 2 → $
};

class Lexico {
private:
    string fuente;
    int ind;
    char c;

    char sigCaracter();

public:
    string simbolo;
    int tipo;

    Lexico(string fuente);
    Lexico();

    int sigSimbolo();
    bool terminado();
};

#endif
