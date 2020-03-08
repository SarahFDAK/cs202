//
//  wumpHunt.cpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 2/24/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "Cave.hpp"

Cave::Cave(){};

Cave::Cave(int room){
    _roomNum = room;
}

int Cave::getRoom() const {
    return _roomNum;
}

int Cave::getWilson1() const {
    return _wilson1;
}

int Cave::getWilson2() const {
    return _wilson2;
}

int Cave::getWilson3() const {
    return _wilson3;
}

void Cave::setWilson1(const Cave &room){
    _wilson1 = room.getRoom();
}

void Cave::setWilson2(const Cave &room){
    _wilson2 = room.getRoom();
}

void Cave::setWilson3(const Cave &room){
    _wilson3 = room.getRoom();
}
