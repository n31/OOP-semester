#include <iostream>
#include "NickQueue.h"
#include "CharString.h"

using namespace std;

int main() {
	cout << "Enter size of int queue: ";
	int m;
	cin >> m;
	NickQueue<int> p;
	cout << ((p.isEmpty()) ? "Quque is empty!" : "Queue isn't empty!") << endl;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		p.push(x);
	}
	cout << ((p.isEmpty()) ? "Quque is empty!" : "Queue isn't empty!") << endl;
	cout << "Your int queue: ";
	p.print();
	// -----
	cout << "Enter size of char* queue: ";
	int n;
	cin >> n;
	NickQueue<char*> q(1);
	q.printNum();
	cout << ((q.isEmpty()) ? "Quque is empty!" : "Queue isn't empty!") << endl;
	for (int i = 0; i < n; i++) {
		char* x = setString();
		q.push(x);
	}
	cout << ((q.isEmpty()) ? "Quque is empty!" : "Queue isn't empty!") << endl;
	cout << "Your char* queue:\n";
	q.print();
	cout << "Check if the word exist in the queue: ";
	char* f = setString();
	cout << ((q.findSubstr(f)) ? "Word exist!" : "Word doesn't exist!") << endl;
	return 0;
}