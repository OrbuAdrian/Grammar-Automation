#include "JumpTable.h"

#include <iostream>

using namespace std;


TabelSalt::TabelSalt() {};

TabelSalt::TabelSalt(string tsText, vector<string> tsAbove) {
    this->tsAbove = tsAbove;

    ifstream ts;
    ts.open(tsText);

    if (ts.is_open()) {
        string line;
        while (getline(ts, line)) {
            valuesBuffer += line + " ";
        }
    }

    generateColumns();
}

void TabelSalt::generateColumns() {
    StringSeparator separator(valuesBuffer, " ");
    vector<string> bufferValues = separator.getTokens();
    vector<string> col0;
    vector<string> col1;
    vector<string> col2;

    for (int i = 0; i < bufferValues.size(); i++) {
        if (i % 3 == 0) {
            col0.push_back(bufferValues[i]);
        }
        else if (i % 3 == 1) {
            col1.push_back(bufferValues[i]);

        }
        else if (i % 3 == 2) {
            col2.push_back(bufferValues[i]);

        }
    }

    Column c0(tsAbove[0], col0);
    Column c1(tsAbove[1], col1);
    Column c2(tsAbove[2], col2);

    cols.push_back(c0);
    cols.push_back(c1);
    cols.push_back(c2);


}

int TabelSalt::getValueFromColumn(string title, int state) {
    for (auto col : cols) {
        if (col.colTitle == title) {
            return stoi(col.colValues[state]);
        }
    }
}