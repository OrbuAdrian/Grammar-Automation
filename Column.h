#ifndef Col_H
#define Col_H

#include <iostream>
#include <vector>

using namespace std;

class Column {
public:
    string colTitle;
    vector<string> colValues;
    bool extendsL, extendsR;

    Column(string colTitle, vector<string> colValues);

    int columnWidth();

    int columnHeight();
};

#endif //!Col_H