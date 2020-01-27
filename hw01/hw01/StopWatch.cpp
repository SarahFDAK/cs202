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
    _start = std::chrono::system_clock::now();
};
std::chrono::time_point<std::chrono::system_clock> StopWatch::setStart(){
    _start = std::chrono::system_clock::now();
    return _start;
}

std::chrono::time_point<std::chrono::system_clock> StopWatch::setStop(){
    _end = std::chrono::system_clock::now();
    return _end;
}

std::time_t StopWatch::stopTime(std::chrono::time_point<std::chrono::system_clock>
                                end_read){
    return std::chrono::system_clock::to_time_t(end_read);
}

std::chrono::duration<double> StopWatch::getDiff(std::chrono::time_point
                                                 <std::chrono::system_clock> end){
    return end - _start;
}

double StopWatch::seconds(std::chrono::duration<double> read_diff){
    return std::chrono::duration<double>(read_diff).count();
}

double StopWatch::milliseconds(std::chrono::duration<double> read_diff){
    return std::chrono::duration<double, std::milli>(read_diff).count();
}
