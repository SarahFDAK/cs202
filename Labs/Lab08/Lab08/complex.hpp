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
private:
    double real_{ 0 };
    double imag_{ 0 };
}

#endif /* complex_hpp */
