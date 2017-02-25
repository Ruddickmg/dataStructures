#include <iostream>
#include "lab6.h"

using namespace std;

int main() {

    lab6<int> l6;

    if (l6.isEmpty())

        cout << "empty" << endl;

    else cout << "not empty" << endl;

    l6.push(6);

    l6.print();

    if(l6.isEmpty())

        cout << "empty" << endl;

    else cout << "not empty" << endl;

    l6.push(8);
    l6.push(9);
    l6.push(3);
    l6.print();

    cout << "min: " << l6.getMin() << endl;

    l6.push(2);
    l6.push(1);

    cout << "min: " << l6.getMin() << endl;

    l6.print();

    cout << "pop: " << l6.pop() << endl;
    cout << "pop: " << l6.pop() << endl;
    cout << "pop: " << l6.pop() << endl;

    cout << "min: " << l6.getMin() << endl;

    cout << "top: " << l6.top() << endl;
    
    l6.print();

    return 0;
}