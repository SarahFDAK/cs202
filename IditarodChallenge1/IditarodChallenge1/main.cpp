//
//  main.cpp
//  IditarodChallenge1
//
//  Created by Sarah Carter on 4/5/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>

unsigned int fib(unsigned int n){
    if(n < 2){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

unsigned int fib_loop(unsigned int n){
    int count = 0;
    int f = 0;
    int f1 = 1;
    int f2 = 0;
    if(n < 2){
        return n;
    }
    else{
        while(count <= n-2){
            f2 = f + f1;
            f = f1;
            f1 = f2;
            count++;
        }
    }
    return f2;
}

unsigned int factorial(unsigned int n){
    if(n < 2){
        return 1;
    }
    return n * factorial(n-1);
}

unsigned int factorial_loop(unsigned int n){
    int count = 2;
    int ft = 1;
    int ft1 = 1;
    if(n < 2)
        return 1;
    while(count <= n){
        ft1 = count * ft;
        ft = ft1;
        count++;
    }
    return ft1;
}

int main(int argc, const char * argv[]) {
    unsigned int n = 7;
    std::cout << "The number in the Fibonacci sequence at " << n << " is " <<
        fib(n) << "\n";
    std::cout << "The number in the non-recursive Fibonacci sequence function at "
        << n << " is " << fib_loop(n) << "\n";
    std::cout << n << " factorial is " << factorial(n)<< "\n";
    std::cout << n << " factorial (non-recursive) is " << factorial_loop(n)
        << "\n";
    return 0;
}
