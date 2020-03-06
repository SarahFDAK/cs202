//
//  SpeedCodeClasses.hpp
//  hw04-SpeedCode
//
//  Created by Sarah Carter on 3/3/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef SpeedCodeClasses_hpp
#define SpeedCodeClasses_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

class Streams {
public:
    void setStream(const std::istream& input);
    std::ofstream Output();
private:
    std::string _userString;
};

class Containers {
public:
    void setEntries(const int& userNum);
    void addWords(const int& entryNum, const std::string& mapEntry);
    int getEntries() const;
    void printWords() const;
private:
    std::map<int, std::string> _myMap;
    int _entries;
};

class Memory {
    
};
#endif /* SpeedCodeClasses_hpp */
