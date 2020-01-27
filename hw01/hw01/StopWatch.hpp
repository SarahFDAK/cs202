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
    std::chrono::time_point<std::chrono::system_clock> setStart();
    std::chrono::time_point<std::chrono::system_clock> setStop();
    std::time_t stopTime(std::chrono::time_point<std::chrono::system_clock> end_read);
    std::chrono::duration<double> getDiff();
    double seconds(std::chrono::duration<double> read_diff);
    double milliseconds(std::chrono::duration<double> read_diff);
private:
    std::chrono::time_point<std::chrono::system_clock> _start;
    std::chrono::time_point<std::chrono::system_clock> _end;
    std::chrono::duration<double> _diff;
};

#endif /* StopWatch_hpp */
