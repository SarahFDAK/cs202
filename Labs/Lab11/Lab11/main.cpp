//
//  CS202 Lab11
//  Sarah Carter
//  Inheritance demonstration
//

#include <iostream>

using std::cout;
using std::endl;

// [x] A default base class object
// [x] A base class object using the one parameter constructor
// [x] A default derived class object
// [ ] A derived class object using the two parameter constructor

//Base class
class Base {
public:
    Base()
        : ccs_ { 1000 } {
        cout << "Constructing a default base class object with a " << ccs_
            << " cc engine" << endl;
    }
            
    Base(int engine)
        : ccs_{ engine }{
        cout << "Constructing a base class object with one parameter constructor of a "
            << ccs_ << " cc engine." << endl;
    }
    
    
    ~Base() {
        cout << "Destrucing the default base class object with a " << ccs_
            << " cc engine." << endl;
    }
private:
    int ccs_;
};
            
class Derived : public Base{
public:
    Derived()
            : Base{ 750 }, brand_{ "Suzuki" }{
        cout << "Constructing derived object with brand " << brand_ << endl;
    }
    ~Derived(){
        cout << "Destructing derived object with brand " << brand_ << endl;
    }
            
private:
    std::string brand_;
};

int main(int argc, const char * argv[]) {
    { Base b; }
    cout << endl;
    
    { Base b{ 500 };}
    cout << endl;
            
    { Derived d; }
    cout << endl;
    return 0;
}
