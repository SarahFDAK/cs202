//
//  main.cpp
//  Lab08
//
//  Created by Sarah Carter on 3/26/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "complex.hpp"

int main(int argc, const char * argv[]) {
    std::cout << Complex() << "\n";
    std::cout << Complex(2,3) << "\n";
    std::cout << 1.0 + Complex() << "\n";
    
    Complex c(5, 4);
    Complex d(10, 3);
    std::cout << c << "\n";
    std::cout << d << "\n";
    c += d;
    std::cout << c << "\n";
    return 0;
}
