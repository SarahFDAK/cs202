//
//  main.cpp
//  hw01
//
//  Created by Sarah Carter on 1/24/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>

#include "StopWatch.hpp"

int main(int argc, const char * argv[]) {
    StopWatch startTime;
    std::cout << "Test" << std::endl;
    auto endTime = startTime.start();
    std::cout << endTime << std::endl;

    return 0;
}
