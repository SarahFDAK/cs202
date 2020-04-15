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
    
    int getCityVectorCount() const;
    
    
    ~CityList();
private:
    std::vector<CityNode> cities_;
};

class CityPath{
public:
    CityPath();
    
    void fillPath(const int list);
    
    int getPathSize() const;
    
    int getPathEntry(const int entryNum);
    
    bool getPathDup(const int city) const;
    
    ~CityPath();
private:
    std::vector<int> path_;
};

class TSPSolver {
public:
    TSPSolver();
    
    void setBestList(const std::vector<int>& list);
    void setBestDist(const double dist);
    
    double getBestDist() const;
    void showBestList() const;
    
    int getRandomInt(const int count) const;
    
    void SolveRandomly(const CityList& cList);
    
    ~TSPSolver();
private:
    std::vector<int> bestList_;
    double bestDist_;
};

#endif /* CityNode_hpp */
