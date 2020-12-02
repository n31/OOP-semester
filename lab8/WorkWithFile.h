#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Produkt.h"
#include <vector>

using namespace std;

class WorkWithFile {
private:
	
	string filename;
	fstream fileStream;
	int length;

	struct Product {
		char kategoria;
		int lacznaLiczbaProduktow;
		vector<string> nazwyKolekcjonerow;
	};
	
public:

	WorkWithFile() {
		this->length = 0;
	}

	void openTextFile(string filename) {
		try {
			this->fileStream.open(filename, ios::in | ios::out | ios::trunc);
			this->filename = filename;
			if (!this->fileStream.is_open()) throw 1;
		}
		catch (int) {
			cerr << "[RUNTIME] Error while opening file...\n";
			terminate();
		}
	}

	WorkWithFile& operator<< (string obj)
	{	
		try {
			if (!this->fileStream.is_open()) throw 1;
			putString(obj);
			return *this;
		}
		catch (int) {
			cerr << "[RUNTIME] Error while opening file...\n";
			terminate();
		}
	}

	WorkWithFile& operator>> (string &obj) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			this->fileStream.seekg(0);
			char ch;
			for (int i = 0; i < getLength(); i++) {
				this->fileStream.get(ch);
				obj.push_back(ch);
			}
		}
		catch (int) {
			cerr << "[RUNTIME] Error while opening file...\n";
			terminate();
		}
	}

	void openFileStream(string filename) {
		try {
			this->fileStream.open(filename, ios::binary | ios::in | ios::out | ios::trunc);
			this->filename = filename;
			if (!this->fileStream.is_open()) throw 1;
		}
		catch (int) {
			cerr << "[RUNTIME] Error while opening file...\n";
			terminate();
		}
	}

	void putString(string text) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			for (auto ch : text) {
				this->fileStream.put(ch);
			}
			this->length += text.size();
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
		
	}

	void outputToConsole() {
		try {
			if (!this->fileStream.is_open()) throw 1;
			this->fileStream.seekg(0);
			char ch;
			for (int i = 0; i < getLength(); i++) {
				this->fileStream.get(ch);
				cout << ch;
			}
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	void outputToConsoleReverse() {
		try {
			if (!this->fileStream.is_open()) throw 1;
			char ch;
			for (int i = getLength() - 1; i >= 0; i--) {
				this->fileStream.seekg(i);
				this->fileStream.get(ch);
				cout << ch;
			}
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	void putObject(Produkt *object, int index = -1) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			if (index < 0) {
				this->fileStream.seekg(length * sizeof(Produkt));
				this->length++;
			}
			else {
				try {
					if (index >= this->length) throw 1;
					this->fileStream.seekg(index * sizeof(Produkt));
				}
				catch(int) {
					cerr << "[RUNTIME] Run out of scope error...\n";
					terminate();
				}
			}
			this->fileStream.write((char*)object, sizeof(Produkt));
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	int getLength() {
		return this->length;
	}

	void outputToObject(Produkt *object, int index) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			this->fileStream.seekg(index * sizeof(Produkt));
			this->fileStream.read((char*)object, sizeof(Produkt));
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	Produkt* fetchObject(int index) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			try {
				if (index >= this->length || index < 0) throw 1;
				Produkt* object = new Produkt;
				this->fileStream.seekg(index * sizeof(Produkt));
				this->fileStream.read((char*)object, sizeof(Produkt));
				return object;
			}
			catch (int) {
				cerr << "[RUNTIME] Run out of scope error...\n";
				terminate();
			}
			cout << "";
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	void printObject() {
		cout << "Printing object: \n";
		for (int i = 0; i < getLength(); i++) {
			cout << fetchObject(i)->toString() << endl;
		}
	}

	void PrintObjectReverse() {
		cout << "Printing object reverse:\n";
		for (int i = getLength() - 1; i >= 0; i--) {
			cout << fetchObject(i)->toString() << endl;
		}
	}

	Produkt* deleteObject(int index) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			try {
				if (index >= this->length || index < 0) throw 1;
				
				Produkt *res = fetchObject(index);

				for (int i = index + 1; i < getLength(); i++) {
					Produkt* tmp = new Produkt;
					outputToObject(tmp, i);
					putObject(tmp, i - 1);
				}

				this->length--;

				return res;
			}
			catch (int) {
				cerr << "[RUNTIME] Run out of scope error...\n";
				terminate();
			}
			cout << "";
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	void swapObjectsAt(int i, int j) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			try {
				if (i >= this->length || i < 0 || j >= this->length || j < 0) throw 1;
				Produkt* tmp = fetchObject(i);
				putObject(fetchObject(j), i);
				putObject(tmp, j);
			}
			catch (int) {
				cerr << "[RUNTIME] Run out of scope error...\n";
				terminate();
			}
			cout << "";
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	void sortByKategoria() {
		cout << "sortByKategoria()\n";
		int i, j;
		Produkt* key;
		for (i = 1; i < getLength(); i++)
		{
			key = fetchObject(i);
			j = i - 1;
			while (j >= 0 && fetchObject(j)->getKategoria() > key->getKategoria())
			{
				putObject(fetchObject(j), j + 1);
				j = j - 1;
			}
			putObject(key, j + 1);
		}
	}

	void sortByNazwaKolekcjonera() {
		cout << "sortByNazwaKolekcjonera()\n";
		int i, j;
		Produkt* key;
		for (i = 1; i < getLength(); i++)
		{
			key = fetchObject(i);
			j = i - 1;
			while (j >= 0 && fetchObject(j)->getNazwaKolekcjonera() > key->getNazwaKolekcjonera())
			{
				putObject(fetchObject(j), j + 1);
				j = j - 1;
			}
			putObject(key, j + 1);
		}
	}

	void sortByNazwaWarsztatu() {
		cout << "sortByNazwaWarsztatu()\n";
		int i, j;
		Produkt* key;
		for (i = 1; i < getLength(); i++)
		{
			key = fetchObject(i);
			j = i - 1;
			while (j >= 0 && fetchObject(j)->getNazwaWarsztatu() > key->getNazwaWarsztatu())
			{
				putObject(fetchObject(j), j + 1);
				j = j - 1;
			}
			putObject(key, j + 1);
		}
	}
	
	void sortByLiczbaProduktow() {
		cout << "sortByLiczbaProduktow()\n";
		int i, j;
		Produkt* key;
		for (i = 1; i < getLength(); i++)
		{
			key = fetchObject(i);
			j = i - 1;
			while (j >= 0 && fetchObject(j)->getLiczbaProduktow() > key->getLiczbaProduktow())
			{
				putObject(fetchObject(j), j + 1);
				j = j - 1;
			}
			putObject(key, j + 1);
		}
	}

	void printInfoByNazwaWarsztatu(string nazwaWarsztatu) {
		cout << "printInfoByNazwaWarsztatu()\n";
		vector<Product> products;
		for (int i = 0; i < getLength(); i++) {
			Produkt *object = fetchObject(i);
			if (object->getNazwaWarsztatu() == nazwaWarsztatu) {
				// ---
				bool kategoriaAlreadyExists = false;
				int productIndex = 0;
				for (int j = 0; j < products.size(); j++) {
					if (products[j].kategoria == object->getKategoria()) {
						kategoriaAlreadyExists = true;
						productIndex = j;
						break;
					}
				}
				//---
				if (kategoriaAlreadyExists) {
					products[productIndex].lacznaLiczbaProduktow += object->getLiczbaProduktow();
					products[productIndex].nazwyKolekcjonerow.push_back(object->getNazwaKolekcjonera());
				}
				else {
					Product p;
					p.kategoria = object->getKategoria();
					p.lacznaLiczbaProduktow = object->getLiczbaProduktow();
					p.nazwyKolekcjonerow.push_back(object->getNazwaKolekcjonera());
					products.push_back(p);
				}
			}
		}
		
		for (int i = 0; i < products.size(); i++) {
			cout << products[i].kategoria << " " << products[i].lacznaLiczbaProduktow << endl;
			for (int j = 0; j < products[i].nazwyKolekcjonerow.size(); j++) {
				cout << products[i].nazwyKolekcjonerow[j] << endl;
			}
		}
	}

	void setSeek(int s) {
		this->fileStream.seekg(s);
	}

	void close() {
		this->fileStream.close();
	}

};