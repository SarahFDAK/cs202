//
//  main.cpp
//  lab06
//
//  Created by Sarah Carter on 2/13/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>

#include "names.hpp"

//void foo(){
//    std::cout << "This is just the function foo." << std::endl;
//}

int main(int argc, const char * argv[]) {
    myNameSpace::foo();
    ::foo();
    NoName myNum;
    myNum.aNum();
//    foo();
    return 0;
}
