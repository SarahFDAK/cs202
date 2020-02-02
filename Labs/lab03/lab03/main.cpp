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
    cout << "Creating raw pointer: " << endl;
    LabClass* myPtr = new LabClass;
    cout << myPtr << endl;
    myPtr -> ~LabClass();
    return 0;
}
