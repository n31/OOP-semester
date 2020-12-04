#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace cs {


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

		DeathStranding(int i, int l, int t) {
			cout << "Pushing to list {id: " << i << ", level: " << l << ", time: " << t << "}\n";
			id = i;
			level = l;
			time = t;
		}

		string toString() {
			string res = "{id: ";
			res += to_string(this->id) + ", level: " + to_string(this->level);
			res += ", time: " + to_string(this->time);
			res += "}";
			return res;
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
}