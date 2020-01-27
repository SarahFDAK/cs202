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

bool sequentialSearch(std::vector<int> &holder, int randNum){
    return std::search(holder.begin(), holder.end(), [&](int n)
    {return n == randNum;}) != holder.end();
}

bool binarySearch(std::vector<int> &holder, int randNum){
    return std::binary_search(holder.begin(), holder.end(), [&](int n)
    {return n == randNum;});
}

void reverse(std::vector<int> &holder){
    std::reverse(holder.begin(), holder.end());
}
