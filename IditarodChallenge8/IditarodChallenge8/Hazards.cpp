//
//  Hazards.cpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 3/8/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "Hazards.hpp"

Hazards::Hazards(){};
Hazards::Hazards(int type){
    _type = type;
};

void Hazards::setHazardRoom(const int room){
    _hazRoom = room;
}

int Hazards::getHazardRoom() const {
    return _hazRoom;
};
