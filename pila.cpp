#include "pila.h"

void Pila::push(ElementoPila* e){
    lista.push_front(e);
}

ElementoPila* Pila::top(){
    return lista.front();
}

void Pila::pop(){
    if (!lista.empty())
        lista.pop_front();
}

void Pila::muestra(){
    cout << "Pila: ";
    for (auto it = lista.rbegin(); it != lista.rend(); ++it){
        cout << "[" << (*it)->toString() << "] ";
    }
    cout << endl;
}
