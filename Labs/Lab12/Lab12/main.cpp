//
//  main.cpp
//  Lab12
//  Sarah Carter
//  CS202
//

#include <iostream>

//[x] Write Base Class with two functions, one virtual
//[ ] Write Derived Class with two functions, one virtual
//[ ] Test Base pointer to Base class object
//[ ] Test Bese pointer to Derived class object
//[ ] Test Derived pointer to Derived class object
//[ ] Test Base class reference to Base class object
//[ ] Test Base class reference to Derived class object
//[ ] Test Derived class reference to Derived class object

class Horse {
public:
    Horse() { std::cout << "Horse::Horse constructor\n"; }
    ~Horse() { std::cout << "Horse::~Horse destructor\n"; }
    
    void function1() { std::cout << "Horse::function1() - basic horse\n"; }
    virtual void function2() { std::cout << "Horse::function2() - fancy virtual horse!\n"; }
};

void printDivider() {
    std::cout << "---------------------------\n";
}

int main(int argc, const char * argv[]) {
    { Horse b; b.function1(); b.function2(); }
    printDivider();
    
    return 0;
}
