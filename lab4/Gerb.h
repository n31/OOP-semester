#pragma once

#include <iostream>
#include <string>
#include "Geraldic.h"

using namespace std;

class Gerb : public Geraldic {
private:
	string colorRgb;
public:
	Gerb(string col, int t, int c) :
		colorRgb(col),
		History(c),
		Geraldic(t, c) {}
	~Gerb() {
		cout << "Gerb object deleted\n";
	}
	void printGerbColor() {
		cout << "colorRGB(Gerb): #" << colorRgb << endl;
	}
};