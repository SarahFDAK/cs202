//
//  main.cpp
//  hw04-SpeedCode
//
//  Created by Sarah Carter on 3/3/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "SpeedCodeClasses.hpp"

int main(int argc, const char * argv[]) {
    Streams myStream;
    std::string myInput;
    std::getline(std::cin, myInput);
    std::istringstream iss(myInput);
    myStream.setStream(iss);
    myStream.Output();
    
    Containers myContainer;
    int myEntryNum = 0;
    std::cout << "How many entries do you want to make?\n";
    std::cin >> myEntryNum;
    while(!std::cin){
        std::cout << "Please enter an integer: \n";
        std::cin.ignore();
    }
    myContainer.setEntries(myEntryNum);
    std::cin.ignore();
    for(int i = 0; i < myEntryNum; i++){
        std::cout << "Word entry " << i << ": ";
        std::getline(std::cin, myInput);
        myContainer.addWords(i, myInput);
    }
    myContainer.printWords();
    return 0;
}
