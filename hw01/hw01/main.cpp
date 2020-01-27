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
    auto s = std::chrono::system_clock::now();
    std::vector<int> holder;
    for(int i = 0; i < 500; i++){
        holder.push_back(i);
    }
    auto e = std::chrono::system_clock::now();
    std::chrono::duration<double> seconds = e - s;
    std::time_t ending = std::chrono::system_clock::to_time_t(e);
    std::cout << std::ctime(&ending) << " " << seconds.count() << std::endl;
    return 0;
}
