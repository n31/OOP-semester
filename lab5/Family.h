#pragma once

#include <iostream>
#include <string>
#include "History.h"
#include "Genialogy.h"

using namespace std;

class Family : public Genialogy {
private:
	string lastName;
public:
	Family(string l, int c, string d) :
		lastName(l),
		History(c),
		Genialogy(d, c) {}
	~Family() {
		cout << "Family object deleted\n";
	}
	void printName() {
		cout << "lastName(Family): " << lastName << endl;
	}
};