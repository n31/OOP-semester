#pragma once

#include <iostream>
#include "DeathStranding.h"
#include "Exception.h"
using namespace std;

template <typename T>
class Stack {
private:
	struct Element {
		T value;
		struct Element* next;
	} *head, *tail;
	int Size;
public:
	class Iterator;
	Stack() : head(NULL), Size(0), tail(NULL) {}
	~Stack() {}

	void push(T value, bool unique = false) {
		if (unique && find(value)) return;
		Element *newElem = new Element;
		newElem->value = value;
		newElem->next = head;
		head = newElem;
		if (newElem->next == NULL) tail = newElem;
		Size++;
	}

	T pop() {
		T popValue = head->value;
		if (head == tail) tail = NULL;
		head = head->next;
		Size--;
		return popValue;
	}

	bool find(T el) {
		for (auto it = Iterator(begin()), end_it = Iterator(end()); it != end_it; it++) if ((*it).value == el) return true;
		return false;
	}

	/*void watch() {
		for (auto it = Iterator(begin()), end_it = Iterator(end()); it != end_it; it++) cout << (*it).value << ' ';
		cout << endl;
	}*/

	Iterator find(DeathStranding el) {
		for (auto it = Iterator(begin()), end_it = Iterator(end()); it != end_it; it++) if ((*it).value == el) return it;
		return NULL;
	}

	void del(DeathStranding el) {
		Stack tmp;
		Iterator miss = find(el);
		for (auto it = Iterator(begin()), end_it = Iterator(end()); it != end_it; it++) {
			if (it == miss) continue;
			tmp.push((*it).value);
		}
		*this = tmp;
	}

	void insert(T el, int pos) {
		Stack tmp;
		int i = 0;
		for (auto it = Iterator(begin()), end_it = Iterator(end()); it != end_it; it++) {
			if (i == pos) {
				tmp.push(el);
			}
			tmp.push((*it).value);
			i++;
		}
		*this = tmp;
	}

	T& at(int n) {
		return (*(begin() + n)).value;
	}

	T& operator[] (const int n) {
		return (*(begin() + n)).value;
	}

	Iterator begin() { return head; }
	Iterator end() { return NULL; }

	class Iterator{
		Element* current;
	public:
		Iterator(Element* first) : current(first) {}

		Iterator& operator++ (int) {
					Element* temp = current->next;
					current = current->next;
					return *this;
		}

		Iterator& operator+ (const int n) {
			for (int i = 0; i < n; i++) {
				Element* temp = current->next;
				current = current->next;
			}
			return *this;
		}

		bool operator!= (const Iterator& it) { return current != it.current; }
		bool operator== (const Iterator& it) { return current == it.current; }

		Element& operator= (const Element& el) {
			current = el.current;
			return this;
		}

		Element& operator* () { return *current; }
	};
};



template <>
class Stack<DeathStranding> {
private:
	struct Element {
		DeathStranding value;
		struct Element* next;
	} *head, *tail;
	int Size;
public:
	class Iterator;
	Stack() : head(NULL), Size(0), tail(NULL) {}
	~Stack() {}

	int getSize() { return Size; }

	bool push(DeathStranding value, bool unique = false) {
		try {
			if (unique && find(value) != NULL) throw 1;
			Element* newElem = new Element;
			newElem->value = value;
			newElem->next = head;
			head = newElem;
			if (newElem->next == NULL) tail = newElem;
			Size++;
			return true;
		}
		catch (int n) {
			Exception ex(n);
			ex.printErr();
			return false;
		}
	}

	DeathStranding pop() {
		DeathStranding popValue = head->value;
		if (head == tail) tail = NULL;
		head = head->next;
		Size--;
		return popValue;
	}

	Iterator find(DeathStranding el) {
		for (auto it = Iterator(begin()), end_it = Iterator(end()); it != end_it; it++) if ((*it).value == el) return it;
		return NULL;
	}

	void del(DeathStranding el) {
		Stack tmp, tmp1;
		for (auto it = Iterator(begin()), end_it = Iterator(end()); it != end_it; it++) {
			tmp.push((*it).value);
		}
		Iterator miss = tmp.find(el);
		for (auto it = tmp.begin(), end_it = tmp.end(); it != end_it; it++) {
			if (it == miss) continue;
			tmp1.push((*it).value);
		}
		*this = tmp1;
	}

	void insert(DeathStranding el, int pos) {
		Stack tmp, tmp1;
		int i = 0;
		for (auto it = Iterator(begin()), end_it = Iterator(end()); it != end_it; it++) {
			tmp.push((*it).value);
		}
		for (auto it = tmp.begin(), end_it = tmp.end(); it != end_it; it++) {
			if (i == pos) {
				tmp1.push(el);
			}
			tmp1.push((*it).value);
			i++;
		}
		*this = tmp1;
	}

	void insSort() {
		for (int i = 0; i < Size; i++) {
			DeathStranding key = at(i);
			int j = i - 1;

			while (j >= 0 && at(j).getLevel() > key.getLevel()) {
				at(j + 1) = at(j);
				j = j - 1;
			}
			at(j + 1) = key;
		}
	}

	void watch() {
		try {
			if (begin() == NULL) throw 1;
			cout << "================================\n";
			for (auto it = Iterator(begin()), end_it = Iterator(end()); it != end_it; it++) {
				if (it != Iterator(begin())) cout << "-----------------------------\n";
				cout << "id: " << (*it).value.getId() << endl;;
				cout << "level: " << (*it).value.getLevel() << endl;
				cout << "time: " << (*it).value.getTime() << endl;
			}
			cout << "================================\n";
		}
		catch (int) {
			cerr << "can't read from an empty stack\n";
		}
	}

	DeathStranding& at(int n) {
		return (*(begin() + n)).value;
	}

	DeathStranding& operator[] (const int n) {
		return (*(begin() + n)).value;
	}

	Iterator begin() { return head; }
	Iterator end() { return NULL; }

	class Iterator {
		Element* current;
	public:
		Iterator(Element* first) : current(first) {}

		Iterator& operator++ (int) {
			Element* temp = current->next;
			current = current->next;
			return *this;
		}

		Iterator& operator+ (const int n) {
			for (int i = 0; i < n; i++) {
				Element* temp = current->next;
				current = current->next;
			}
			return *this;
		}

		bool operator!= (const Iterator& it) { return current != it.current; }
		bool operator== (const Iterator& it) { return current == it.current; }

		Element& operator= (Element& el) {
			current->next = el.next;
			current->value.setLevel(el.value.getLevel());
			current->value.setTime(el.value.getTime());
			current->value.setId(el.value.getId());
		}

		Element& operator* () { return *current; }
	};
};