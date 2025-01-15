#ifndef JT_H
#define JT_H


#include <vector>
#include <fstream>
#include <iostream>

#include "StringSeparator.h"
#include "Column.h"

using namespace std;


class TabelSalt {
    string valuesBuffer = "";
    vector<Column> cols;
    vector<string> tsAbove;

public:

    TabelSalt();

    TabelSalt(string, vector<string>);

    void generateColumns();

    int getValueFromColumn(string, int);
};
#endif //!JT_H