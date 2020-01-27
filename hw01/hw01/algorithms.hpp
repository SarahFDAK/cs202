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

using std::vector;

void basicSort(vector<int> &holder);
void sequentialSearch(vector<int> &holder, vector<int> &randNum);
void binarySearch(vector<int> &holder, vector<int> &randNum);
void reverse(vector<int> &holder);

#endif /* algorithms_hpp */
