#include <iostream>
#include "Stack.h"
#include "DeathStranding.h"

using namespace std;
int main()
{
    Stack<DeathStranding> s;
    int size;
    cout << "enter size: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        int level, time, id;
        DeathStranding obj;
        cin >> level >> time >> id;
        obj.setId(id);
        obj.setTime(time);
        obj.setLevel(level);
        if (!s.push(obj, true)) i--;
    }

    s.watch();
    s.insSort();
    s.watch();
    cout << "find: ";
    int level, time, id;
    DeathStranding obj;
    cin >> level >> time >> id;
    obj.setId(id);
    obj.setTime(time);
    obj.setLevel(level);
    if (s.find(obj) != NULL) {
        cout << "exist" << endl;
        cout << "deleted\n";
    }
    else cout << "doesn't exist\n";
    s.del(obj);
    if (s.find(obj) != NULL) cout << "exist" << endl;
    else cout << "doesn't exist\n";
    s.watch();
}
