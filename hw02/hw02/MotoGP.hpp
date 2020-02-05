//
//  MotoGP.hpp
//  hw02
//
//  Created by Sarah Carter on 2/2/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef MotoGP_hpp
#define MotoGP_hpp

#include <stdio.h>
#include <iostream>
#include <list>

struct Riders{
    std::string firstName;
    std::string lastName;
    std::string team;
    std::string country;
    int riderAge;
    int riderNum;
};

inline bool operator==(const Riders& a, const Riders& b) {
    return (a.firstName == b.firstName) && (a.lastName == b.lastName);
}
inline bool operator!=(const Riders& a, const Riders& b) {
    return !(a == b);
}

void riderList();
void push(std::list<std::shared_ptr<Riders>> &riders2020, const Riders &comp);
void popQueue(std::list<std::shared_ptr<Riders>> &riders2020);
void popStack(std::list<std::shared_ptr<Riders>> &riders2020);
void insertPtr(std::list<std::shared_ptr<Riders>> &riders2020, const Riders &comp, std::list<std::shared_ptr<Riders>>::iterator n);
void find(std::list<std::shared_ptr<Riders>> &riders2020, const Riders &comp);
void printList(std::list<std::shared_ptr<Riders>> &riders2020);


#endif /* MotoGP_hpp */
