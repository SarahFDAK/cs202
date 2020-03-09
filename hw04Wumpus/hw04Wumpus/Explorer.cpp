//
//  Explorer.cpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 3/8/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <sstream>

#include "Explorer.hpp"

Explorer::Explorer(){};

Explorer::Explorer(const Cave& cave){
    _yourRoom = cave.getRoom();
}

void Explorer::setCurrentRoom(const Cave& cave) {
    _yourRoom = cave.getRoom();
};

void Explorer::setLifeStat(const int alive){
    _lifeStat = alive;
};

void Explorer::move(const Cave& cave){
    std::cout << "Which room?\n" << cave.getWilson1() << ", " <<
                cave.getWilson2() << ", or " << cave.getWilson3() << " ?\n";
    std::string newRoom;
    int choice;
    while(std::getline(std::cin, newRoom)){
        std::istringstream iss(newRoom);
        if(iss >> choice){
            if(choice == cave.getWilson1()){
                _yourRoom = cave.getWilson1();
                break;
            }
            else if(choice == cave.getWilson2()){
                _yourRoom = cave.getWilson2();
                break;
            }
            else if(choice == cave.getWilson3()){
                _yourRoom = cave.getWilson3();
                break;
            }
        }
        std::cout << "That wasn't an option! Please try again: \n";
    }
};
    
void Explorer::missed(const int usedArrow) {
    if(_arrows > 1)
        _arrows -= 1;
    else
        std::cout << "You are out of arrows. Better run away!\n";
};

int Explorer::getExplorerLife() const {
    return _lifeStat;
};
int Explorer::getExplorerRoom() const {
    return _yourRoom;
};
int Explorer::getArrowNum() const {
    return _arrows;
};

