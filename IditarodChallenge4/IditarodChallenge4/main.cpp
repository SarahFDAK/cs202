//
//  main.cpp
//  IditarodChallenge4
//  Sarah Carter
//  CS202
//  This program reads a tsp file of city nodes, then solves for the shortest
//  distance using randomly generated vectors, a greedy solve technique, and
//  the approach of all permutations of the list.
//

#include <iostream>

#include "CityNode.hpp"

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
    int M;
    TSPSolver solveIt;
    std::cout << "Enter the number of times you want to randomly solve for TSP: \n";
    while(!(std::cin >> M)){
        std::cout << "Please enter an integer: \n";
        std::cin.ignore();
    }
    solveIt.SolveRandomly(list, M);
    solveIt.SolveGreedy(list);
//    solveIt.SolveMyWay(list);
    return 0;
}
