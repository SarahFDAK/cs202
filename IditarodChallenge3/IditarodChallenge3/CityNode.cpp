//
//  CityNode.cpp
//  IditarodChallenge3
//
//  Created by Sarah Carter on 4/9/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "CityNode.hpp"


CityNode::CityNode(){};

void CityNode::setCityNode(int num, double latitude, double longitude){
    nodeNum_ = num;
    nodeLat_ = latitude;
    nodeLong_ = longitude;
}

void CityNode::getCityNode() const {
    std::cout << "Node: " << nodeNum_;
    std::cout << "  Lat: " << nodeLat_;
    std::cout << "  Long: " << nodeLong_ << "\n";
}

CityNode::~CityNode(){};

CityList::CityList(){};

void CityList::fillList(CityNode& node){
    cities_.push_back(node);
}

bool CityList::checkFile(std::istream& fin){
    if(!fin){
        if(fin.eof()){
            std::cout << "Reached end of file.\n";
            exit(0);
        }
        std::cout << "Error opening file.\n";
        return false;
    }
    return true;
}

void CityList::readFile(std::istream& fin, CityNode& node){
    std::string read;
    int num;
    double lat;
    double lng;
    while(std::getline(fin, read)){
        if(read[0] > 48 || read[0] < 57){
            std::istringstream is(read);
            is >> num >> lat >> lng;
            node.setCityNode(num, lat, lng);
            fillList(node);
        }
        continue;
    }
    for(auto a:cities_)
        a.getCityNode();
}

CityList::~CityList(){};
