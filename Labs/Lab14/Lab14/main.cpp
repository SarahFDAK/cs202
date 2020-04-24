//
//  main.cpp
//  Lab14
//
//  Created by Sarah Carter on 4/23/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <cmath>

//[x] Write a function template 'twice'
//[x] Test it with an int and a double
//[x] Test iwth with a C++ string
//[x] Fix it to work with a C string
//[x] Write a TVector3 class that uses template function for operator<<
//[x] Write normalize and length functions for TVector3 class
//[ ] Write dot, cross  functions for TVector3 class

template <typename T>
T twice(const T& x){
    return x + x;
}

std::string twice(const char* x){
    return twice(std::string(x));
}

template <typename T>
class TVector3 {
public:
    T x{};
    T y{};
    T z{};
    
    TVector3() {}
    TVector3(T x, T y, T z) : x(x), y(y), z(z) {}
    
    TVector3& operator *=(T s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const TVector3<T>& v){
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

template <typename T>
T length(TVector3<T> v) {
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

template <typename T>
TVector3<T> normalize(TVector3<T> v){
    T l = length(v);
    TVector3<T> result = v;
    v *= 1 / l;
    return v;
}

int main(int argc, const char * argv[]) {
    std::cout << twice(2) << std::endl;
    std::cout << twice(4.6) << std::endl;
    std::cout << twice(std::string("Vincent Twice")) << std::endl;
    std::cout << twice("Vincent Twice") << std::endl;
    
    TVector3<float> v1 { 1, 2, 3 };
    auto v2 = normalize(v1);
    std::cout << v1 << std::endl;
    std::cout << "Length of v1 = " << length(v1) << std::endl;
    std::cout << "Normalize v1 = " << v2 << std::endl;
    std::cout << "Length of v2 = " << length(v2) << std::endl;
    return 0;
}
