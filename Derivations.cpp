#include "Derivations.h"


Derivari::Derivari() : Start(), End() {

}

Derivari::Derivari(const string& s, const vector<string>& e) : Start(s), End(e) {

}

void Derivari::show() {
    cout << Start << "-> ";

    for (auto dEnd : End) {
        cout << dEnd;

        if (dEnd != End.back()) {
            cout << " | ";
        }

    }
}

char Derivari::retStart() {
    return Start.data()[0];
}

string Derivari::retEndString(int i = 0) {
    if (i >= 0 && i < End.size()) {
        return End[i];
    }
    else {
        return "";
    }
}