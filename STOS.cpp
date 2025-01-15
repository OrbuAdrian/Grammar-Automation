#include "STOS.h"
#include <iostream>

using namespace std;

inline string trim(const string& str) {
    auto start = str.begin();
    auto end = str.end();

    // Trim leading
    while (start != end && std::isspace(*start)) {
        ++start;
    }

    // Trim trailing
    do {
        --end;
    } while (end != start && std::isspace(*end));

    return string(start, end + 1);
}

void STOS::generateAction(int i) {
    
}

STOS::STOS() {
    
}

STOS::STOS(Productii* p) {
    
    string strLeft, strRight;
    string separators = "*+-/";

    for (const auto& production : p->productii) {
        int arrowPos = production.find("->");

        strLeft = trim(production.substr(0, arrowPos));
        strRight = trim(production.substr(arrowPos + 2));

        string action = "";

        

        cout << production << endl;
    }
}