#include "Productions.h"


void Productii::showProductions() {
    cout << "\nProductions:" << endl;
    for (auto p : productii) {
        cout << p << endl;
    } cout << endl;
}

void Productii::showDerivations() {
    cout << "Derivations:" << endl;
    for (auto d : derivari) {
        d.show();
        cout << endl;
    }
}

void Productii::createSimbStart() {
    bool foundStart = false;
    for (auto d : derivari) {
        if (d.Start == "S ") {
            simbStart = new Derivari(d.Start, d.End);
            foundStart = true;
            break;
        }

    }

    if (!foundStart) {
        simbStart = &derivari.front();
    }
}

void Productii::createDerivations() {
    vector<string> derivationList;
    string sPrevious, sCurrent;

    for (const auto p : productii) {

        int arrowPos = p.find("->");
        sCurrent = p.substr(0, arrowPos);
        string d = p.substr(arrowPos + 3);


        // create the derivation list here
        if ((sPrevious == sCurrent) || (sPrevious.empty())) {
            derivationList.push_back(d);
            sPrevious = sCurrent;
        }
        else {
            Derivari D(sPrevious, derivationList);

            derivari.push_back(D);

            derivationList.clear();
            derivationList.push_back(d);
            sPrevious = sCurrent;
        }

    }

    if (!sPrevious.empty()) {
        Derivari D(sPrevious, derivationList);
        derivari.push_back(D);
    }

    createSimbStart();
}

bool Productii::isDerivationElement(char filter) {
    for (auto& d : derivari) {
        if (d.retStart() == filter) {
            return true;
        }
    }
    return false;
}

Derivari* Productii::retDerivare(char s) {
    for (auto& d : derivari) {
        if (d.retStart() == s) {
            return &d;
        }
    }
    return nullptr;
}

string* Productii::getTerminalAtPos(int i) {
    string text = productii[i-1];

    int arrowPos = text.find("->");
    string terminal = text.substr(0, arrowPos - 1);
    string derivation = text.substr(arrowPos + 2 + 1);

    StringSeparator sep(derivation);
    vector<string> symbols = sep.getTokens_bySymbols();
    string length = to_string(symbols.size());

    string* data = new string[2];
    data[0] = terminal;
    data[1] = length;

    return data;
}

Productii::Productii() : simbStart(), productii{}, derivari{} {
}

Productii::Productii(const vector<string>& p) : productii(p), simbStart() {
    //cout << "Productii generate..." << endl;
}