#ifndef _ESTADO
#define _ESTADO

#include "ElementoPila.h"
#include <string>

class Estado : public ElementoPila {
private:
    int numero;
public:
    Estado(int n) : numero(n) {}
    int getNumero() { return numero; }
    string toString() override { return "Estado(" + to_string(numero) + ")"; }
};

#endif
