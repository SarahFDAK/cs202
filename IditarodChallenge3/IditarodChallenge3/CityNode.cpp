//
//  CityNode.cpp
//  IditarodChallenge3
//
//  Created by Sarah Carter on 4/9/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <cmath>

#include "CityNode.hpp"


CityNode::CityNode(){};

void CityNode::setCityNode(int num, double latitude, double longitude){
    nodeNum_ = num;
    nodeLat_ = latitude;
    nodeLong_ = longitude;
}

int CityNode::getNodeNum() const{
    return nodeNum_;
}

double CityNode::getNodeLat() const{
    return nodeLat_;
}

double CityNode::getNodeLong() const{
    return nodeLong_;
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
            return false;
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
        if(isdigit(read[0])){
            std::istringstream is(read);
            is >> num >> lat >> lng;
            node.setCityNode(num, lat, lng);
            fillList(node);
        }
        continue;
    }
}

double CityList::distance(int first, int second) const{
    if(first == second){
        std::cout << "Those are the same city.\n";
        return 0.0;
    }
    if(first > cities_.size() || second > cities_.size()){
        std::cout << "This request is out of range.\n";
        return 0.0;
    }
    double firstX = cities_[first - 1].getNodeLat();
    double firstY = cities_[first - 1].getNodeLong();
    double secondX = cities_[second - 1].getNodeLat();
    double secondY = cities_[second - 1].getNodeLong();
    double dist = std::sqrt(pow((secondX - firstX),2.0) + pow((secondY - firstY),2)) ;

    if(dist > 24905){
        std::cout << "At least one of your cities isn't on the earth.\n";
        return 0.0;
    }
    
    return dist;
}

int CityList::getCityVectorCount() const{
    return cities_.size();
}


CityList::~CityList(){};
