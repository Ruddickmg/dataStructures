#include <iostream>
#include "Employee.h"
#include "HashTable.cpp"

using namespace std;

void check (HashTable<Employee> h, Employee e, string s) {
    
    cout << s << " is " << (h.contains(e) ? "in" : "not in") << " the hash table" << endl;
}

int main() {

    cout << endl;

    HashTable<Employee> h1;

    Employee e1("abc", 10, 1);
    Employee e2("def", 11, 2);
    Employee e3("ghi", 12, 3);
    Employee e4("jkl", 13, 4);

    h1.insert(e1);
    h1.insert(e2);
    h1.insert(e3);

    cout << endl;

    check(h1, e1, "E1");
    check(h1, e4, "E4");

    h1.remove(e1);

    check(h1, e1, "E1");
    check(h1, e2, "E2");

    cout << endl << "--<==> fin <==>--" << endl;
};