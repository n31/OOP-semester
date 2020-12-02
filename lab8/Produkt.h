#pragma once

#include <string>

using namespace std;

class Produkt {
private:
	char kategoria;
	string nazwaKolekcjonera;
	string nazwaWarsztatu;
	int liczbaProduktow;

public:

	Produkt() {
		this->kategoria = NULL;
		this->nazwaKolekcjonera = "";
		this->nazwaWarsztatu = "";
		this->liczbaProduktow = NULL;
	}

	Produkt(char kategoria, string nazwaKolekcjonera, string nazwaWarsztatu, int liczbaProduktow) {
		this->kategoria = kategoria;
		this->nazwaKolekcjonera = nazwaKolekcjonera;
		this->nazwaWarsztatu = nazwaWarsztatu;
		this->liczbaProduktow = liczbaProduktow;
	}

	string toString() {
		string res = "{";
		res.push_back(this->kategoria);
		res += ", " + this->nazwaKolekcjonera + ", ";
		res += this->nazwaWarsztatu + ", ";
		res += to_string(this->liczbaProduktow) + "}";
		return res;
	}

	void setKategoria(char kategoria) {
		this->kategoria = kategoria;
	}

	void setNazwaKolekcjonera(string nazwaKolekcjanera) {
		this->nazwaKolekcjonera = nazwaKolekcjanera;
	}
	
	void setNazwaWarsztatu(string nazwaWarsztatu) {
		this->nazwaWarsztatu = nazwaWarsztatu;
	}

	void setLiczbaProductow(int liczbaProductow) {
		this->liczbaProduktow = liczbaProductow;
	}

	char getKategoria() {
		return this->kategoria;
	}

	string getNazwaKolekcjonera() {
		return this->nazwaKolekcjonera;
	}

	string getNazwaWarsztatu() {
		return this->nazwaWarsztatu;
	}

	int getLiczbaProduktow() {
		return this->liczbaProduktow;
	}
};