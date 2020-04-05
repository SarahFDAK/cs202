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

int main(int argc, const char * argv[]) {
    unsigned int n = 6;
    std::cout << fib(n) << "\n";
    return 0;
}
