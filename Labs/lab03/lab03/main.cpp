//
//  main.cpp
//  lab03
//
//  Created by Sarah Carter on 2/2/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include "labClass.hpp"

using std::cout;
using std::endl;



int main(int argc, const char * argv[]) {
    
    cout << "Creating raw pointer:\n";
    LabClass* myPtr = new LabClass;
    cout << myPtr -> getCopy() << endl;
    //You can see that this pointer is created, but I don't see anywhere that it is
    //de-allocated. If I manually call the destructor here, it will be.
    
    cout << "Create unique pointer:\n";
    auto myPtr2 = std::make_unique<LabClass>(5);
    cout << myPtr2 << " unique pointer address\n\n";
    
    cout << "Transferring unique pointer ownership:\n";
    auto myPtr3 = std::move(myPtr2);
    cout << myPtr3 << " transferred ownership address\n\n";
    //Printing the first unique pointer address, moving it, and then printing the
    //second shows that the ownership of the address was moved to the new pointer.
    
    cout << "Create shared pointer:\n";
    auto mySPtr = std::make_shared<LabClass>(12);
    std::shared_ptr<LabClass> mySPtr2(mySPtr);
    cout << mySPtr << " is first shared pointer address and\n" <<
    mySPtr << " is the second shared pointer address\n\n";
    //These printed lines show that the original shared address was copied to the
    //second shared address. I am not sure the unique pointer from before was
    //de-allocated, unless the one destructor line is for the unique pointer and
    //the other is for the two shared pointers de-allocating at once.
    
    return 0;
}
