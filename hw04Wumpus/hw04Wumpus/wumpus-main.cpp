//
//  main.cpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 2/24/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <tuple>

#include "Hazards.hpp"
#include "Wumpus.hpp"
#include "Explorer.hpp"

using std::cout;
using std::endl;

//Create random number generator
std::mt19937 PRNG(){
    std::random_device rd1;
    std::mt19937 gen1(rd1());
    return gen1;
}

//Initialize roomNums map to fill with randomized numbers between 1 and 20
std::map<int, int> roomNums;

//Create cave map associating each room number with its 3 neighbors
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
    else return std::make_tuple(roomNums[15], roomNums[16], roomNums[19]);
    
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
    //Create vector to hold numbers 1 through 20 to shuffle randomly for distribution
    //later; create vector to hold cave room numbers
    std::vector<int> rooms;
    std::vector<Cave> caves;
    
    //Populate room numbers vector and Caves vector
    for(int i = 0; i < 20; i++){
        rooms.push_back(i+1);
        Cave room(i+1);
        caves.push_back(room);
    }

    //Randomly shuffle rooms 1-20, then push them to the room numbers map
    std::shuffle(rooms.begin(), rooms.end(), PRNG());
    for(int j = 0; j < 20; j++){
        roomNums[j+1] = rooms[j];
    }
    
    //Create neighbor rooms for each cave using the roomNums map and the roomNeighbors
    //tuple.
    for(int k = 0; k < 20; k++){
        int room1, room2, room3;
        std::tie(room1, room2, room3) = roomNeighbors(k+1);
        caves[k].setWilson1(room1);
        caves[k].setWilson2(room2);
        caves[k].setWilson3(room3);
    }
    
    //Declare and initialize player, wumpus, and hazards
    Explorer player(randInt(1,20));
    Wumpus wompa(0);
    Hazards bat1(1);
    Hazards bat2(1);
    Hazards pit1(2);
    Hazards pit2(2);
    
    //Set starting room for Wumpus and hazards
    while(wompa.getWumpRoom()==0 ||
          wompa.getWumpRoom() == player.getExplorerRoom())
        wompa.setWumpRoom(randInt(1,20));
    while(bat1.getHazardRoom() == 0 ||
          bat1.getHazardRoom() == wompa.getWumpRoom() ||
          bat1.getHazardRoom() == player.getExplorerRoom())
        bat1.setHazardRoom(randInt(1, 20));
    while(bat2.getHazardRoom() == 0 ||
          bat2.getHazardRoom() == player.getExplorerRoom() ||
          bat2.getHazardRoom() == wompa.getWumpRoom() ||
          bat2.getHazardRoom() == bat1.getHazardRoom())
        bat2.setHazardRoom(randInt(1, 20));
    while(pit1.getHazardRoom() == 0 ||
          pit1.getHazardRoom() == player.getExplorerRoom() ||
          pit1.getHazardRoom() == wompa.getWumpRoom() ||
          pit1.getHazardRoom() == bat1.getHazardRoom() ||
          pit1.getHazardRoom() == bat2.getHazardRoom())
        pit1.setHazardRoom(randInt(1, 20));
    while(pit2.getHazardRoom() == 0 ||
          pit2.getHazardRoom() == player.getExplorerRoom() ||
          pit2.getHazardRoom() == wompa.getWumpRoom() ||
          pit2.getHazardRoom() == bat1.getHazardRoom() ||
          pit2.getHazardRoom() == bat2.getHazardRoom() ||
          pit2.getHazardRoom() == pit1.getHazardRoom())
        pit2.setHazardRoom(randInt(1, 20));
    
    //Start game loop
    while(player.getExplorerLife() == 0 && player.getArrowNum() > 0){
        std::cout << "Your room: " << player.getExplorerRoom()<< " Wumpus " << wompa.getWumpRoom() << " bat " << bat1.getHazardRoom() << " bat " << bat2.getHazardRoom() << " pit " << pit1.getHazardRoom() << " pit " << pit2.getHazardRoom() << std::endl;
        
        //Set Cave object to allow for shorter member function calls
        Cave nextDoor = caves[player.getExplorerRoom()-1];
        //Report player location, number of arrows, and neighboring rooms
        std::cout << "You are in room " << player.getExplorerRoom() << ". You have " <<
        player.getArrowNum() << " arrows left. The adjoining rooms are " <<
        nextDoor.getWilson1() << ", " <<
        nextDoor.getWilson2() << ", and " <<
        nextDoor.getWilson3() << ".\n";
        //Report to player if Wumpus, bats, or pits are nearby
        if(wompa.getWumpRoom() == nextDoor.getWilson1() ||
           wompa.getWumpRoom() == nextDoor.getWilson2() ||
           wompa.getWumpRoom() == nextDoor.getWilson3())
            std::cout << "This room smells AWFUL!!\n";
        if((bat1.getHazardRoom() == nextDoor.getWilson1() ||
                bat1.getHazardRoom() == nextDoor.getWilson2() ||
                bat1.getHazardRoom() == nextDoor.getWilson3()) ||
                (bat2.getHazardRoom() == nextDoor.getWilson1() ||
                 bat2.getHazardRoom() == nextDoor.getWilson2() ||
                 bat2.getHazardRoom() == nextDoor.getWilson3()))
            std:cout << "I hear a bat...\n";
        if(pit1.getHazardRoom() == nextDoor.getWilson3() ||
           pit1.getHazardRoom() == nextDoor.getWilson2() ||
           pit1.getHazardRoom() == nextDoor.getWilson1() ||
           pit2.getHazardRoom() == nextDoor.getWilson3() ||
           pit2.getHazardRoom() == nextDoor.getWilson2() ||
           pit2.getHazardRoom() == nextDoor.getWilson1())
            std::cout << "I feel a cold breeze...\n";
        
        //As for player to choose action
        std::cout << "Do you want to move (m) or shoot (s) an arrow?\n";
        std::string choice;
        std::cin >> choice;
        //Move the player - end the game if they die
        if(choice == "m" || choice == "M"){
            player.move(nextDoor);
            int event = player.event(player.getExplorerRoom(), bat1, bat2, pit1, pit2, wompa);
            if(event == 1)
                continue;
            else if(event == 2)
                break;
            else if(event == 3)
                break;
            else
                continue;
            }
        //Try to let the palyer shoot - this isn't working for some reason
        if(choice == "s" || choice == "S"){
            player.shoot(caves[player.getExplorerRoom()-1], wompa);
            if(wompa.getWumpStat() == false)
                return 0;
        }
    }
    std::cout << "Better luck next time...\n";
    return 0;
}
