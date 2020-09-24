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
		Geraldic(t, c) {}
	~Gerb() {
		cout << "Gerb object deleted\n";
	}
	void printGerbColor() {
		cout << "colorRGB(Gerb): #" << colorRgb << endl;
	}
	void printCentury() {
		cout << "Century (from Gerb): " << century << endl;
	}
	float calculateSmth() {
		// рассчет частоты использования цвета герба в определенном веке
		string s = colorRgb;
		float k = s[0] - s[1] + s[2] - s[3] + s[4] - s[5];
		if (k < 0) k *= -1;
		return (float)century / (k + 1) / 100;
	}
};