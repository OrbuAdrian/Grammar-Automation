#include <iostream>
#include <string>
#include <vector>
#include <fstream>


#include <conio.h>
#include <windows.h>

#include "Grammar.h"

using namespace std;

int main()
{

    ifstream file;
    file.open("Text.txt");
    vector<string> productii;

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {

            if (!line.empty()) {
                productii.push_back(line);
            }
        }
        file.close();
    }

    Gramatica G(productii);
    std::cout << endl;
    string key;

    while (true) {
        key = _getch();
        system("CLS");
        if (key == "r") {
            G.loop(30);
        }
        else break;
    }


}