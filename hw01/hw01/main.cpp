//
//  main.cpp
//  hw01
//
//  Created by Sarah Carter on 1/24/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <random>

#include "StopWatch.hpp"
#include "algorithms.hpp"

void fillVector(std::mt19937 gen, std::uniform_int_distribution<> dis, int items, std::vector<int> &holder){
    for(int i = 0; i < items; i++){
        holder.push_back(dis(gen));
    }
}

void reportResults(StopWatch myClock, int items){

    auto endTime = std::chrono::system_clock::to_time_t(myClock.setStop());
    auto myDiff = myClock.getDiff(myClock.setStop());
    double time_in_seconds = myClock.seconds(myDiff);
    double time_in_milli = myClock.milliseconds(myDiff);
    std::cout << "Completed " << items << " items at: " << std::ctime(&endTime)
    << " in " << time_in_seconds << " seconds and " << time_in_milli
    << " milliseconds." <<std::endl;
}

int main(int argc, const char * argv[]) {
    StopWatch myClock;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,150);
    
    std::vector<int> holder;
    
    fillVector(gen, dis, 10, holder);
    reportResults(myClock, 10);
    
    fillVector(gen, dis, 100, holder);
    reportResults(myClock, 100);
    
    fillVector(gen, dis, 1000, holder);
    reportResults(myClock, 1000);
    
    fillVector(gen, dis, 10000, holder);
    reportResults(myClock, 10000);
    
    fillVector(gen, dis, 1000000, holder);
    reportResults(myClock, 100000);
    
    fillVector(gen, dis, 10000000, holder);
    reportResults(myClock, 10000000);
    
    
    return 0;
}
