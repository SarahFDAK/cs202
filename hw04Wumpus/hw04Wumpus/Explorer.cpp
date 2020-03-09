//
//  Explorer.cpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 3/8/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//


#include "Explorer.hpp"

Explorer::Explorer(){};

Explorer::Explorer(int life){
    _lifeStat = life;
}

void Explorer::setCurrentRoom(const Cave& cave) {
    _yourRoom = cave.getRoom();
};
void Explorer::setLifeStat(const int alive){
    _lifeStat = alive;
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
