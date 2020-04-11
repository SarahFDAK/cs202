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

bool checkFile(const std::string& file){
    std::ifstream fin(file);
    if(!fin){
        if(fin.eof()){
            std::cout << "Reached end of file.\n";
            return true;
        }
        std::cout << "Error opening file.\n";
        return false;
    }
    return true;
}

CityNode readFile(std::string& file){
    CityNode node;
    int num;
    double lat;
    double lng;
    std::ifstream fin(file);
    fin >> num >> lat >> lng;
    node.setCityNode(num, lat, lng);
    return node;
}

CityList::~CityList(){};
