//
//  main.cpp
//  IditarodChallenge2
//
//  Created by Sarah Carter on 4/6/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>

int ack(int m, int n){
    if(m == 0)
        return n + 1;
    else if(m > 0 && n == 0)
        return ack(m - 1, 1);
    return ack(m - 1, ack(m, n - 1));
}

int main(int argc, const char * argv[]) {
    std::cout << ack(0, 0) << "\n";
    return 0;
}
