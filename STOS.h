#ifndef STOS_H
#define STOS_H

#include "Productions.h"
#include <vector>
#include <string>
#include <stack>

struct StateScheme {
	string id, p;

	StateScheme(string i) {
		id = i;
	}

	string getTemp() {
		string lowerId = id;
		if (lowerId[0] >= 'A' && lowerId[0] <= 'Z') {
			lowerId[0] = lowerId[0] + ('a' - 'A');
			return lowerId;
		}
	}
};

class STOS {
private:
	Productii* P;
	stack<StateScheme> stack;

public:
	STOS();
	STOS(Productii* p);
	void generateAction(int);
	void emit();
	void newtemp();

};


#endif 