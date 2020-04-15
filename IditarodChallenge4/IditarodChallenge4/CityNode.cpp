//
//  CityNode.cpp
//  IditarodChallenge3
//
//  Created by Sarah Carter on 4/9/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <cmath>
#include <random>
#include <algorithm>

#include "CityNode.hpp"

using std::mt19937;
using std::random_device;

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

//Check if the file can be opened
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

//Read file contents and populate vector of CityNodes
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

CityNode CityList::getCityNode(const int index){
    return cities_[index];
}

//Calculate distance between cities
double CityList::distance(int first, int second) const{
    //Return 0 of first and second city are the same
//    if(first == second){
//        std::cout << "Those are the same city.\n";
//        return 0.0;
//    }
    //Return 0 if one of the city numbers is beyond the list size
    if(first > cities_.size() || second > cities_.size()){
        std::cout << "This request is out of range.\n";
        return 0.0;
    }
    double firstX = cities_[first - 1].getNodeLat();
    double firstY = cities_[first - 1].getNodeLong();
    double secondX = cities_[second - 1].getNodeLat();
    double secondY = cities_[second - 1].getNodeLong();
    double dist = std::sqrt(pow((secondX - firstX),2.0) + pow((secondY - firstY),2)) ;
    //Return 0 if the distance between cities is greater than the circumference
    //of the Earth
//    if(dist > 24905){
//        std::cout << "At least one of your cities isn't on the earth.\n";
//        return 0.0;
//    }
    
    return dist;
}

int CityList::getCityVectorCount() const{
    return cities_.size();
}

CityList::~CityList(){};

CityPath::CityPath(){};

void CityPath::fillPath(const int city){
    path_.push_back(city);
}

void CityPath::emptyPath(){
    path_.clear();
}

int CityPath::getPathSize() const{
    return path_.size();
}

int CityPath::getPathEntry(const int entryNum){
    return path_[entryNum];
}

//Check if a city node number is already in the CityPath
bool CityPath::getPathDup(const int city) const{
    for(auto i = 0; i < path_.size(); i++){
        if(path_[i] == city)
            return false;
    }
    return true;
}

std::vector<int>& CityPath::getPathVector(){
    return path_;
}

CityPath::~CityPath(){};

TSPSolver::TSPSolver() {};

void TSPSolver::setBestList(const std::vector<int>& list){
    bestList_ = list;
}
void TSPSolver::setBestDist(const double dist){
    bestDist_ = dist;
}

double TSPSolver::getBestDist() const{
    return bestDist_;
}

void TSPSolver::showBestList() const{
    for(auto a: bestList_)
        std::cout << a << std::endl;
}

//Get a PRGN
int TSPSolver::getRandomInt(const int count) const{
    random_device rd;
    mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0,count);
    return dist(gen);
}

//Solve for distance in randomly generated lists
void TSPSolver::SolveRandomly(CityList& cList, const int M){
    int count = cList.getCityVectorCount();
    bestDist_ = 1e12;
    CityPath randomList;
    //Initialize the bestList member with the CityList nodeNums
    for(int i = 0; i < cList.getCityVectorCount(); i++){
        bestList_.push_back((cList.getCityNode(i)).getNodeNum());
    }
    double totalDist = 0;
    int loops = 0;
    
    //Loop for the number of times requested by the user
    while(loops < M){
        //Fill random path vector with randomly generated numbers
        do{
            int randNum = getRandomInt(count);
            //Check if generated number is already in the list
            if(randomList.getPathDup(randNum))
                randomList.fillPath(randNum);
            else
                continue;
        } while(randomList.getPathSize() < count);
        //Fill the end of the list with the first entry
        int a = randomList.getPathEntry(0);
        randomList.fillPath(a);
        //Calculate the total distance
        for(int i = 0; i < randomList.getPathSize()-1; i++){
            int first = randomList.getPathEntry(i);
            int second = randomList.getPathEntry(i + 1);
            double currDist = cList.distance(first, second);
            totalDist += currDist;
        }
        //If the total distance in the new vector is shorter than the previous
        //total, replace the bestList_ vector and the bestDist_ member
        if(bestDist_ > totalDist){
            for(int i = 0; i < randomList.getPathSize(); i++)
                bestList_[i] = randomList.getPathEntry(i);
            bestDist_ = totalDist;
        }
        loops++;
    }
    std::cout << "The best route found is a distance of " << bestDist_ <<
    " miles.\n";
}


