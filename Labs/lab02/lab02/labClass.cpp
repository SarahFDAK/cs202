//
//  labClass.cpp
//  lab02
//
//  Created by Sarah Carter on 1/23/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "labClass.hpp"

LabClass::LabClass(): _test(0){
    std::cout << "Default constructor\n";
}

LabClass::LabClass(int userInt){
    _test = userInt;
    std::cout << "User defined constructor\n";
};

LabClass::LabClass(const LabClass &copy){
    _test = copy._test;
    std::cout << "Copy constructor\n";
}

int LabClass::getCopy(){
    std::cout << "Get copy\n";
    return _test;
}

int LabClass::getCopy() const {
    std::cout << "Get copy const\n";
    return _test;
}

LabClass::~LabClass(){
    std::cout << "Destructor\n";
};
