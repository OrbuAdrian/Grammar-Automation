#include "AutomatPushDown.h"

StateSymbol::StateSymbol(string symbol, int state) {
    this->state = state;
    this->symbol = symbol;
}

void StateSymbol::show() {
    cout << symbol;
    cout << state;
}

void showFull(stack<StateSymbol>& s) {

    vector<StateSymbol> vec;
    stack<StateSymbol> temp = s;
    while (!temp.empty()) {

        vec.push_back(temp.top());
        temp.pop();
    }

    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {

        it->show();
        cout << "";
    }
    cout << endl << endl;
}


bool AutomatPushDown::solveAction(string action) {
    if (action == "acc") {
        return true;
    }
    else switch (action[0]) {
    case 'd': {
        symbState.push(StateSymbol(inputWord_Tokenized[inputIdx], action[1] - '0'));
        inputIdx++;

    } break;
    case 'r': {

        string* data = P->getTerminalAtPos(action[1] - '0');
        string symbol = data[0];
        int length = stoi(data[1]);

        while (length) {
            symbState.pop();
            --length;
        }

        symbState.push(StateSymbol(symbol, TS.getValueFromColumn(symbol, symbState.top().state)));


    } break;

    }
    return false;
}

void AutomatPushDown::getSTOS() {
    
}

void AutomatPushDown::evaluate() {

    bool foundSolution;

    do {
        showFull(symbState);

        string action = TA.getValueFromColumn(inputWord_Tokenized[inputIdx], symbState.top().state);
        foundSolution = solveAction(action);

    } while (!foundSolution);

    cout << "String ACCEPTAT!!!";

}

void AutomatPushDown::verify(string inputWord) {

    inputWord_Tokenized = StringSeparator(inputWord).getTokens_bySymbols();
    inputIdx = 0;

    evaluate(); //first symbol from the input word
}

void AutomatPushDown::showAPDTable() {
    vector<Column> ta;
    vector<string> taValues;
    string taTitle = "Tabel de actiuni: TA";

    /*for (auto& col : TA.getColumns()) {
        vector<string> taValues = col.colValues;
        taValues.insert(taValues.begin(), col.colTitle);
        ta.push_back(Column(taTitle, taValues))

    }*/

}

AutomatPushDown::AutomatPushDown(string taText, vector<string> taAbove, string tsText, vector<string> tsAbove, Productii* P) : TA(taText, taAbove), TS(tsText, tsAbove), P(P) {

    symbState.push(StateSymbol("$", 0));
    toVerify += "$";

    cout << "Input Word is: " << toVerify << endl;
    verify(toVerify);
}

