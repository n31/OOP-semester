#pragma once

#include <iostream>
#include <string>
#include "History.h"

class Geraldic : public virtual History {
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
};