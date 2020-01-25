//
//  labClass.hpp
//  lab02
//
//  Created by Sarah Carter on 1/23/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef labClass_hpp
#define labClass_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class LabClass{
public:
    LabClass();
    LabClass(int userInt);
    LabClass(const LabClass &copy);
    int getCopy();
    int getCopy() const;
    ~LabClass();
private:
    int _test;
};

#endif /* labClass_hpp */
