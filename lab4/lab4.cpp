#include <iostream>
#include <string>
#include "Human.h"
#include "Setters.h"

using namespace std;

int main() {
	int cent = setCentury(),
		type = setGerbType(),
		gender = setGender();
	string color = setGerbColor(),
		dna = setDna(),
		name = setName();

	cout << endl;


	Human *h = new Human(gender, name, color, type, cent, dna);
	h->print();

	cout << endl;
	delete h;

	return 0;
}