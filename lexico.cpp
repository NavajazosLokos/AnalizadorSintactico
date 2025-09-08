#include "lexico.h"
#include <cctype>  // para isalpha

Lexico::Lexico(string fuente) {
    ind = 0;
    this->fuente = fuente;
}

Lexico::Lexico() {
    ind = 0;
}

// Devuelve el siguiente símbolo
int Lexico::sigSimbolo() {
    if (terminado()) {
        simbolo = "$";
        tipo = TipoSimbolo::PESOS;
        return tipo;
    }

    c = sigCaracter();

    if (isalpha(c) || c == '_') { // identificador
        simbolo = c;
        tipo = TipoSimbolo::IDENTIFICADOR;
    } else if (c == '+') {
        simbolo = c;
        tipo = TipoSimbolo::OPADIC;
    } else if (c == '$') {
        simbolo = "$";
        tipo = TipoSimbolo::PESOS;
    } else {
        simbolo = c;
        tipo = TipoSimbolo::ERROR;
    }

    return tipo;
}

// Siguiente caracter
char Lexico::sigCaracter() {
    if (terminado()) return '$';
    return fuente[ind++];
}

bool Lexico::terminado() {
    return ind >= fuente.length();
}
