#ifndef G_H
#define G_H

#include <string>
#include <vector>
#include <iostream>
#include <windows.h>


#include "StringSeparator.h"
#include "AutomatPushDown.h"
#include "STOS.h"
#include "Productions.h"

#include "Column.h"
#include "Table.h"

using namespace std;

class Gramatica {

private:

    Productii* P;
    string derivare = "extrem dreapta";
    vector<string> Terminals;
    vector<string> nonTerminals;
    vector<string> symbols;
    vector<string> operations;

public:

    Gramatica(const vector<string>& );

    void generateAPD(string, string);

    void generateAPDTable();

    void generateSTOS();

    void showGrammar();

    void loop(int);

    ~Gramatica();

};

#endif //!G_H
