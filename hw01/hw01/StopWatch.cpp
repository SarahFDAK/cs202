//
//  StopWatch.cpp
//  hw01
//
//  Created by Sarah Carter on 1/25/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "StopWatch.hpp"
std::chrono::time_point<std::chrono::system_clock> timeStamp =
    std::chrono::system_clock::now();

StopWatch::StopWatch(): _start(){
    std::cout << "Default constructor" << std::endl;
    _start = timeStamp;
};
std::chrono::time_point<std::chrono::system_clock> StopWatch::setStart(){
    _start = timeStamp;
    return _start;
}

std::chrono::time_point<std::chrono::system_clock> StopWatch::setStop(){
    _end = timeStamp;
    return _end;
}

std::time_t StopWatch::stopTime(std::chrono::time_point<std::chrono::system_clock>
                                end_read){
    _end = end_read;
    return std::chrono::system_clock::to_time_t(_end);
}

//std::chrono::duration<double> StopWatch::getDiff(){
//    _diff = _end -  _start;
//    return _diff;
//}

double StopWatch::seconds(std::chrono::duration<double> read_diff){
    return std::chrono::duration<double>(read_diff).count();
}

double StopWatch::milliseconds(std::chrono::duration<double> read_diff){
    return std::chrono::duration<double, std::milli>(read_diff).count();
}
