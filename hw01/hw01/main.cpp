//
//  main.cpp
//  Sarah Carter
//  1/27/20
//  This program fills a vector with pseudo-random numbers, then times how
//  long it takes to sort, search, binary search, and reverse this vector.
//  The algorithms were timed for six different numbers of items.
//

#include <random>

#include "StopWatch.hpp"
#include "algorithms.hpp"

//Fill the main vector with random ints, then populate the randNum vector with a
//single random int.
void fillVector(std::mt19937 gen, std::uniform_int_distribution<> dis, int items, std::vector<int> &holder, std::vector<int> &randNum){
    for(int i = 0; i < items; i++){
        holder.push_back(dis(gen));
    }
    randNum.push_back(dis(gen));
}

//Stop the timer, calculate the duration and save the end time, then print out
//the details - now many items were processed, what time it finished, and how
//long it took in seconds and milliseconds.
void reportResults(StopWatch myClock, int items){
    auto endTime = std::chrono::system_clock::to_time_t(myClock.setStop());
    auto myDiff = myClock.getDiff(myClock.setStop());
    double time_in_seconds = myClock.seconds(myDiff);
    double time_in_milli = myClock.milliseconds(myDiff);
    std::cout << "Completed " << items << " items at: " << std::ctime(&endTime)
    << " in " << time_in_seconds << " seconds and " << time_in_milli
    << " milliseconds." <<std::endl;
}
//Start the clock, then run the sort algorithm
void testSortSpeed(StopWatch &myClock, std::vector<int> &holder){
    std::cout << "Sort\n";
    myClock.setStart();
    basicSort(holder);
}
//Start the clock, then run a search for a random number
void testSearchSpeed(StopWatch &myClock, std::vector<int> &holder, std::vector<int> &randNum){
    std::cout << "Search\n";
    myClock.setStart();
    sequentialSearch(holder, randNum);
}
//Start the clock, then run a binary search for a random number
void testBSearchSpeed(StopWatch &myClock, std::vector<int> &holder, std::vector<int> &randNum){
    std::cout << "Binary Search\n";
    myClock.setStart();
    binarySearch(holder, randNum);
}
//Start the clock, then reverse the order of the vector.
void testReverseSpeed(StopWatch &myClock, std::vector<int> &holder){
    std::cout << "Reverse\n";
    myClock.setStart();
    reverse(holder);
}

int main(int argc, const char * argv[]) {
    StopWatch myClock;
    //Create a vectoe to hold various ints representing number of items
    //to process
    std::vector<int> items{10, 100, 1000, 10000, 1000000, 10000000};
    //declare and define the PRNG
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,150);
    
    std::vector<int> holder;
    std::vector<int> randNum;
    //For each int in the items vector, fill the vector, then run each
    //algorithm test and report the amount of time each algorithm took to run.
    for(size_t i = 0; i < items.size(); i++){
        fillVector(gen, dis, items[i], holder, randNum);
        testSortSpeed(myClock, holder);
        reportResults(myClock, items[i]);
        testSearchSpeed(myClock, holder, randNum);
        reportResults(myClock, items[i]);
        testBSearchSpeed(myClock, holder, randNum);
        reportResults(myClock, items[i]);
        testReverseSpeed(myClock, holder);
        reportResults(myClock, items[i]);
    }

    return 0;
}
