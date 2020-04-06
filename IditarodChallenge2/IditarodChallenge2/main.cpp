//
//  main.cpp
//  IditarodChallenge2
//  Sarah Carter
//  4/6/20
//  This program runs a recursive function to calculate Ackermann's number
//  and times the output.

#include <iostream>
#include "StopWatch.hpp"

//Recursive Ackermann's function
int ack(int m, int n){
    if(m == 0)
        return n + 1;
    else if(m > 0 && n == 0)
        return ack(m - 1, 1);
    return ack(m - 1, ack(m, n - 1));
}

//Calculate time elapsed and report results
void reportResults(StopWatch myClock, const int a){
    auto myDiff = myClock.getDiff(myClock.setStop());
    double time_in_seconds = myClock.seconds(myDiff);
    double time_in_milli = myClock.milliseconds(myDiff);
    std::cout << "Calculated " << a << " in " << time_in_seconds << " seconds and "
        << time_in_milli << " milliseconds." << std::endl;
}

int main(int argc, const char * argv[]) {
    StopWatch timer;
    timer.setStart();
    reportResults(timer, ack(4,1));
    return 0;
}
