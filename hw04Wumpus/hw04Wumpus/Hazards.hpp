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
    int _bat1Room = 0;
    int _bat2Room = 0;
    int _pit1Room = 0;
    int _pit2Room = 0;
  
public:
    Hazards();
    Hazards(int bat1, int bat2, int pit1, int pit2);
    
    void setBat1Room(const Cave& cave);
    void setBat2Room(const Cave& cave);
    void setPit1Room(const Cave& cave);
    void setPit2Room(const Cave& cave);
    
    int getBat1Room() const;
    int getBat2Room() const;
    int getPit1Room() const;
    int getPit2Room() const;
};

#endif /* Hazards_hpp */
