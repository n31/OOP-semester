#pragma once

#include <list>
#include <iterator>
#include "DeathStranding.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace cs;

namespace as {
	using namespace std;

	class AlgoClass {
	public:
		list<DeathStranding> objList;

		list<string> chList;

		ifstream fin;
		ofstream fout;

		void countWords(string fromFile, string toFile, string chars) {
			cout << "Trying to open " << fromFile << endl;
			try {
				fin.open(fromFile);
				if (!fin.is_open()) throw 1;
			}
			catch(int) {
				cout << "Can't open " << fromFile << endl;
				terminate();
			}
			fout.open(toFile);
			readFromFile();
			int res = countByChars(chars);
			cout << "Writing answer to " << toFile << endl;
			fout << res;
			chList.clear();
		}

		template<typename T>
		bool isAllTrueFor(list<DeathStranding>::iterator begin, list<DeathStranding>::iterator end, T &lambda) {
			bool flag = true;
			for (list<DeathStranding>::iterator it = begin; it != end; it++) {
				if (!lambda((*it))) flag = false;
			}
			return flag;
		}

		template<typename T>
		list<DeathStranding> copyAllTrueFor(list<DeathStranding>::iterator begin, list<DeathStranding>::iterator end, T& lambda) {
			list<DeathStranding> res;
			for (list<DeathStranding>::iterator it = begin; it != end; it++) {
				if (lambda((*it))) res.push_back(*it);
			}
			return res;
		}

	private:
		
		void readFromFile() {
			while (!fin.eof()) {
				string s;
				fin >> s;
				chList.push_back(s);
			}
		}

		int countByChars(string chars) {
			int result = 0;
			for (list<string>::iterator it = chList.begin(); it != chList.end(); it++) {
				cout << "Finding \"" << chars << "\" in \"" << *it << "\"" << endl;
				vector<int> flags(chars.size(), 0);
				for (int i = 0; i < (*it).size(); i++) {
					
					for (int j = 0; j < chars.size(); j++) {
						if ((*it)[i] == chars[j]) {
							flags[j]++;
						}
					}
				}
				bool wordFlag = true;
				for (auto flag : flags) {
					if (flag == 0) wordFlag = false;
				}
				if (wordFlag) {
					result++;
					cout << "true" << endl;
				}
				else {
					cout << "false" << endl;
				}
			}
			return result;
		}


	};
}