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
    CityPath greedy;
//    std::vector<int> mine;
    
//    solveIt.SolveRandomly(list, 25, random);
    solveIt.SolveGreedy(list, greedy);
//    solveIt.SolveMyWay(list, mine);
    
//    double xmin = list.getMinLong();
//    double xmax = list.getMaxLong();
//    double ymin = list.getMinLat();
//    double ymax = list.getMaxLat();
//
//
//    int imageWidth = 2500;
//    int imageHeight = 2250;
    //Create extra CityPath to hold path data
    CityPath greedyTemp;
    
    inProgress(list, greedy, greedyTemp);
    
//    std::cout << xmin << ", " << xmax << ", " << ymin << ", " << ymax << std::endl;
//    std::string Random = ChartPath(list, random, xmin, xmax, ymin, ymax);
//    std::string RandomSolve = buildSVG(Random, imageWidth, imageHeight);
    
//    std::string Greedy = ChartPath(list, greedy, xmin, xmax, ymin, ymax);
//    std::string GreedySolve = buildSVG(Greedy, imageWidth, imageHeight);
//    CreateFile(GreedySolve, "Greedy");

//    std::string MyWay = ChartPath(list, mine, xmin, xmax, ymin, ymax);
//    std::string MyWaySolve = buildSVG(MyWay, imageWidth, imageHeight);

//    CreateFile(RandomSolve, "Random");
//    CreateFile(MyWaySolve, "Mine");
    return 0;
}

