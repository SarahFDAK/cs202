//
//  main.cpp
//  hw01
//
//  Created by Sarah Carter on 1/24/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <vector>

#include "StopWatch.hpp"

int main(int argc, const char * argv[]) {
    StopWatch myClock;
    std::vector<int> holder;
    for(int i = 0; i < 500; i++){
        holder.push_back(i);
    }
    auto endTime = std::chrono::system_clock::to_time_t(myClock.setStop());
    auto myDiff = myClock.getDiff(myClock.setStop());
    double time_in_seconds = myClock.seconds(myDiff);
    double time_in_milli = myClock.milliseconds(myDiff);
    std::cout << "Completed at: " << std::ctime(&endTime) << " in " << time_in_seconds
    << " seconds and " << time_in_milli << " milliseconds." <<std::endl;
    return 0;
}
