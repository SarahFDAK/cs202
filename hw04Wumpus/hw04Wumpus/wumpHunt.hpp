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
#include <map>
#include <vector>

//Cave map:
//Room  Neighbors
//A     B, E, F
//B     A, C, H
//C     B, D, J
//D     C, E, L
//E     A, D, N
//F     A, G, O
//G     F, H, P
//H     B, G, I
//I     H, J, Q
//J     C, I, K
//K     J, L, R
//L     D, K, M
//M     L, N, S
//N     E, M, O
//O     F, N, T
//P     G, Q, T
//Q     I, P, R
//R     K, Q, S
//S     M, R, T
//T     O, P, S

class Cave {
    //Cave's room number
    int _roomNum;
    //Neighboring rooms - dating myself by naming the neighbor after
    //Home Improvement. Perhaps the neighbor is a volleyball...
    char _wilson1;
    char _wilson2;
    char _wilson3;
    
public:
    Cave();
    Cave(int _roomNum);
    
    void setWilson1(const Cave& cave);
    void setWilson2(const Cave& cave);
    void setWilson3(const Cave& cave);
    
    int getRoom() const;
    char getWilson1() const;
    char getWilson2() const;
    char getWilson3() const;
};

std::vector<int> rooms { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' };


#endif /* wumpHunt_hpp */
