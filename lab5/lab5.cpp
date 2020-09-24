#include <iostream>
#include <string>
#include "Setters.h"
#include "History.h"
#include "Genialogy.h"
#include "Geraldic.h"
#include "Gerb.h"
#include "locale.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int cent = setCentury(),
		type = setGerbType();
	string color = setGerbColor(),
		dna = setDna();

	//History** arr = (History**)malloc(sizeof(History*) * 3);
	History** arr = new History*[3];
	arr[0] = new Geraldic(type, cent);
	arr[1] = new Genialogy(dna, cent);
	arr[2] = new Gerb(color, type, cent);

	arr[0]->printCentury();
	cout << "частота использования геральдического типа: " << arr[0]->calculateSmth() << "%" << endl;

	arr[1]->printCentury();
	cout << "распростаненность рнк: " << arr[1]->calculateSmth() << "%" << endl;

	arr[2]->printCentury();
	cout << "частота использования цвета герба: " << arr[2]->calculateSmth() << "%" << endl << endl;

	for (int i = 0; i < 3; i++) {
		delete arr[i];
		cout << endl;
	}
	delete[] arr;

	return 0;
}