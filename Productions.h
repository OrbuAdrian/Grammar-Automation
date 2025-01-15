#ifndef P_H
#define P_H

#include <string>
#include <vector>
#include <iostream>

#include "StringSeparator.h"
#include "Derivations.h"

using namespace std;

struct Productii {
    Derivari* simbStart;
    vector<Derivari> derivari;
    vector<string> productii;

    

    void showProductions();
    void showDerivations();

    void createSimbStart();

    void createDerivations();

    bool isDerivationElement(char);

    Derivari* retDerivare(char);

    string* getTerminalAtPos(int);
    
    Productii();
    
    Productii(const vector<string>&);

};

#endif // !P_H

