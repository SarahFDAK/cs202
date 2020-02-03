//
//  MotoGP.cpp
//  hw02
//
//  Created by Sarah Carter on 2/2/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <sstream>
#include "catch.hpp"
#include "MotoGP.hpp"

using std::list;
using std::shared_ptr;
using std::make_shared;

void riderList(){
    Riders VR = {"Valentino", "Rossi", "Italy", "Yamaha", 40, 46};
    Riders MM = {"Marc", "Marquez", "Spain", "Honda", 27, 93};
    Riders AD = {"Andrea", "Dovizioso", "Italy", "Ducati", 33, 4};
    Riders MV = {"Maverick", "Viñales", "Spain", "Yamaha", 25, 12};
    Riders TN = {"Takaaki", "Nakagami", "Japan", "Honda", 28, 30};
}


void push(list<shared_ptr<Riders>> &riders2020, const Riders &comp){
    riders2020.push_back(make_shared<Riders>(comp));
}

void popQueue(list<shared_ptr<Riders>> &riders2020){
    riders2020.pop_front();
}

void popStack(list<shared_ptr<Riders>> &riders2020){
    riders2020.pop_back();
}

void insert(list<shared_ptr<Riders>> &riders2020, const Riders &comp,
            list<shared_ptr<Riders>>::iterator n){
    riders2020.insert(n, make_shared<Riders>(comp));
}

void printList(list<shared_ptr<Riders>> &riders2020){
    
}
