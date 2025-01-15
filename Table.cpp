#include "Table.h"

Table::Table() {
}

Table::Table(vector<Column> c) {
    cols = c;
    colsNumber = cols.size();
    rowsNumber = c[0].colValues.size() + 1;

    for (auto col : cols) {
        tableWidth += col.columnWidth();
    }

    initializeBuffer();
}

void Table::addSpacing(int maxSize, int value) {

    int difference = maxSize - value;

    if (difference && maxSize > value) {
        for (int i = 0; i < difference; i++) {
            buffer += " ";
        }
    }
}

void Table::printTableHeaders() {
    string sep = "=";

    buffer += " ";
    for (auto c : cols) {
        for (int i = 0; i < c.columnWidth(); i++) {
            buffer += "_";
        }
        if (c.extendsR) {
            buffer += "_";
        }
        else buffer += " ";
    }
    buffer += '\n';


    buffer += "|";
    for (auto& col : cols) {
        if (col.extendsL) {
            string str(col.colTitle.length(), ' ');  // Use a char (' ') instead of a string (" ")
            buffer += str;
        }
        else buffer += col.colTitle;

        addSpacing(col.columnWidth(), col.colTitle.length());

        if (col.extendsR) buffer += " ";
        else buffer += "|";
    }
    buffer += '\n';


    buffer += "|";
    for (auto c : cols) {
        for (int i = 0; i < c.columnWidth(); i++) {
            if (c.colValues[0] == " ") {
                buffer += " ";
            }
            else buffer += sep;
        }
        if (c.extendsR) buffer += sep;
        else buffer += "|";
    }
    buffer += '\n';

}

void Table::printTableBody() {
    string sep = "_";

    for (int i = 0; i < rowsNumber - 1; i++) { // -1 because header is separate
        for (auto& col : cols) {
            if (i < col.colValues.size()) {
                buffer += "|";
                buffer += col.colValues[i];
                addSpacing(col.columnWidth(), col.colValues[i].length());
            }

        }
        buffer += "|";
        buffer += '\n';


        buffer += "|";
        for (auto c : cols) {
            for (int i = 0; i < c.columnWidth(); i++) {
                buffer += sep;
            }
            buffer += "|";
        }
        buffer += '\n';
    }
}

void Table::initializeBuffer() {
    buffer = "";
    printTableHeaders();
    printTableBody();
}

void Table::show() {
    cout << buffer;
}

void Table::normalizeRows(int newRowsNumber) {
    for (auto& col : cols) {
        int currentRows = col.colValues.size() + 1; // Include header
        if (currentRows < newRowsNumber) {
            int difference = newRowsNumber - currentRows;
            for (int i = 0; i < difference; i++) {
                col.colValues.insert(col.colValues.begin(), " ");
            }
        }
    }
}

bool Table::sameTitle(Column a, Column b) {
    if (a.colTitle == b.colTitle) return true;
    return false;

}

Table& Table::operator+=(Table& t) {
    int maxRows = max(rowsNumber, t.rowsNumber);
    normalizeRows(maxRows);  // Ensure both tables have the same number of rows

    // Add the columns from the second table
    for (int i = 0; i < t.cols.size(); i++) {
        if (i == 0 && sameTitle(cols.back(), t.cols[i])) {
            cols[cols.size() - 1].extendsR = true;
            t.cols[i].extendsL = true;
        }
        cols.push_back(t.cols[i]);
    }



    colsNumber += t.colsNumber;
    rowsNumber = maxRows;

    initializeBuffer();

    return *this;
}

void Table::refactorColumns() {
    
}