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

Complex Complex::operator+(const Complex c){
    return Complex(real_ + c.realNum(), imag_ + c.imagNum());
}

Complex& Complex::operator+=(const Complex c){
    *this = *this + c;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& c){
    os << c.realNum();
    os << " + i ";
    os << c.imagNum();
    return os;
}

