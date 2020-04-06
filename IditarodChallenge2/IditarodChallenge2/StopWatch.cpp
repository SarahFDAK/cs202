//
//  StopWatch.cpp
//  hw01
//
//  Created by Sarah Carter on 1/25/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "StopWatch.hpp"
//Set the default constructor to set the start time to now
StopWatch::StopWatch(): _start(){
    _start = std::chrono::system_clock::now();
};
//Method to set the start time to now, again
std::chrono::time_point<std::chrono::system_clock> StopWatch::setStart(){
    _start = std::chrono::system_clock::now();
    return _start;
}
//Set the stop time to the relative now
std::chrono::time_point<std::chrono::system_clock> StopWatch::setStop(){
    _end = std::chrono::system_clock::now();
    return _end;
}
//Convert the stop time to time_t
std::time_t StopWatch::stopTime(std::chrono::time_point<std::chrono::system_clock>
                                end_read){
    return std::chrono::system_clock::to_time_t(end_read);
}
//Calculate duration
std::chrono::duration<double> StopWatch::getDiff(std::chrono::time_point
                                                 <std::chrono::system_clock> end){
    return end - _start;
}
//Return duration in seconds
double StopWatch::seconds(std::chrono::duration<double> read_diff){
    return std::chrono::duration<double>(read_diff).count();
}
//Return duration in milliseconds
double StopWatch::milliseconds(std::chrono::duration<double> read_diff){
    return std::chrono::duration<double, std::milli>(read_diff).count();
}
