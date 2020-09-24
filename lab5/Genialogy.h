#pragma once

#include <iostream>
#include <string>
#include "History.h"

class Genialogy : public History {
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
	void printCentury() {
		cout << "Century (from Genialogy): " << century << endl;
	}
	float calculateSmth() {
		// перевод днк в рнк и расчет распространенности рнк в определенном веке
		string rna = dna;
		for (int i = 0; i < rna.size(); i++)
			if (rna[i] == 'T' || rna[i] == 't') rna[i] = 'U';
		//float k = rna[0] - rna[1] + rna[2] - rna[0];
		float k = (rna[0] * 0.1 + rna[1] * 0.1 + rna[2] * 0.1) / 100;
		return century * k;
	}
};
