//
//  Hazards.hpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 3/8/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef Hazards_hpp
#define Hazards_hpp

#include <stdio.h>
#include "Cave.hpp"

class Hazards {
    int _hazRoom = 0;
    
    //bats are type 1, pits are type 2
    int _type;
  
public:
    Hazards();
    Hazards(int type);
    
    void setHazardRoom(const int room);
    
    int getHazardRoom() const;
};

#endif /* Hazards_hpp */
