//
//  Wumpus.cpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 3/8/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "Wumpus.hpp"

void Wumpus::setWumpRoom(const Cave& cave) {
    _wumpRoom = cave.getRoom();
};
void Wumpus::setWumpLife(const bool& wumpStat) {
    _itsAlive = wumpStat;
};

int Wumpus::getWumpRoom() const {
    return _wumpRoom;
};
bool Wumpus::getWumpStat() const {
    return _itsAlive;
};
