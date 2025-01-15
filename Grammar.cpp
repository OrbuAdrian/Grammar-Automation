#include "Grammar.h"

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



void Gramatica::generateAPD(string taText, string tsText) {
    vector<string> taAbove = { "id", "+", "*", "(", ")", "$" };
    vector<string> tsAbove = { "E", "T", "F" };
    AutomatPushDown apd(taText, taAbove, tsText, tsAbove, P);
}

void Gramatica::generateSTOS() {
    STOS stos(P);
}

void Gramatica::generateAPDTable() {
       
}

void Gramatica::showGrammar() {
    cout << "\nDerivare: " << derivare;

    cout << "\nSymbols: ";
    for (const auto& symbol : symbols) {
        cout << symbol << " ";
    }

    cout << "\nTerminals: ";
    for (const auto& terminal : Terminals) {
        cout << terminal << " ";
    }

    cout << "\nNon-Terminals: ";
    for (const auto& nonTerminal : nonTerminals) {
        cout << nonTerminal << " ";
    }

    P->showProductions();
    //P->showDerivations();

    cout << endl; // New line for better readability
}

void Gramatica::loop(int steps) {

    srand(time(nullptr));

    int sIdx = rand() % P->simbStart->End.size();

    string rezultat = P->simbStart->retEndString(sIdx);
    bool derived = true;
    int generationNumber = 0;

    cout << "\nDerivare: " << derivare << '\n';
    P->showDerivations();
    cout << "\n\nDerivare start: ";
    P->simbStart->show();
    cout << "\n(" << ++generationNumber << ") " << "Generare sir: ";
    cout << rezultat;


    while (steps - 1) {

        derived = false;

        if (derivare == "extrem stanga") {

            for (int i = 0; i < rezultat.size(); i++) {

                if (P->isDerivationElement(rezultat[i])) {
                    Derivari* dPtr = P->retDerivare(rezultat[i]);

                    if (dPtr) {
                        int rIdx = rand() % dPtr->End.size();

                        rezultat.erase(i, 1);
                        rezultat.insert(i, dPtr->retEndString(rIdx));
                        derived = true;
                        break;
                    }
                }

            }
        }
        else
            if (derivare == "extrem dreapta") {
                for (int i = rezultat.size() - 1; i >= 0; i--) {

                    if (P->isDerivationElement(rezultat[i])) {
                        Derivari* dPtr = P->retDerivare(rezultat[i]);

                        if (dPtr) {
                            int rIdx = rand() % dPtr->End.size();

                            rezultat.erase(i, 1);
                            rezultat.insert(i, dPtr->retEndString(rIdx));
                            derived = true;
                            break;
                        }
                    }

                }
            }


        if (!derived) break;

        cout << "\n(" << ++generationNumber << ") " << "Generare sir: ";

        for (char c : rezultat) {
            Sleep(500 / rezultat.size());
            cout << c;
        }


        steps--;
    }
}


Gramatica::Gramatica(const vector<string>& productions) {
    P = new Productii(productions);

    string strLeft, strRight;
    vector<string> tokens;

    for (const auto& p : productions) {
        string separators = "*+-/() ";

        int arrowPos = p.find("->");

        strLeft = trim(p.substr(0, arrowPos));
        strRight = trim(p.substr(arrowPos + 2));

        //Generate non terminals
        for (char c : strLeft) {
            string symb(1, c);

            if (find(nonTerminals.begin(), nonTerminals.end(), symb) == nonTerminals.end()) {
                nonTerminals.push_back(symb);
            }
        }

        StringSeparator separator(strRight, separators);
        vector<string> toks = separator.getTokens();
        tokens.insert(tokens.end(), toks.begin(), toks.end());

    }

    //Generate non terminals
    for (auto tok : tokens) {
        if (find(Terminals.begin(), Terminals.end(), tok) == Terminals.end()
            && find(nonTerminals.begin(), nonTerminals.end(), tok) == nonTerminals.end()) {

            Terminals.push_back(tok);
        }
    }

    //Generate symbols;
    symbols.insert(symbols.end(), nonTerminals.begin(), nonTerminals.end());
    symbols.insert(symbols.end(), Terminals.begin(), Terminals.end());

    P->createDerivations();
    showGrammar();
    generateAPD("TabelaActiuni.txt", "TabelaSalt.txt");
    generateAPDTable();
}

Gramatica::~Gramatica() {
    delete P;
}