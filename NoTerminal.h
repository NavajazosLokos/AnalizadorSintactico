#ifndef _NOTERMINAL
#define _NOTERMINAL

#include "ElementoPila.h"
#include <string>
using namespace std;

class NoTerminal : public ElementoPila {
private:
    string simbolo;
public:
    NoTerminal(string s) : simbolo(s) {}
    string toString() override { return "NoTerminal(" + simbolo + ")"; }
};

#endif
