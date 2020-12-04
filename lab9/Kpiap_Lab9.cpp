#include <iostream>
#include "AlgoClass.h"
#include <list>
#include "DeathStranding.h"
#include <iterator>

using namespace as;

int main() {
	AlgoClass var;
	var.countWords("from.txt", "to.txt", "abc");

	cout << "Creating new list ls\n";
	list<cs::DeathStranding> ls;
	ls.push_back(cs::DeathStranding(1, 1, 10));
	ls.push_back(cs::DeathStranding(2, 2, 20));
	ls.push_back(cs::DeathStranding(3, 3, 30));

	auto allIdsIsBiggerThanNull = [](cs::DeathStranding x) {
		return x.getId() > 0;
	};

	cout << "Is all IDs in the list is bigger than zero? " << var.isAllTrueFor(ls.begin(), ls.end(), allIdsIsBiggerThanNull) << endl;
	ls.push_back(cs::DeathStranding(-1, 3, 30));
	cout << "Is all IDs in the list is bigger than zero? " << var.isAllTrueFor(ls.begin(), ls.end(), allIdsIsBiggerThanNull) << endl;

	cout << "Creating new onlyPositivesList\n";
	cout << "Copying only positives IDs from ls list\n";
	list<cs::DeathStranding> onlyPositivesList = var.copyAllTrueFor(ls.begin(), ls.end(), allIdsIsBiggerThanNull);
	cout << "Printing only positives list:\n";
	for (list<cs::DeathStranding>::iterator it = onlyPositivesList.begin(); it != onlyPositivesList.end(); it++) {
		cout << (*it).toString() << endl;
	}
}