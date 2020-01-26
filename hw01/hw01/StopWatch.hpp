//
//  StopWatch.hpp
//  hw01
//
//  Created by Sarah Carter on 1/25/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef StopWatch_hpp
#define StopWatch_hpp

#include <stdio.h>
#include <iostream>
#include <chrono>
#include <ctime>

class StopWatch{
public:
    StopWatch();
    time_t start();
    time_t stop();
private:
    std::time_t _start;
    std::time_t _end;
};

#endif /* StopWatch_hpp */
