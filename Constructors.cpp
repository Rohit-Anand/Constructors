//
//  Constructors.cpp
//  Learning_cpp
//
//  Created by Rohit Anand on 23/06/18.
//  Copyright © 2018 Rohit Anand. All rights reserved.
//

// This file is dummy, just to print and monitor the c'Tors, may be used later to introduce
// C'Tors and D'Tors to others

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base default c'tor" << endl;
        a = 10;
    }
    
    Base (const Base& b) {
        cout << "Base Copy Const c'tor" << endl;
    }
    
    Base (Base& b) {
        cout << "Base Copy c'tor" << endl;
    }
    
    Base(Base&& b) {
        cout << "Base Move c'tor" << endl;
        a = b.a;
        b.a = 0;
    }
    
    Base& operator= (Base& b) {
        cout << "operator = Base" << endl;
        return b;
    }
    
    virtual void fun() const {
        cout << "Base Fun: " << a << endl;
    }
    
    int a;

    Base(const Base&& b) {
        cout << "Base const Move c'tor" << endl;
        a = b.a;
    }
};

class Derived : public Base {
public:
    void fun() const {
        cout << "Derived Fun" << endl;
    }
};

int main() {
    const Base b;
    cout << " -- --- " << endl;
    Base b1(b);
    cout << " -- --- " << endl;
    Base b2(std::move(b));
    cout << " -- --- " << endl;
    b.fun();
    b2.fun();
    
    
    Derived d;
    d.fun();
    cout << " -- bD --- " << endl;
    Base* b3 = new Derived();
    b3->fun();

    return 0;
}
