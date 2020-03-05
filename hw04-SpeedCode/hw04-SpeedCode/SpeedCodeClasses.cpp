//
//  SpeedCodeClasses.cpp
//  hw04-SpeedCode
//
//  Created by Sarah Carter on 3/3/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "SpeedCodeClasses.hpp"

void Streams::setStream(std::istream& input){
    std::string holder;
    while(input >> holder)
        _userString+=(holder + " ");
}

std::ofstream Streams::Output(){
    std::ofstream fout("StreamsOutput.txt");
    if(!fout)
        std::cout << "Error opening file\n";
    fout << _userString;
    return fout;
}

void Containers::setEntries(int& userNum){
    _entries = userNum;
}

void Containers::addWords(int& entryNum, std::string& mapEntry){
    _myMap[entryNum] = mapEntry;
}

int Containers::getEntries() const{
    return _entries;
}
