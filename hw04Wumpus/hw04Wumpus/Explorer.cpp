//
//  Explorer.cpp
//  hw04Wumpus
//
//  Created by Sarah Carter on 3/8/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <sstream>

#include "Explorer.hpp"

Explorer::Explorer(){};

Explorer::Explorer(const int room){
    _yourRoom = room;
}

void Explorer::setCurrentRoom(const int room) {
    _yourRoom = room;
};

void Explorer::setLifeStat(const int alive){
    _lifeStat = alive;
};

void Explorer::move(const Cave& cave){
    std::cout << "Which room?\n" << cave.getWilson1() << ", " <<
                cave.getWilson2() << ", or " << cave.getWilson3() << " ?\n";
    std::string newRoom;
    int choice;
    while(true){
        std::getline(std::cin, newRoom);
        std::istringstream iss(newRoom);
        if(iss >> choice){
            if(choice == cave.getWilson1()){
                _yourRoom = cave.getWilson1();
               break;
            }
            else if(choice == cave.getWilson2()){
                _yourRoom = cave.getWilson2();
                break;
            }
            else if(choice == cave.getWilson3()){
                _yourRoom = cave.getWilson3();
                break;
            }
            else
                std::cout << "That wasn't an option! Please try again: \n";
        }
    }
};

int Explorer::event(const Cave& cave, const Hazards& bat1, const Hazards& bat2,
                     const Hazards& pit1, const Hazards &pit2, Wumpus &wompa){
    if(cave.getRoom() == bat1.getHazardRoom() ||
       cave.getRoom() == bat2.getHazardRoom()){
        std::cout << "A giant bat grabbed you and carried you off!\n";
        while(_yourRoom == cave.getRoom())
            _yourRoom = randInt(1, 20);
        return 1;
    }
    else if(cave.getRoom() == pit1.getHazardRoom() ||
            cave.getRoom() == pit2.getHazardRoom()){
        std::cout << "Oh no, you fell in a pit!\n";
        return 2;
    }
    else if(cave.getRoom() == wompa.getWumpRoom()){
        std::cout << "GLOMP! The Wumpus just had you for snacks!\n";
        return 3;
    }
    return 1;
}

//Shoot function 
void Explorer::shoot(Cave& cave, Wumpus &wompa){
    std::cout << "Which room do you want to shoot into?\n" << cave.getWilson1() <<
                ", " << cave.getWilson2() << ", " << cave.getWilson3() << std::endl;
    std::string input;
    int choice;
//    int count = 0;
    std::cin.ignore();
    std::getline(std::cin, input);
    std::istringstream iss(input);
//    while(count < 3){
        if(iss >> choice){
            if(choice == cave.getWilson1()){
                if(wompa.getWumpRoom() == cave.getWilson1()){
                    wompa.setWumpLife(false);
                    std::cout << "You got the Wumpus! Congrats!\n";
                }
                else if(wompa.getWumpRoom() == cave.getWilson2() ||
                        wompa.getWumpRoom() == cave.getWilson3()){
                    std::cout << "You woke up the Wumpus...\n";
                    wompa.moveWumpus(1, 20);
                    _arrows--;
                    //count ++;
                }
                else{
                    std::cout << "You didn't hit anything...\n";
                    _arrows--;
                }
            }
            else if(choice == cave.getWilson2()){
                if(wompa.getWumpRoom() == cave.getWilson2()){
                    wompa.setWumpLife(false);
                    std::cout << "You got the Wumpus! Congrats!\n";
                }
                else if(wompa.getWumpRoom() == cave.getWilson1() ||
                        wompa.getWumpRoom() == cave.getWilson3()){
                    std::cout << "You woke up the Wumpus...\n";
                    wompa.moveWumpus(1, 20);
                    _arrows--;
                    //count ++;
                }
                else{
                    std::cout << "You didn't hit anything...\n";
                    _arrows--;
                }
            }
            else if(choice == cave.getWilson3()){
                if(wompa.getWumpRoom() == cave.getWilson3()){
                    wompa.setWumpLife(false);
                    std::cout << "You got the Wumpus! Congrats!\n";
                }
                else if(wompa.getWumpRoom() == cave.getWilson1() ||
                        wompa.getWumpRoom() == cave.getWilson2()){
                    std::cout << "You woke up the Wumpus...\n";
                    wompa.moveWumpus(1, 20);
                    _arrows--;
                    //count ++;
                }
                else{
                    std::cout << "You didn't hit anything...\n";
                    _arrows--;
                }
            }
            else
                std::cout << "That isn't one of the options...\n";
        }
//        std::cout << "Please enter a room number:\n";
//        std::getline(std::cin, input);
//    }
    
}
    
void Explorer::missed(const int usedArrow) {
    if(_arrows > 1)
        _arrows -= 1;
    else
        std::cout << "You are out of arrows. Better run away!\n";
};

int Explorer::getExplorerLife() const {
    return _lifeStat;
};
int Explorer::getExplorerRoom() const {
    return _yourRoom;
};
int Explorer::getArrowNum() const {
    return _arrows;
};


