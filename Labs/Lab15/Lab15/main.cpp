//
//  main.cpp
//  Lab15
//
//  Created by Sarah Carter on 4/23/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

//[x] Test STL algorithm from algorithm header
//[ ] Test STL algorithm from numeric header

void copyBackward() {
    std::vector<int> first { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> copy(first.size());
    std::copy_backward(first.begin(), first.end(), copy.end());
    for(auto& p: copy)
        std::cout << p << " ";
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    copyBackward();
    
    return 0;
}
