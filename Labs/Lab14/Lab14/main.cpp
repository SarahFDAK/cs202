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
//[x] Write dot, cross  functions for TVector3 class

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

template <typename T, typename U>
auto dot(TVector3<T> a, TVector3<U> b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

template <typename T, typename U>
auto cross(TVector3<T> a, TVector3<U> b) {
    return TVector3<decltype(a.x * b.x)>{
        a.y * b.z - a.z * b.y, //x
        a.z * b.x - a.x * b.z, //y
        a.x * b.y - a.y * b.x  //z
    };
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
    
    TVector3<double> up { 0, 1, 0 };
    TVector3<double> right { 1, 0, 0 };
    std::cout << "Dot(up, right)   = " << dot(up, right) << std::endl;
    std::cout << "Cross(up, right) = " << cross(up, right) << std::endl;
    std::cout << "Cross(right, up) = " << cross(right, up) << std::endl;
    double angle1 = dot(right, v2) * 180.0 / 3.14159;
    std::cout << "Angle between right and v2 = " << angle1 << std::endl;
    return 0;
}
