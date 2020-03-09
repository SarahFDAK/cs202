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
#include <iostream>
#include <random>


class Cave {
    //Cave's room number
    int _roomNum;
    //Neighboring rooms - dating myself by naming the neighbor after
    //Home Improvement. Perhaps the neighbor is a volleyball...
    int _wilson1;
    int _wilson2;
    int _wilson3;
    
public:
    Cave();
    Cave(int _roomNum);
    
    void setWilson1(const int room);
    void setWilson2(const int room);
    void setWilson3(const int room);
    
    int getRoom() const;
    int getWilson1() const;
    int getWilson2() const;
    int getWilson3() const;
};

int randInt(int low, int high);

#endif /* wumpHunt_hpp */
