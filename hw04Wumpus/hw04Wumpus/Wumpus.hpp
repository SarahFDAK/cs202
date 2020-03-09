//
//  Wumpus.hpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 3/8/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef Wumpus_hpp
#define Wumpus_hpp

#include <stdio.h>
#include "Cave.hpp"

class Wumpus {
    bool _itsAlive = true;
    int _wumpRoom = 0;
    
public:
    Wumpus();
    Wumpus(bool life);
    
    void setWumpRoom(const Cave& cave);
    void setWumpLife(const bool& wumpStat);
    
    int getWumpRoom() const;
    bool getWumpStat() const;
};

#endif /* Wumpus_hpp */
