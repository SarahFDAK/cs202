//
//  Hazards.cpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 3/8/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "Hazards.hpp"

void Hazards::setBat1Room(const Cave& cave) {
    _bat1Room = cave.getRoom();
};
void Hazards::setBat2Room(const Cave& cave) {
    _bat2Room = cave.getRoom();
};
void Hazards::setPit1Room(const Cave& cave) {
    _pit1Room = cave.getRoom();
};
void Hazards::setPit2Room(const Cave& cave) {
    _pit2Room = cave.getRoom();
};

int Hazards::getBat1Room() const {
    return _bat1Room;
};
int Hazards::getBat2Room() const {
    return _bat2Room;
};
int Hazards::getPit1Room() const {
    return _pit1Room;
};
int Hazards::getPit2Room() const {
    return _pit2Room;
};
