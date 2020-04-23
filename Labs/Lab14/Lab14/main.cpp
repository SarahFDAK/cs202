//
//  main.cpp
//  Lab14
//
//  Created by Sarah Carter on 4/23/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>

//[x] Write a function template 'twice'
//[x] Test it with an int and a double
//[x] Test iwth with a C++ string
//[x] Fix it to work with a C string

template <typename T>
T twice(const T& x){
    return x + x;
}

std::string twice(const char* x){
    return twice(std::string(x));
}

int main(int argc, const char * argv[]) {
    std::cout << twice(2) << std::endl;
    std::cout << twice(4.6) << std::endl;
    std::cout << twice(std::string("Vincent Twice")) << std::endl;
    std::cout << twice("Vincent Twice") << std::endl;
    
    return 0;
}
