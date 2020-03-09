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

class Explorer {
    int _lifeStat = 0;
    int _yourRoom = 0;
    int _arrows = 5;
    
public:
    Explorer();
    Explorer(int life);
    
    void setCurrentRoom(const Cave& cave);
    void setLifeStat(const int alive);
    void missed(const int usedArrow);
    
    int getExplorerLife() const;
    int getExplorerRoom() const;
    int getArrowNum() const;
};

#endif /* Explorer_hpp */
