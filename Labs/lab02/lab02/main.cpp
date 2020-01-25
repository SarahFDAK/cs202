//
//  main.cpp
//  lab02
//
//  Created by Sarah Carter on 1/23/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <sstream>
#include <vector>

#include "labClass.hpp"

void passVal(LabClass myObj){
    std::cout << myObj.getCopy();
}

void passRef(LabClass &myObj){
    std::cout << myObj.getCopy() << std::endl;
}

void passRefToConst(const LabClass &myObj){
    std::cout << myObj.getCopy() << std::endl;
}

LabClass returnByValue(){
    std::cout << "Returning by value\n";
    return LabClass(9);
}

int main(int argc, const char * argv[]) {
    int myInt;
    std::cout << "Please enter an integer: " << std::endl;
    std::cin >> myInt;
    LabClass tester(myInt);
    passVal(tester);
    passRef(tester);
    passRefToConst(tester);
    LabClass a;
    LabClass b(a);
    std::vector<LabClass> myVec (5, tester);
    for(auto &i: myVec){
        std::cout << i.getCopy() << "\n";
    }
    std::cout << "Before PBV\n";
    LabClass c = returnByValue();
    std::cout << "After PBV\n";
    return 0;
}
