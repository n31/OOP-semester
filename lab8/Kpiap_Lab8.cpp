#include <iostream>
#include <string>
#include "WorkWithFile.h"
#include "Produkt.h"

#include <fstream>

using namespace std;

int main() {
	WorkWithFile fileWorker;

	fileWorker.openTextFile("textfile.txt");
	for (int i = 0; i < 5; i++) {
		fileWorker << to_string(i);
	}
	fileWorker.outputToConsole();
	cout << endl;
	fileWorker.outputToConsoleReverse();
	cout << endl << endl;

	WorkWithFile fileWorker1;
	fileWorker1.openFileStream("testFile.txt");
	fileWorker1.putString("Hello, world!");
	fileWorker1.outputToConsole();
	cout << endl;
	fileWorker1.outputToConsoleReverse();
	cout << endl << endl;

	WorkWithFile fileWorker2;
	fileWorker2.openFileStream("bin.bin");
	Produkt* fairing = new Produkt('B', "Elon Musk", "SpaceX", 69);
	Produkt* nozzle = new Produkt('A', "Jeff Bezos", "Blueorigin", 420);
	Produkt* pumps = new Produkt('A', "William E. Boeing", "Boeing", 911);
	Produkt* oxidizer = new Produkt('B', "Dwight D. Eisenhower", "NASA", 58);
	Produkt* fin = new Produkt('C', "Russian government", "Roscosmos", 92);
	fileWorker2.putObject(fairing);
	fileWorker2.putObject(nozzle);
	fileWorker2.putObject(pumps);
	fileWorker2.putObject(oxidizer);
	fileWorker2.putObject(fin);
	Produkt *anyProduct = new Produkt();
	fileWorker2.printObject();
	fileWorker2.PrintObjectReverse();
	fileWorker2.sortByKategoria();
	fileWorker2.printObject();
	fileWorker2.sortByLiczbaProduktow();
	fileWorker2.printObject();
	fileWorker2.sortByNazwaKolekcjonera();
	fileWorker2.printObject();
	fileWorker2.sortByNazwaWarsztatu();
	fileWorker2.printObject();
	string warsztat;
	cout << "Enter warsztat: ";
	cin >> warsztat;
	fileWorker2.printInfoByNazwaWarsztatu(warsztat);
	for (int i = 0; i < fileWorker2.getLength(); i += 2) {
		anyProduct = fileWorker2.deleteObject(i);
		cout << anyProduct->toString() << " DELETED" << endl;
	}
	fileWorker2.printObject();
	

	return 0;
}