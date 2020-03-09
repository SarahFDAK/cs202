//
//  Explorer.hpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 3/8/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef Explorer_hpp
#define Explorer_hpp

#include <stdio.h>
#include "Cave.hpp"
#include "Hazards.hpp"
#include "Wumpus.hpp"

class Explorer {
    int _lifeStat = 0;
    int _yourRoom = 0;
    int _arrows = 5;
    
public:
    Explorer();
    Explorer(const int room);
    
    void setCurrentRoom(const int room);
    void move(const Cave& cave);
    void setLifeStat(const int alive);
    void missed(const int usedArrow);
    void shoot(Cave& cave, Wumpus& wompa);
    int event(const Cave& cave, const Hazards& bat1, const Hazards& bat2,
               const Hazards& pit1, const Hazards& pit2, const Wumpus& wompa);
    
    int getExplorerLife() const;
    int getExplorerRoom() const;
    int getArrowNum() const;
};

#endif /* Explorer_hpp */
