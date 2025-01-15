#include "Column.h"

Column::Column(string colTitle, vector<string> colValues) {
    this->colTitle = colTitle;
    this->colValues = colValues;
}

int Column::columnWidth() {

    string maxString = "";
    for (auto s : colValues) {

        maxString = max(maxString, s);
    }



    return max(colTitle.size(), maxString.size());
}

int Column::columnHeight() {
    return colValues.size();
}