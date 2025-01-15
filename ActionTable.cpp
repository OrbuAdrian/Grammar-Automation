#include "ActionTable.h"

TabelActiuni::TabelActiuni() {};
TabelActiuni::TabelActiuni(string taText, vector<string> taAbove) {
    this->taAbove = taAbove;

    ifstream ta;
    ta.open(taText);

    if (ta.is_open()) {
        string line;
        while (getline(ta, line)) {
            valuesBuffer += line + " ";
        }
    }

    generateColumns();
}

void TabelActiuni::generateColumns() {
    StringSeparator separator(valuesBuffer, " ");
    vector<string> bufferValues = separator.getTokens();
    vector<string> col0;
    vector<string> col1;
    vector<string> col2;
    vector<string> col3;
    vector<string> col4;
    vector<string> col5;

    for (int i = 0; i < bufferValues.size(); i++) {
        if (i % 6 == 0) {
            col0.push_back(bufferValues[i]);
        }
        else if (i % 6 == 1) {
            col1.push_back(bufferValues[i]);

        }
        else if (i % 6 == 2) {
            col2.push_back(bufferValues[i]);

        }
        else if (i % 6 == 3) {
            col3.push_back(bufferValues[i]);

        }
        else if (i % 6 == 4) {
            col4.push_back(bufferValues[i]);

        }
        else if (i % 6 == 5) {
            col5.push_back(bufferValues[i]);

        }

    }

    cols.emplace_back(taAbove[0], col0);
    cols.emplace_back(taAbove[1], col1);
    cols.emplace_back(taAbove[2], col2);
    cols.emplace_back(taAbove[3], col3);
    cols.emplace_back(taAbove[4], col4);
    cols.emplace_back(taAbove[5], col5);


}

string TabelActiuni::getValueFromColumn(string title, int state) {
    for (auto col : cols) {
        if (col.colTitle == title) {
            return col.colValues[state];
        }
    }
}

vector<Column> TabelActiuni::getColumns() {
    return cols;
}