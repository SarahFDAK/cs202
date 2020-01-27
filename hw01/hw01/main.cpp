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

void fillVector(std::mt19937 gen, std::uniform_int_distribution<> dis, int items, std::vector<int> &holder, std::vector<int> &randNum){
    for(int i = 0; i < items; i++){
        holder.push_back(dis(gen));
    }
    randNum.push_back(dis(gen));
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

void testSortSpeed(StopWatch &myClock, std::vector<int> &holder){
    std::cout << "Sort\n";
    myClock.setStart();
    basicSort(holder);
}

void testSearchSpeed(StopWatch &myClock, std::vector<int> &holder, std::vector<int> &randNum){
    std::cout << "Search\n";
    myClock.setStart();
    sequentialSearch(holder, randNum);
}

void testBSearchSpeed(StopWatch &myClock, std::vector<int> &holder, std::vector<int> &randNum){
    std::cout << "Binary Search\n";
    myClock.setStart();
    binarySearch(holder, randNum);
}

void testReverseSpeed(StopWatch &myClock, std::vector<int> &holder){
    std::cout << "Reverse\n";
    myClock.setStart();
    reverse(holder);
}

int main(int argc, const char * argv[]) {
    StopWatch myClock;
    int ten = 10;
    int hundred = 100;
    int thousand = 1000;
    int tenthousand = 10000;
    int million = 1000000;
    int tenmillion = 10000000;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,150);
    
    std::vector<int> holder;
    std::vector<int> randNum;
    
    fillVector(gen, dis, ten, holder, randNum);
    testSortSpeed(myClock, holder);
    reportResults(myClock, ten);
    testSearchSpeed(myClock, holder, randNum);
    reportResults(myClock, ten);
    testBSearchSpeed(myClock, holder, randNum);
    reportResults(myClock, ten);
    testReverseSpeed(myClock, holder);
    reportResults(myClock, ten);
    
    fillVector(gen, dis, hundred, holder, randNum);
    testSortSpeed(myClock, holder);
    reportResults(myClock, hundred);
    testSearchSpeed(myClock, holder, randNum);
    reportResults(myClock, hundred);
    testBSearchSpeed(myClock, holder, randNum);
    reportResults(myClock, hundred);
    testReverseSpeed(myClock, holder);
    reportResults(myClock, hundred);
    
    fillVector(gen, dis, thousand, holder, randNum);
    testSortSpeed(myClock, holder);
    reportResults(myClock, thousand);
    testSearchSpeed(myClock, holder, randNum);
    reportResults(myClock, thousand);
    testBSearchSpeed(myClock, holder, randNum);
    reportResults(myClock, thousand);
    testReverseSpeed(myClock, holder);
    reportResults(myClock, thousand);
    
    fillVector(gen, dis, tenthousand, holder, randNum);
    testSortSpeed(myClock, holder);
    reportResults(myClock, tenthousand);
    testSearchSpeed(myClock, holder, randNum);
    reportResults(myClock, tenthousand);
    testBSearchSpeed(myClock, holder, randNum);
    reportResults(myClock, tenthousand);
    testReverseSpeed(myClock, holder);
    reportResults(myClock, tenthousand);
    
    fillVector(gen, dis, million, holder, randNum);
    testSortSpeed(myClock, holder);
    reportResults(myClock, million);
    testSearchSpeed(myClock, holder, randNum);
    reportResults(myClock, million);
    testBSearchSpeed(myClock, holder, randNum);
    reportResults(myClock, million);
    testReverseSpeed(myClock, holder);
    reportResults(myClock, million);
    
    fillVector(gen, dis, tenmillion, holder, randNum);
    testSortSpeed(myClock, holder);
    reportResults(myClock, tenmillion);
    testSearchSpeed(myClock, holder, randNum);
    reportResults(myClock, tenmillion);
    testBSearchSpeed(myClock, holder, randNum);
    reportResults(myClock, tenmillion);
    testReverseSpeed(myClock, holder);
    reportResults(myClock, tenmillion);
    
    return 0;
}
