//
//  main.cpp
//  IditarodChallenge4
//
//  Created by Sarah Carter on 4/14/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>

#include "CityNode.hpp"

int main(int argc, const char * argv[]) {
        std::string args;
    CityList list;
    CityNode node;
    //End program if user did not input a file to read
//    if(argc == 1){
//        std::cout << "Please enter a file to open.\n";
//        return 0;
//    }
//    args = argv[1];
    std::ifstream fin("rl1323.tsp");
    //Read contents of file while checkFile tests are true
    while(list.checkFile(fin)){
        list.readFile(fin, node);
    }
    TSPSolver solveIt;
    solveIt.SolveRandomly(list);
    return 0;
}
