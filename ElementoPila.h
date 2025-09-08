#ifndef _ELEMENTOPILA
#define _ELEMENTOPILA

#include <string>
using namespace std;

class ElementoPila {
public:
    virtual ~ElementoPila() {}
    virtual string toString() = 0;  // declaramos función virtual pura
};

#endif
