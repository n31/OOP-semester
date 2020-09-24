#pragma once
#include <iostream>

using namespace std;

class History {
private:
	int century;
public:
	History(int c) : century(c) {}
	~History() {
		cout << "History object deleted\n";
	}
	void printCentury() {
		cout << "Century(History): " << century << endl;
	}
};