//
//  main.cpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 2/24/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <random>
#include <map>
#include <tuple>

#include "Hazards.hpp"
#include "Wumpus.hpp"
#include "Explorer.hpp"

using std::cout;
using std::endl;

int randNum(int a, int b){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

std::map<int, int> roomNums {
    {1, 0},
    {2, 0},
    {3, 0},
    {4, 0},
    {5, 0},
    {6, 0},
    {7, 0},
    {8, 0},
    {9, 0},
    {10, 0},
    {11, 0},
    {12, 0},
    {13, 0},
    {14, 0},
    {15, 0},
    {16, 0},
    {17, 0},
    {18, 0},
    {19, 0},
    {20, 0}
};

std::tuple<int, int, int> roomNeighbors(int roomNum){
    if(roomNum == 1) return std::make_tuple(roomNums[2], roomNums[5], roomNums[6]);
    if(roomNum == 2) return std::make_tuple(roomNums[1], roomNums[3], roomNums[8]);
    if(roomNum == 3) return std::make_tuple(roomNums[2], roomNums[4], roomNums[10]);
    if(roomNum == 4) return std::make_tuple(roomNums[3], roomNums[5], roomNums[12]);
    if(roomNum == 5) return std::make_tuple(roomNums[1], roomNums[4], roomNums[14]);
    if(roomNum == 6) return std::make_tuple(roomNums[1], roomNums[7], roomNums[15]);
    if(roomNum == 7) return std::make_tuple(roomNums[6], roomNums[8], roomNums[16]);
    if(roomNum == 8) return std::make_tuple(roomNums[2], roomNums[7], roomNums[9]);
    if(roomNum == 9) return std::make_tuple(roomNums[8], roomNums[10], roomNums[17]);
    if(roomNum == 10) return std::make_tuple(roomNums[3], roomNums[9], roomNums[11]);
    if(roomNum == 11) return std::make_tuple(roomNums[10], roomNums[12], roomNums[18]);
    if(roomNum == 12) return std::make_tuple(roomNums[4], roomNums[11], roomNums[13]);
    if(roomNum == 13) return std::make_tuple(roomNums[12], roomNums[14], roomNums[19]);
    if(roomNum == 14) return std::make_tuple(roomNums[5], roomNums[13], roomNums[15]);
    if(roomNum == 15) return std::make_tuple(roomNums[6], roomNums[14], roomNums[20]);
    if(roomNum == 16) return std::make_tuple(roomNums[7], roomNums[17], roomNums[20]);
    if(roomNum == 17) return std::make_tuple(roomNums[9], roomNums[16], roomNums[18]);
    if(roomNum == 18) return std::make_tuple(roomNums[11], roomNums[17], roomNums[19]);
    if(roomNum == 19) return std::make_tuple(roomNums[13], roomNums[18], roomNums[20]);
    else return std::make_tuple(roomNums[15], roomNums[15], roomNums[19]);
    
};
//Cave map:
//Room  Neighbors
//1 A    B, E, F
//2 B    A, C, H
//3 C    B, D, J
//4 D    C, E, L
//5 E    A, D, N
//6 F    A, G, O
//7 G    F, H, P
//8 H    B, G, I
//9 I    H, J, Q
//10J    C, I, K
//11K    J, L, R
//12L    D, K, M
//13M    L, N, S
//14N    E, M, O
//15O    F, N, T
//16P    G, Q, T
//17Q    I, P, R
//18R    K, Q, S
//19S    M, R, T
//20T    O, P, S

int main(int argc, const char * argv[]) {
    std::vector<Cave> rooms;
    for(int i = 0; i < 20; i++){
        Cave room(i+1);
//        rooms.push_back(room);
        roomNums[i+1] = randNum(1, 20);
        
        rooms[i+1].setWilson1(std::get<0>(roomNums[roomNeighbors(i+1)));
        rooms[i+1].setWilson2(std::get<1>(roomNeighbors(i+1)));
        rooms[i+1].setWilson3(std::get<2>(roomNeighbors(i+1)));
        std::cout << room.getRoom() << ", " << room.getWilson1() << ", " <<
        room.getWilson2() << ", " << room.getWilson3() << std::endl;
    }
    
    return 0;
}
