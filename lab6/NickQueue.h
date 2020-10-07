#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Base {
private:
	int num;
public:
	Base(int n) : num(n) {}
	~Base() {}
	void printNum() {
		cout << "Your num: " << num << endl;
	}
};

template <typename T>
class NickQueue {
private:
	struct Queue {
		T elem;
		Queue* nextElem;
	};
	Queue* queueHead, * queueTail;
	int s;
public:
	NickQueue() : queueHead(NULL), queueTail(NULL), s(0) {}

	bool isEmpty() {
		return queueHead == NULL;
	}

	void push(T elem) {
		Queue* newElem = new Queue;
		newElem->elem = elem;
		if (isEmpty()) queueTail = queueHead = newElem;
		else {
			queueTail->nextElem = newElem;
			queueTail = newElem;
		}
		s++;
	}

	T pop() {
		T res = queueHead->elem;
		Queue* p;
		if (queueTail == queueHead)
		{
			delete queueHead;
			queueTail = queueHead = nullptr;
			return res;
		}
		p = queueHead->nextElem;
		delete queueHead;
		queueHead = p;
		s--;
		return res;
	}

	int size() { return s; }

	void print() {
		//while (!isEmpty()) cout << pop() << ' ';
		for (int i = 0; i < s; i++) {
			T x = pop();
			cout << x << ' ';
			push(x);
			s--;
		}
		cout << endl;
	}

	bool find(T val) {
		for (int i = 0; i < s; i++) {
			T x = pop();
			push(x);
			if (x == val) return true;
		}
		return false;
	}
};

template <>
class NickQueue<char*> : public Base {
private:
	struct Queue {
		char* elem;
		Queue* nextElem;
	};
	Queue* queueHead, * queueTail;
	int s = 0;
public:
	NickQueue(int n) : queueHead(NULL), queueTail(NULL), Base(n) {}

	bool isEmpty() {
		return queueHead == NULL;
	}

	void push(char* elem) {
		Queue* newElem = new Queue;
		newElem->elem = elem;
		if (isEmpty()) queueTail = queueHead = newElem;
		else {
			queueTail->nextElem = newElem;
			queueTail = newElem;
		}
		s++;
	}

	char* pop() {
		char* res = queueHead->elem;
		Queue* p;
		if (queueTail == queueHead)
		{
			delete queueHead;
			queueTail = queueHead = nullptr;
			return res;
		}
		p = queueHead->nextElem;
		delete queueHead;
		queueHead = p;
		s--;
		return res;
	}

	void print() {
		for (int i = 0; i < s; i++) {
			char* x = pop();
			printf("%s ", x);
			push(x);
			s--;
		}
		cout << endl;
	}

	bool find(char* val) {
		for (int i = 0; i < s; i++) {
			char* x = pop();
			push(x);
			if (x == val) return true;
		}
		return false;
	}

	bool findSubstr(char* val) {
		for (int i = 0; i < s; i++) {
			char* x = pop();
			push(x);
			if (strstr(x, val)) return true;
		}
		return false;
	}
};