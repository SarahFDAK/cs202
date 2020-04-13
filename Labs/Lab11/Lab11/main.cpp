//
//  CS202 Lab11
//  Sarah Carter
//  Inheritance demonstration
//

#include <iostream>

using std::cout;
using std::endl;

// [ ] A default base class object
// [ ] A base class object using the one parameter constructor
// [ ] A default derived class object
// [ ] A derived class object using the two parameter constructor

//Base class
class Base {
public:
    Base()
        : ccs_ { 1000 } {
        cout << "Constructing a default base class object with a " << ccs_
            << " cc engine" << endl;
    }
    
    
    ~Base() {
        cout << "Destrucing the default base class object with a " << ccs_
            << " cc engine." << endl;
    }
private:
    int ccs_;
};

int main(int argc, const char * argv[]) {
            { Base b; }
            cout << endl;
            
    return 0;
}
