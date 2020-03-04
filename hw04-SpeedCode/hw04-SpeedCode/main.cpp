//
//  main.cpp
//  hw04-SpeedCode
//
//  Created by Sarah Carter on 3/3/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "SpeedCodeClasses.hpp"

int main(int argc, const char * argv[]) {
    Streams myStream;
    std::string myInput;
    std::getline(std::cin, myInput);
    std::istringstream iss(myInput);
    myStream.setStream(iss);
    myStream.Output();
    return 0;
}
