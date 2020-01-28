//
//  main.cpp
//  timeItII
//
//  Created by Sarah Carter on 1/27/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "functions.hpp"

using std::string;
using std::vector;
using std::list;
using std::deque;

int main(int argc, const char * argv[]) {
    std::vector<string> books {"AliceInWonderland.txt", "Beowulf.txt", "PrideAndPrejudice.txt", "SoulsOfBlackFolk.txt", "TreasureIsland.txt"};
    StopWatch myClock;
    vector<string> textVector;
    list<string> textList;
    deque<string> textDeque;
    for(size_t i = 0; i < books.size(); i++){
        fillVector(books[i], textVector, myClock);
        fillList(books[i], textList, myClock);
        fillDeque(books[i], textDeque, myClock);
        findVector(textVector, books[i], myClock);
        findList(textList, books[i], myClock);
        findDeque(textDeque, books[i], myClock);
        sortVector(textVector, books[i], myClock);
        sortList(textList, books[i], myClock);
        sortDeque(textDeque, books[i], myClock);
    }
    return 0;
}
