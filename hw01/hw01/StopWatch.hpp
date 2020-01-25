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
    
private:
    std::time_t _start;
};

#endif /* StopWatch_hpp */
