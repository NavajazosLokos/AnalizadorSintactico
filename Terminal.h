#ifndef _TERMINAL
#define _TERMINAL

#include "ElementoPila.h"
#include <string>
using namespace std;

class Terminal : public ElementoPila {
private:
    string simbolo;
public:
    Terminal(string s) : simbolo(s) {}
    string toString() override { return "Terminal(" + simbolo + ")"; }
};

#endif
