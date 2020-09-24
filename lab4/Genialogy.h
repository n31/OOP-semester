#pragma once

#include <iostream>
#include <string>
#include "History.h"

class Genialogy : public virtual History {
private:
	string dna; // T C A G
public:
	Genialogy(string d, int c) : dna(d), History(c) {}
	~Genialogy() {
		cout << "Genialogy object deleted\n";
	}
	void printDna() {
		cout << "dna(Genialogy): " << dna << endl;
	}
};