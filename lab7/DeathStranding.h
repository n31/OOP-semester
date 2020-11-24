#pragma once
#include <iostream>

using namespace std;

class DeathStranding {
private:
	int id;
	int time;
	int level;
public:
	DeathStranding() {
		id = 0;
		time = 0;
		level = 0;
	}

	DeathStranding(unsigned int i, unsigned int l) {
		id = i;
		level = l;
		time = 0;
	}

	~DeathStranding() {
		//cout << "Destructor has worked\n";
	}

	bool operator== (DeathStranding& obj) {
		if (
			obj.getTime() == getTime() &&
			obj.getLevel() == getLevel() &&
			obj.getId() == getId()
			) return true;
		return false;
	}

	void setTime(int t) {
		if (t > 0) time = t;
		else cout << "Error has occured: the time isn't real! Try again...\n";
	}

	void setLevel(int l) {
		if (l > 0) level = l;
		else cout << "Error has occured: the level isn't real! Try again...\n";
	}

	void setId(int i) {
		if (i >= 0) id = i;
		else cout << "Error has occured: the id isn't real! Try again...\n";
	}

	int getLevel() { return level; }
	int getTime() { return time; }
	int getId() { return id; }

	void show() {
		cout << "id: " << id << " time: " << time << " level: " << level << endl;
	}
};