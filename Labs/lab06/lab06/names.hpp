//
//  names.hpp
//  lab06
//
//  Created by Sarah Carter on 2/13/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef names_hpp
#define names_hpp

#include <stdio.h>

namespace myNameSpace{
    void foo();
}

namespace {
    void foo(){
        std::cout << "Here is an anonymous namespace" << std::endl;
    }
}

class NoName {
private:
    int x = 3;
public:
    void aNum();
};

#endif /* names_hpp */
