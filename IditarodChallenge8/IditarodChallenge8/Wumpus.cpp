//
//  Wumpus.cpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 3/8/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "Wumpus.hpp"

Wumpus::Wumpus(){};

Wumpus::Wumpus(int room){
    _wumpRoom = room;
}

void Wumpus::setWumpRoom(const int room) {
    _wumpRoom = room;
};
void Wumpus::setWumpLife(const bool& wumpStat) {
    _itsAlive = wumpStat;
};

void Wumpus::moveWumpus(int low, int high){
    _wumpRoom = randInt(low, high);
}

int Wumpus::getWumpRoom() const {
    return _wumpRoom;
};
bool Wumpus::getWumpStat() const {
    return _itsAlive;
};
