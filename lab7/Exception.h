#pragma once
#include <iostream>

using namespace std;

class Exception {
	int ex;
public:
	Exception(int e) : ex(e) {}

	void printErr() {
		if (ex == 1) {
			cout << "this element is already exist (From Exception class with love)\n";
		}
	}
};