//
//  algorithms.cpp
//  hw01
//
//  Created by Sarah Carter on 1/26/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "algorithms.hpp"

void basicSort(std::vector<int> &holder){
    std::sort(holder.begin(), holder.end());
}

void sequentialSearch(std::vector<int> &holder, std::vector<int> &randNum){
    std::search(holder.begin(), holder.end(), randNum.begin(), randNum.end());
}

void binarySearch(std::vector<int> &holder, std::vector<int> &randNum){
    std::binary_search(holder.begin(), holder.end(), randNum[0]);
}

void reverse(std::vector<int> &holder){
    std::reverse(holder.begin(), holder.end());
}
