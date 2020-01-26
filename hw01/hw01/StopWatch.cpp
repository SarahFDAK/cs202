//
//  StopWatch.cpp
//  hw01
//
//  Created by Sarah Carter on 1/25/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "StopWatch.hpp"

StopWatch::StopWatch(): _start(){
    std::cout << "Default constructor" << std::endl;
};
std::time_t StopWatch::start(){
    _start = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    return _start;
}