void TSPSolver::SolveGreedy(CityList &cList){
    CityPath greedyList;
    int randNum =getRandomInt(cList.getCityVectorCount());
    //Start the list with a random selection
    greedyList.fillPath(randNum);
    int first;
    int second;
    int closestCity = 0;
    double totalDist = 0;
    
    //Run loop while greedyList is shorter than the CityList
    while(greedyList.getPathSize() < cList.getCityVectorCount()){
        double shortestDist = 1e12;
        int gL = greedyList.getPathSize() - 1;
        //Find the last city entered in the list and set it to the second city
        //for the distance function
        int lastCity = greedyList.getPathEntry(gL);
        second = lastCity;
        
        //Cycle through all cities in CityList to check distances from last city
        for(int i = 0; i < cList.getCityVectorCount(); i++){
            //Check if the current city is already in the list
            if(!greedyList.getPathDup(cList.getCityNode(i).getNodeNum()))
                continue;
            else{
                first = cList.getCityNode(i).getNodeNum();
                double currDist = cList.distance(first, second);
                //If the newest city is closer than the last shortest distance,
                //replace shortestDistance and closestCity variables
                if(shortestDist > currDist){
                    shortestDist = currDist;
                    closestCity = first;
                }
            }
        }
        //Add shortest distance to total distance
        totalDist += shortestDist;
        //Add the closest city to the list
        greedyList.fillPath(closestCity);
    }
    //Add first entry to the end of the list to create loop
    first = greedyList.getPathEntry(greedyList.getPathSize()-1);
    greedyList.fillPath(randNum);
    second = greedyList.getPathEntry(greedyList.getPathSize() - 1);
    //Calculate total distance of loop
    double lastDist = cList.distance(first, second);
    totalDist += lastDist;
    
    for(int i = 0; i < greedyList.getPathSize(); i++){
        std::cout << greedyList.getPathEntry(i) << std::endl;
    }
    std::cout << "The total distance covered is: " << totalDist <<
                " miles, starting at node " << greedyList.getPathEntry(0) << "\n";
}

void TSPSolver::SolveMyWay(CityList &cList){
    CityPath myPath;
    //Populate CityPath with CityList nodeNums
    for(int i = 0; i < cList.getCityVectorCount(); i++){
        myPath.fillPath(cList.getCityNode(i).getNodeNum());
    }
    //Add the first entry to the end of the list to complete the loop
    myPath.fillPath(cList.getCityNode(0).getNodeNum());
    double currDist = 0;
    double totalDist = 0;
    //Run the loop while there are more permutations of the list
    do{
        double shortestDist = 1e12;
        //Find the distance between each element
        for(int i = 0; i < myPath.getPathSize()-1; i++){
            int first = myPath.getPathEntry(i);
            int second = myPath.getPathEntry(i + 1);
            currDist = cList.distance(first, second);
            totalDist += currDist;
        }
        //Replace shortest distance if the new total distance is shorter
        if(shortestDist > totalDist){
            shortestDist = totalDist;
            //Replace bestList and bestDist members with the new list and the
            //shortest distance
            bestList_ = myPath.getPathVector();
            bestDist_ = shortestDist;
        }
    } while(std::next_permutation(myPath.getPathVector().begin(),           myPath.getPathVector().end()));
    
    std::cout << "The shortest available distance is " << bestDist_ << " using\n";
    showBestList();
}


TSPSolver::~TSPSolver(){};
