#ifndef _PILA
#define _PILA

#include <list>
#include <iostream>
#include <string>
#include "ElementoPila.h"
using namespace std;

class Pila {
private:
    list<ElementoPila*> lista;

public:
    void push(ElementoPila* e);
    ElementoPila* top();
    void pop();
    void muestra();
};

#endif
