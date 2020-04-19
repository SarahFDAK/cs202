//
//  main.cpp
//  Lab12
//  Sarah Carter
//  CS202
//

#include <iostream>

//[x] Write Base Class with two functions, one virtual
//[x] Write Derived Class with two functions, one virtual
//[x] Test Base pointer to Base class object
//[x] Test Bese pointer to Derived class object
//[ ] Test Derived pointer to Derived class object
//[ ] Test Base class reference to Base class object
//[ ] Test Base class reference to Derived class object
//[ ] Test Derived class reference to Derived class object

class Horse {
public:
    Horse() { std::cout << "Horse::Horse on a farm\n"; }
    virtual ~Horse() { std::cout << "Horse::~Horse left the farm\n"; }
    
    void function1() { std::cout << "Horse::function1() - basic horse\n"; }
    virtual void function2() { std::cout << "Horse::function2() - literally a carthorse\n"; }
};

class RaceHorse : public Horse {
public:
    RaceHorse() { std::cout << "RaceHorse::RaceHorse won the Derby!\n"; }
    ~RaceHorse() { std::cout << "RaceHorse::~RaceHorse came in tenth...\n"; }
    
    void function1() { std::cout << "RaceHorse::function1() - Fancy racehorse\n"; }
    void function2() override { std::cout << "RaceHorse::function2() - Thoroughbred\n"; }
};

void TestBasePointer() {
    Horse pony;
    { Horse* pp = &pony;
        pp->function1();
        pp->function2();
    }
    RaceHorse speedy;
    { Horse* pp = &speedy;
        pp->function1();
        pp->function2();
    }
    
    { RaceHorse* rp = &speedy;
        rp->function1();
        rp->function2();
    }
}


void printDivider() {
    std::cout << "---------------------------\n";
}

int main(int argc, const char * argv[]) {
    { Horse b; b.function1(); b.function2(); }
    printDivider();
    
    { RaceHorse d; d.function1(); d.function2(); }
    printDivider();
    
    TestBasePointer();
    printDivider();
    return 0;
}
