#ifndef AT_H
#define AT_H

#include <vector>
#include <fstream>
#include <iostream>

#include "StringSeparator.h"
#include "Column.h"

class TabelActiuni {
public:
    string valuesBuffer = "";
    vector<Column> cols;
    vector<string> taAbove;


    TabelActiuni();
    TabelActiuni(string, vector<string>);

    void generateColumns();

    string getValueFromColumn(string, int);

    vector<Column> getColumns();
};

#endif //!AT_H