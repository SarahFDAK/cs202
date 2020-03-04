//
//  SpeedCodeClasses.cpp
//  hw04-SpeedCode
//
//  Created by Sarah Carter on 3/3/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "SpeedCodeClasses.hpp"

void Streams::setStream(std::istream& input){
    input >> _userString;
}

std::ofstream Streams::Output(){
    std::ofstream fout("StreamsOutput.txt");
    fout << _userString;
    return fout;
}
