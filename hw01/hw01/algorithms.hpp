//
//  algorithms.hpp
//  hw01
//
//  Created by Sarah Carter on 1/26/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef algorithms_hpp
#define algorithms_hpp

#include <stdio.h>
#include <algorithm>
#include <vector>
#include "StopWatch.hpp"

using std::vector;

void basicSort(vector<int> &holder);
bool sequentialSearch(vector<int> &holder, int randNum);
bool binarySearch(vector<int> &holder);
void rotate(vector<int> &holder);

#endif /* algorithms_hpp */
