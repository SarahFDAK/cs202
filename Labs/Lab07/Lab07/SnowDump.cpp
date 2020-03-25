//
//  SnowDump.cpp
//  Lab07
//
//  Created by Sarah Carter on 3/25/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "SnowDump.hpp"


SnowDump::SnowDump(){};

void SnowDump::setCity(const std::string newCity){
    cityName_ = newCity;
}

void SnowDump::setState(const std::string newState){
    stateName_ = newState;
}
void SnowDump::setSnowFall(const double newDepth){
    snowFall_ = newDepth;
}

std::ostream& operator<<(std::ostream& os, const SnowDump& snowDump){
    return os;
}
