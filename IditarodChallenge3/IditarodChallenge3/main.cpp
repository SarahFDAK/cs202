//
//  IditarodChallenge3
//  Author: Sarah Carter
//  CS202
//  This program will read in a tsp file containing latitudes and longitudes of cities,
//  then return the distance between two cities.
//

#include <iostream>

#include "CityNode.hpp"

int main(int argc, const char * argv[]) {
    //Create a string to hold user input in command prompt
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
    int first;
    int second;
    std::string input;
    
    //Get user input for city distance
    std::cout << "Enter city numbers between 1 and " << list.getCityVectorCount() << "\n";
    
    std::getline(std::cin, input);
    std::istringstream in(input);
    //If user did not input integers, end program
    if(!(in >> first >> second)){
        std::cout << "Please enter integers only.\n";
        return 0;
    }
    //Report the distance between the requested cities.
    in >> first >> second;
    std::cout << "The distance between the city at node number " << first << " and node number " << second << " is " << list.distance(first, second) << "\n";
    
    return 0;
}
