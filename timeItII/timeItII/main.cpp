//
//  main.cpp
//  timeItII
//
//  Created by Sarah Carter on 1/27/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>

#include "StopWatch.hpp"

using std::string;
using std::vector;
using std::list;
using std::deque;
using std::ifstream;

void fillVector(const string &book, vector<string> &textVector){
    ifstream fin(book);
    if(!fin){
        if(fin.eof()){
            std::cout << "End of file." << std::endl;
        }
        else
            std::cout << "Error reading file" << std::endl;
    }
    string word;
    while(std::cin >> word){
        textVector.push_back(word);
    }
}

void reportResults(StopWatch myClock, string &book){
    auto endTime = std::chrono::system_clock::to_time_t(myClock.setStop());
    auto myDiff = myClock.getDiff(myClock.setStop());
    double time_in_seconds = myClock.seconds(myDiff);
    std::cout << "Completed " << book << " items at: " << std::ctime(&endTime)
    << " in " << time_in_seconds << " seconds" << std::endl;
}

int main(int argc, const char * argv[]) {
    std::vector<string> books {"AliceInWonderland.txt", "Beowulf.txt", "PrideAndPrejudice.txt", "SoulsOfBlackFolk.txt", "TreasureIsland.txt"};
    StopWatch myClock;
    vector<string> textVector;
    list<string> textList;
    deque<string> textDeque;
//    for(size_t i = 0; i < books.size(); i++){
        fillVector(books[1], textVector);
        reportResults(myClock, books[1]);
//    }
    return 0;
}
