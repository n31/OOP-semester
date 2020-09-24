#pragma once

#include <string>
#include <iostream>

using namespace std;

int setCentury() {
	int c;
	cout << "Enter AC century: ";
	cin >> c;
	if (!(c <= 21 && c > 0)) {
		cout << "Incorrect century! Try again: ";
		cin >> c;
	}
	return c;
}
	
int setGerbType() {
	string types[3] = { "Supporters", "Badges", "Banners" };
	int t;
	cout << "Enter geraldic type: \n";
	for (int i = 0; i < 3; i++) cout << i << ". " << types[i] << endl;
	cin >> t;
	while (t > 2 || t < 0) {
		cout << "Incorrect type! Try again: ";
		cin >> t;
	}
	return t;
}

string setGerbColor() {
	string s;
	cout << "Enter RGB of the gerb color: ";
	cin >> s;
	while (s.find_first_not_of("abcdefABCDEF01234567890") != string::npos || s.size() != 6) {
		cout << "Invalid input! Try again: ";
		cin >> s;
	}
	return s;
}

string setDna() {
	string s;
	cout << "Enter human DNA (T, C, A, G): ";
	cin >> s;
	while (s.find_first_not_of("TCAGtcag") != string::npos || s.size() != 3) {
		cout << "Invalid input! Try again: ";
		cin >> s;
	}
	return s;
}
	
string setName() {
	cout << "Enter human last name: ";
	string s;
	cin >> s;
	return s;
}
	
int setGender() {
	int g;
	cout << "Enter human gender(1 - male, 2 - female): ";
	cin >> g;
	while (g != 1 && g != 2) {
		cout << "incorrect input! Try again: ";
		cin >> g;
	}
	return g;
}