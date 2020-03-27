//
//  complex.hpp
//  Lab08
//
//  Created by Sarah Carter on 3/26/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef complex_hpp
#define complex_hpp

#include <stdio.h>
#include <iostream>

class Complex {
public:
    Complex();
    Complex(double real, double imag = 0);
    
    Complex operator+(const Complex c);
    Complex& operator+=(const Complex c);
    
    double realNum() const { return real_; }
    double imagNum() const { return imag_; }
    
private:
    double real_{ 0 };
    double imag_{ 0 };
};

inline Complex operator+(double lhs, const Complex rhs){
    return Complex(lhs + rhs.realNum(), rhs.imagNum());
}

std::ostream& operator<<(std::ostream& os, const Complex& c);

#endif /* complex_hpp */
