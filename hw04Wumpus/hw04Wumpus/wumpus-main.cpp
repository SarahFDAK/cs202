//
//  main.cpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 2/24/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <random>

using std::cout;
using std::endl;

int randNum(int a, int b){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(a, b);
    return dist(gen);
}


int main(int argc, const char * argv[]) {
    
    
    return 0;
}
