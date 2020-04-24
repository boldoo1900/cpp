#include <iostream>

using namespace std;

class B {
public:
    const int b;
    void print() {
        cout << b << "\n";
    }
};

class A {
    B value;

public:

    A(B* y) : value(*y) {
    }

    A get_copy() const {
        value.print();     //error
        return A(&value);  //error
    }
};


