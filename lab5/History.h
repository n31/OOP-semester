#pragma once
#include <iostream>

using namespace std;

class History {
protected:
	int century;
public:
	History(int c) : century(c) {}
	virtual ~History() {
		cout << "History object deleted\n";
	}
	virtual void printCentury() = 0;
	virtual float calculateSmth() = 0;
};