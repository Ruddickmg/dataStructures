#include <iostream>
#include "SkipList.h"

using namespace std;

int main() {

    int maxLevels = 4, maxKey = 999999999, lowestKey = 0;
    int thing1, thing2, thing3;

    SkipList<int> list { maxLevels, maxKey, lowestKey };

    cout << endl << "Pre insertion: " << list << endl;

    thing1 = list.insert(888);
    thing2 = list.insert(5);
    thing3 = list.insert(80);

    cout << endl << "Post: " << list << endl;
    //list.printAllUpdates();

    list.remove(thing1);

    cout << endl << "after delete of thing #1, key: " << thing1 << ", " << std::endl  << list << endl;
    //list.printAllUpdates();

    cout << endl << "find thing #3: " << list.find(thing3) << endl << endl;

    list.remove(thing2);

    cout << "delete thing #2, key: " << thing2 << ", " << std::endl << list << endl;
    //list.printAllUpdates();



    return 0;
}

