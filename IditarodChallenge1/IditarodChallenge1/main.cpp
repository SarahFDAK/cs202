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

int main(int argc, const char * argv[]) {
    unsigned int n = 7;
    std::cout << fib(n) << "\n";
    std::cout << fib_loop(n) << "\n";
    return 0;
}
