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
    
    void setWilson1(const Cave& cave);
    void setWilson2(const Cave& cave);
    void setWilson3(const Cave& cave);
    
    int getRoom() const;
    int getWilson1() const;
    int getWilson2() const;
    int getWilson3() const;
};


#endif /* wumpHunt_hpp */
