//
//  complex.cpp
//  Lab08
//
//  Created by Sarah Carter on 3/26/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "complex.hpp"

Complex::Complex() {}

Complex::Complex(double real, double imag)
: real_(real), imag_(imag)
{
}

std::ostream& operator<<(std::ostream& os, const Complex& c){
    os << c.realNum();
    os << " + i ";
    os << c.imagNum();
    return os;
}

