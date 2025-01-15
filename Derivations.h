#ifndef D_H
#define D_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Derivari {
public:
    string Start;
    vector<string> End;

    
    void show();

    char retStart();

    string retEndString(int);
    
    Derivari();

    Derivari(const string&, const vector<string>&);
};

#endif //!D_H
