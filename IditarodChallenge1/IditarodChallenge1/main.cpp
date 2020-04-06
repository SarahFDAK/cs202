//
//  main.cpp
//  IditarodChallenge1
//  Sarah Carter
//  4/5/20
//  This code includes functions to report nth number in a Fibonacci sequence both
//  recursively and non-recursively, and does that same for that number's factorial.

#include <iostream>


//Recursive Fibonacci function
unsigned int fib(unsigned int n){
    if(n < 2){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

//Non-recursive Fibonacci function
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

//Recursive factorial function
unsigned int factorial(unsigned int n){
    if(n < 2){
        return 1;
    }
    return n * factorial(n-1);
}

//Non-recursive factorial function
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
    int n = 0;
    //Get integer from user, set to n
    std::cout << "Enter a positive integer: \n";
    std::cin >> n;
    if(n < 0){
        std::cout << "I asked for a positive integer. Goodbye. \n";
        return 0;
    }
    
    //Find nth number in Fibonacci sequence
    std::cout << "Fibonacci sequence at " << n << " is " << fib(n) << "\n";
    std::cout << "Non-recursive Fibonacci sequence function at "
        << n << " is " << fib_loop(n) << "\n";
    
    //Find n factorial
    std::cout << n << " factorial is " << factorial(n)<< "\n";
    std::cout << n << " factorial (non-recursive) is " << factorial_loop(n)
        << "\n";
    
    return 0;
}
