//
//  SnowDump.hpp
//  Lab07
//
//  Created by Sarah Carter on 3/25/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef SnowDump_hpp
#define SnowDump_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class SnowDump {
public:
    SnowDump();
private:
    std::string cityName_{ "Fairbanks" };
    std::string stateName_{ "Alaska" };
    double snowFall_{ 8000.0 };
};

std::ostream& operator<<(std::ostream& os, const SnowDump& snowDump);

#endif /* SnowDump_hpp */
