//
//  main.cpp
//  IditarodChallenge3
//
//  Created by Sarah Carter on 4/9/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>

#include "CityNode.hpp"

int main(int argc, const char * argv[]) {
    std::string args;
    CityList list;
    CityNode node;
    if(argc == 1){
        std::cout << "Please enter a file to open.\n";
        return 0;
    }
    args = argv[1];
    std::ifstream fin(args);

    while(list.checkFile(fin)){
        list.readFile(fin, node);
    }
    
    std::cout << list.getCityInfo(20).getNodeNum() << "\n";
    
    std::cout << list.distance(20, 15) << "\n";
    
    return 0;
}
