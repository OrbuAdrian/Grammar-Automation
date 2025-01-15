#ifndef APD_H
#define APD_H

#include <string>
#include <stack>
#include <vector>
#include <fstream>

#include "StringSeparator.h"
#include "STOS.h"

#include "ActionTable.h"
#include "JumpTable.h"
#include "Productions.h"
#include "Table.h"


#include <iostream>


using namespace std;

struct StateSymbol {
    string symbol;
    int state;

    StateSymbol(string , int);
    void show();
};


class AutomatPushDown {
private:
    stack<StateSymbol> symbState;
    vector<string> inputWord_Tokenized;
    int inputIdx = 0;

    TabelActiuni TA;
    TabelSalt TS;
    Productii* P;
    STOS stos;

    string toVerify = "id+id*id";

public:

    bool solveAction(string);

    void evaluate();

    void verify(string inputWord);

    void showAPDTable();

    void getSTOS();

    AutomatPushDown(string, vector<string>, string, vector<string>, Productii*);

};


#endif // !APD_H
