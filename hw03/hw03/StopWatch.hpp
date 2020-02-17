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
    //default constructor
    StopWatch();
    //Method to restart clock
    std::chrono::time_point<std::chrono::system_clock> setStart();
    //Method to stop the clock
    std::chrono::time_point<std::chrono::system_clock> setStop();
    //Convert the time point that the clock stopped into time_t format
    std::time_t stopTime(std::chrono::time_point<std::chrono::system_clock> end_read);
    //Calculate the duration
    std::chrono::duration<double> getDiff(std::chrono::time_point
                                          <std::chrono::system_clock> end);
    //Convert the duration in seconds and milliseconds to a double
    double seconds(std::chrono::duration<double> read_diff);
    double milliseconds(std::chrono::duration<double> read_diff);
private:
    std::chrono::time_point<std::chrono::system_clock> _start;
    std::chrono::time_point<std::chrono::system_clock> _end;
};

#endif /* StopWatch_hpp */
