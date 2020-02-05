//
//  MotoGP.cpp
//  hw02
//
//  Created by Sarah Carter on 2/2/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <sstream>
#include <algorithm>
#include "MotoGP.hpp"

using std::list;
using std::shared_ptr;
using std::make_shared;

void push(list<shared_ptr<Riders>> &riders2020, const Riders &comp){
    riders2020.push_back(make_shared<Riders>(comp));
}

void popQueue(list<shared_ptr<Riders>> &riders2020){
    riders2020.pop_front();
}

void popStack(list<shared_ptr<Riders>> &riders2020){
    riders2020.pop_back();
}

void insertPtr(list<shared_ptr<Riders>> &riders2020, const Riders &comp1, const Riders &comp2){
    list<shared_ptr<Riders>>::iterator n;
    n = find_if(riders2020.begin(), riders2020.end(), [&](auto x){
        return *x == comp1;
        });;
    riders2020.insert(n, make_shared<Riders>(comp2));
}

void printList(list<shared_ptr<Riders>> &riders2020){
    for(auto i : riders2020){
        std::cout << (*i).firstName << " " << (*i).lastName << "\n" << (*i).country
        << " age: " << (*i).riderAge << "\n" << (*i).team << " #" << (*i).riderNum
        << "\n\n";
    }
}
