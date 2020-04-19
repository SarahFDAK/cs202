//
//  main.cpp
//  Lab12
//  Sarah Carter
//  CS202
//

#include <iostream>

//[ ] Write Base Class with two functions, one virtual
//[ ] Write Derived Class with two functions, one virtual
//[ ] Test Base pointer to Base class object
//[ ] Test Bese pointer to Derived class object
//[ ] Test Derived pointer to Derived class object
//[ ] Test Base class reference to Base class object
//[ ] Test Base class reference to Derived class object
//[ ] Test Derived class reference to Derived class object

class Base {
public:
    Base() { std::cout << "Base::Base constructor\n"; }
    ~Base() { std::cout << "Base::~Base destructor\n"; }
    
    void function1() { std::cout << "Base::function1() - non virtual\n"; }
    virtual void function2() { std::cout << "Base::function2() - virtual\n"; }
};

void printDivider() {
    std::cout << "---------------------------\n";
}

int main(int argc, const char * argv[]) {
    { Base b; b.function1(); b.function2(); }
    printDivider();
    
    return 0;
}
