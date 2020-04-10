//
//  CityNode.cpp
//  IditarodChallenge3
//
//  Created by Sarah Carter on 4/9/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <sstream>
#include <fstream>
#include "CityNode.hpp"


CityNode::CityNode(){};

void CityNode::setCityNode(int num, double latitude, double longitude){
    nodeNum_ = num;
    nodeLat_ = latitude;
    nodeLong_ = longitude;
}

CityNode::~CityNode(){};

CityList::CityList(){};

void CityList::fillList(const CityNode& node){
    cities_.push_back(node);
}

void CityList::readFile(std::istream& in, CityNode& node){
    int num;
    double lat;
    double lng;
    in >> num >> lat >> lng;
    node.setCityNode(num, lat, lng);
}

CityList::~CityList(){};
