//
//  CityNode.hpp
//  IditarodChallenge3
//
//  Created by Sarah Carter on 4/9/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef CityNode_hpp
#define CityNode_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <istream>

class CityNode {
public:
    CityNode ();
    
    void setCityNode(int num, double latitude, double longitude);
    
    ~CityNode ();
private:
    int nodeNum_;
    double nodeLat_;
    double nodeLong_;
    double graphX_;
    double graphY_;
};

class CityList {
public:
    CityList();
    
    void fillList(const CityNode& node);
    
    void readFile(std::istream& in, CityNode& node);
    
    ~CityList();
private:
    std::vector<CityNode> cities_;
};

#endif /* CityNode_hpp */
