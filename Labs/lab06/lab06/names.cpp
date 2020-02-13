//
//  names.cpp
//  lab06
//
//  Created by Sarah Carter on 2/13/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>

#include "names.hpp"

void myNameSpace::foo(){
    std::cout << "This is my namespace." << std::endl;
}

void NoName::aNum(){
    std::cout << x << std::endl;
}
