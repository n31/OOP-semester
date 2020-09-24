#pragma once

#include <iostream>
#include <string>
#include "History.h"

class Geraldic : public History {
private:
	int type;
	string types[3] = { "Supporters", "Badges", "Banners" };
public:
	Geraldic(int t, int c) : History(c) { type = t; }
	~Geraldic() {
		cout << "Geraldic object deleted\n";
	}
	void printGerbType() {
		cout << "Type(Geraldic): " << types[type] << endl;
	}
	void printCentury() {
		cout << "Century (from Geraldic): " << century << endl;
	}
	float calculateSmth() {
		// рассчет частоты использования геральдического типа в зависимости от века
		float k = (type == 0) ? 0.25 : ((type == 1) ? 0.5 : 1.5);
		return (float)century * k / (float)(type + 1);
	}
};