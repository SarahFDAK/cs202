//
//  main.cpp
//  IditarodChallenge2
//
//  Created by Sarah Carter on 4/6/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include "StopWatch.hpp"

int ack(int m, int n){
    if(m == 0)
        return n + 1;
    else if(m > 0 && n == 0)
        return ack(m - 1, 1);
    return ack(m - 1, ack(m, n - 1));
}

void reportResults(StopWatch myClock, const int a){
    auto myDiff = myClock.getDiff(myClock.setStop());
    double time_in_seconds = myClock.seconds(myDiff);
    std::cout << "Calculated " << a << " in " << time_in_seconds << " seconds" << std::endl;
}

int main(int argc, const char * argv[]) {
    StopWatch timer;
    timer.setStart();
    reportResults(timer, ack(4,4));
    return 0;
}
