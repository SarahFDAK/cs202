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
    
    cout << "Create unique pointer:\n";
    auto myPtr2 = std::make_unique<LabClass>(5);
    cout << myPtr2 << " unique pointer address\n\n";
    
    cout << "Transferring unique pointer ownership:\n";
    auto myPtr3 = std::move(myPtr2);
    cout << myPtr3 << " transferred ownership address\n\n";
    
    cout << "Create shared pointer:\n";
    auto mySPtr = std::make_shared<LabClass>(12);
    std::shared_ptr<LabClass> mySPtr2(mySPtr);
    cout << mySPtr << " is first shared pointer address and\n" <<
    mySPtr << " is the second shared pointer address\n\n";
    return 0;
}
