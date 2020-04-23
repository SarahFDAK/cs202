//
//  Shaktoolik.cpp
//  IditarodChallenge6
//  Sarah Carter
//  CS202
//  Description: This program will provide in-progress files for the creation
//  of SVG files

#include <iostream>

#include "CityNode.hpp"
#include "SVGcode.hpp"

int main(int argc, const char * argv[]) {
        std::string args;
    CityList list;
    CityNode node;
    //End program if user did not input a file to read
    if(argc == 1){
        std::cout << "Please enter a file to open.\n";
        return 0;
    }
    args = argv[1];
    std::ifstream fin(args);
    //Read contents of file while checkFile tests are true
    while(list.checkFile(fin)){
        list.readFile(fin, node);
    }
//    int M;
    TSPSolver solveIt;
//    std::cout << "Enter the number of times you want to randomly solve for TSP: \n";
//    while(!(std::cin >> M)){
//        std::cout << "Please enter an integer: \n";
//        std::cin.ignore();
//    }
//    std::vector<int> random;
    std::vector<int> greedy;
//    std::vector<int> mine;
    
//    solveIt.SolveRandomly(list, 25, random);
    solveIt.SolveGreedy(list, greedy);
//    solveIt.SolveMyWay(list, mine);
    
    double xmin = 1e12;
    double xmax = 0.0;
    double ymin = 1e12;
    double ymax = 0.0;
    
    //Find min and max latitude and longitude in city list
    for(int i = 0; i < list.getCityVectorCount(); i++){
        double currY = list.getCityNode(i).getNodeLat();
        double currX = list.getCityNode(i).getNodeLong();
        xmin = std::min(xmin, currX);
        xmax = std::max(xmax, currX);
        ymin = std::min(ymin, currY);
        ymax = std::max(ymax, currY);
    }
    
    int imageWidth = 2500;
    int imageHeight = 2250;
    
//    std::cout << xmin << ", " << xmax << ", " << ymin << ", " << ymax << std::endl;
//    std::string Random = ChartPath(list, random, xmin, xmax, ymin, ymax);
//    std::string RandomSolve = buildSVG(Random, imageWidth, imageHeight);
    
    std::string Greedy = ChartPath(list, greedy, xmin, xmax, ymin, ymax);
    std::string GreedySolve = buildSVG(Greedy, imageWidth, imageHeight);
    
//    std::string MyWay = ChartPath(list, mine, xmin, xmax, ymin, ymax);
//    std::string MyWaySolve = buildSVG(MyWay, imageWidth, imageHeight);

//    CreateFile(RandomSolve, "Random");
    CreateFile(GreedySolve, "Greedy");
//    CreateFile(MyWaySolve, "Mine");
    return 0;
}

