//
//  wumpHunt.hpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 2/24/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef wumpHunt_hpp
#define wumpHunt_hpp

#include <stdio.h>
#include <tuple>

class Rooms{
public:
    void setNeighborRooms(const int& n1, const int& n2, const int& n3);
private:
    int _roomNum;
    std::tuple<char, char, char> _neighbors;
};

#endif /* wumpHunt_hpp */
