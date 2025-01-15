#ifndef T_H
#define T_H

#include "Column.h"


class Table {

public:
    string Title;

    int colsNumber;
    int rowsNumber;
    bool canBeAttached = true;

    vector<Column> cols;
    string buffer;

    int tableWidth = 0;
    int tableHeight = 0;

public:
    Table();

    Table(vector<Column>);

    void addSpacing(int, int);

    void printTableHeaders();

    void printTableBody();

    void initializeBuffer();

    void show();

    void normalizeRows(int);

    bool sameTitle(Column, Column);

    void refactorColumns();

    Table& operator+=(Table&);
};

#endif // !T_H


//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Column {
//public:
//    vector<string> colValues;
//    bool extendsL, extendsR;
//
//    Column(vector<string> colValues) {
//        this->colValues = colValues;
//    }
//
//    int columnWidth() {
//        string maxString = "";
//        for (auto s : colValues) {
//
//            maxString = max(maxString, s);
//        }
//
//        return maxString.size();
//    }
//
//    int nrOfRows() {
//        return colValues.size();
//    }
//};
//
//
//class Table {
//
//public:
//    string Title;
//
//    int colsNumber;
//    int rowsNumber;
//    bool canBeAttached = true;
//
//    vector<Column> cols;
//    string buffer;
//
//    int tableWidth = 0;
//    int tableHeight = 0;
//
//public:
//
//    Table(string t, vector<Column> c) {
//        Title = t;
//        cols = c;
//        colsNumber = cols.size();
//        rowsNumber = c[0].nrOfRows();
//
//        int colSize = 0, size = 0;
//        for (auto& col : c) {
//            colSize = max(colSize, col.columnWidth());
//            size += colSize;
//        }
//
//        int titleLength = Title.length(); // Convert to int
//        tableWidth = max(size, titleLength);
//
//
//        initializeBuffer();
//    }
//
//    Table(string t, Column c) {
//        Title = t;
//        cols.push_back(c);
//
//        colsNumber = cols.size();
//        rowsNumber = c.nrOfRows();
//
//        initializeBuffer();
//    }
//
//
//    void addSpacing(int maxSize, int value) {
//
//        int difference = maxSize - value;
//
//        if (difference && maxSize > value) {
//            for (int i = 0; i < difference; i++) {
//                buffer += " ";
//            }
//        }
//    }
//
//    void printTableHeaders() {
//        string sep = "=";
//
//        buffer += " ";
//        for (int i = 0; i < tableWidth; i++) {
//            buffer += "_";
//        }
//        buffer += " ";
//        buffer += '\n';
//
//
//        buffer += "|";
//        for (auto& col : cols) {
//            if (col.extendsL) {
//                string str(Title.length(), ' ');  // Use a char (' ') instead of a string (" ")
//                buffer += str;
//            }
//            else buffer += Title;
//
//            addSpacing(col.columnWidth(), Title.length());
//
//            if (col.extendsR) buffer += " ";
//            else buffer += "|";
//        }
//        buffer += '\n';
//
//
//        buffer += "|";
//        for (auto c : cols) {
//            for (int i = 0; i < tableWidth; i++) {
//                if (c.colValues[0] == " ") {
//                    buffer += " ";
//                }
//                else buffer += sep;
//            }
//            if (c.extendsR) buffer += sep;
//            else buffer += "|";
//        }
//        buffer += '\n';
//
//    }
//
//    void printTableBody() {
//        string sep = "_";
//
//        for (int i = 0; i < rowsNumber; i++) { // -1 because header is separate
//            for (auto& col : cols) {
//                if (i < col.colValues.size()) {
//                    buffer += "|";
//                    buffer += col.colValues[i];
//                    addSpacing(tableWidth, col.colValues[i].length());
//                }
//
//            }
//            buffer += "|";
//            buffer += '\n';
//
//
//            buffer += "|";
//            for (auto c : cols) {
//                for (int i = 0; i < tableWidth; i++) {
//                    buffer += sep;
//                }
//                buffer += "|";
//            }
//            buffer += '\n';
//        }
//    }
//
//    void initializeBuffer() {
//        buffer = "";
//        printTableHeaders();
//        printTableBody();
//    }
//
//    void show() {
//        cout << buffer;
//    }
//
//    void normalizeRows(int newRowsNumber) {
//        for (auto& col : cols) {
//            int currentRows = col.colValues.size() + 1; // Include header
//            if (currentRows < newRowsNumber) {
//                int difference = newRowsNumber - currentRows;
//                for (int i = 0; i < difference; i++) {
//                    col.colValues.insert(col.colValues.begin(), " ");
//                }
//            }
//        }
//    }
//
//    bool sameTitleWith(Table& other) {
//        if (Title == other.Title) return true;
//        return false;
//    }
//
//    Table& operator+=(Table& t) {
//        int maxRows = max(rowsNumber, t.rowsNumber);
//        //cout << maxRows;
//        if (rowsNumber < t.rowsNumber) {
//            normalizeRows(maxRows);
//        }
//        else if (rowsNumber > t.rowsNumber) {
//            t.normalizeRows(maxRows);
//        }
//
//
//        // Add the columns from the second table
//        for (int i = 0; i < t.cols.size(); i++) {
//            if (i == 0 && sameTitleWith(t)) {
//                cols[cols.size() - 1].extendsR = true;
//                t.cols[i].extendsL = true;
//            }
//            cols.push_back(t.cols[i]);
//        }
//
//
//        colsNumber += t.colsNumber;
//        rowsNumber = maxRows;
//
//        initializeBuffer();
//
//        return *this;
//    }
//};
//
//
//int main()
//{
//    vector<Column> columns;
//    vector<string> colValuesA, colValuesB, colValuesC, colValuesD;
//
//    string TitleA, TitleB, TitleC, TitleD;
//    TitleA = "TitleA    ";
//    TitleB = "TitleB    ";
//    TitleC = "TitleC    ";
//    TitleD = "TitleD    ";
//
//    colValuesA.insert(colValuesA.end(), { "a1" ,"a2", "a3" });
//    colValuesB.insert(colValuesB.end(), { "B values" ,"b1", "b2", "b3" });
//    colValuesC.insert(colValuesC.end(), { "C values" ,"c1", "c2", "c3" });
//    colValuesD.insert(colValuesD.end(), { "d1", "d2", "d3" });
//
//    columns.push_back(Column(colValuesA));
//    //Table t1("Tabel1", columns);
//
//    columns.clear();
//
//    columns.push_back(Column(colValuesB));
//    //Table t2("Tabel2  ", columns);
//
//    columns.clear();
//
//    columns.push_back(Column(colValuesC));
//    //Table t3("Tabel3  ", columns);
//
//    columns.clear();
//
//    columns.push_back(Column(colValuesD));
//    //Table t4("Tabel4  ", columns);
//
//    columns.clear();
//
//    columns.insert(columns.end(), { Column(colValuesB) });
//    Table t5("Tabel5  ", columns);
//
//    columns.clear();
//
//    columns.insert(columns.end(), { Column(colValuesB) });
//    Table t6("Tabel6  ", columns);
//
//    //t2 += t3;
//    //t1 += t2;
//    //t1 += t4;
//    t6 += t5;
//    t6.show();
//
//
//    return 0;
//}
