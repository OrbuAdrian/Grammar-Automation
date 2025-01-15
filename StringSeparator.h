#ifndef SS_H
#define SS_H

#include <string>
#include <vector>

using namespace std;

class StringSeparator {
private:
    vector<string> tokenList;
    vector<string> tokenList_symbols;
    string tokens = "";
    string content;
    string separators;

public:

    StringSeparator(const string& content, const string& separators) {

        this->content = content;
        this->separators = separators;

        TokenList();
        TokenList_Symbols();
    }

    StringSeparator(const string& content) {

        this->content = content;

        TokenList_Symbols();
    }


    void TokenList() {

        if (content.find_first_of(separators) != string::npos) {
            TokenizeString(this->content);
        }
        else {
            tokenList.push_back(this->content);
        }

    }

    void TokenList_Symbols() {
        TokenizeString_BySymbol(this->content);
    }


    void TokenizeString_BySymbol(string initString) {

        for (int i = 0; i < initString.length(); i++) {
            if (isLetter(initString[i])) {

                tokens = "";
                while (i < initString.length() && isLetter(initString[i])) {
                    tokens += initString[i];
                    i++;

                }
                i--;
                tokenList_symbols.push_back(tokens);

            }
            else if (initString[i] != '\n') {
                tokenList_symbols.push_back(string(1, initString[i]));
            }



        }
    }

    void TokenizeString(string initString) {

        for (int i = 0; i < initString.length(); i++) {

            if (separators.find(initString[i]) != string::npos) {
                if (tokens != "") {
                    tokenList.push_back(tokens);
                    tokens = "";
                }
                else {
                    continue;
                }
            }
            else {
                tokens += initString[i];
            }
        }

        if (tokens.length() > 0) {
            tokenList.push_back(tokens);
        }


    }

    vector<string> getTokens() {
        return tokenList;
    }

    vector<string> getTokens_bySymbols() {
        return tokenList_symbols;
    }


    bool isLetter(char value) {
        if (('a' <= value && value <= 'z') ||
            ('A' <= value && value <= 'Z')) {

            return true;
        }
        return false;
    }
};

#endif // !SS_H

