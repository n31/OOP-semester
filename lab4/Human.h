#pragma once

#include <iostream>
#include "History.h"
#include "Gerb.h"
#include "Family.h"

using namespace std;

class Human : public Gerb, public Family {
private:
	int gender;
public:
	Human(int g, string n, string col, int t, int c, string d) :
		gender(g),
		History(c),
		Gerb(col, t, c),
		Family(n, c, d) {}
	~Human() {
		cout << "Human object deleted\n";
	}
	void printGender() {
		if (gender == NULL) cout << "gender(Human): NULL\n";
		else cout << "gender(Human): " << ((gender == 2) ? "Female" : "Male") << endl;
	}
	void print() {
		printGender();
		printName();
		printDna();
		printGerbColor();
		printGerbType();
		printCentury();
	}
};