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
#include <fstream>
#include <sstream>


class CityNode {
public:
    CityNode ();
    
    void setCityNode(int num, double latitude, double longitude);
    
    int getNodeNum() const;
    
    double getNodeLat() const;
    
    double getNodeLong() const;
    
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
    
    void fillList(CityNode& node);
    
    bool checkFile(std::istream& fin);
    
    void readFile(std::istream& fin, CityNode& node);
    
    double distance(int first, int second) const;
    
    CityNode getCityInfo(int index) const;
    
    ~CityList();
private:
    std::vector<CityNode> cities_;
};

#endif /* CityNode_hpp */
