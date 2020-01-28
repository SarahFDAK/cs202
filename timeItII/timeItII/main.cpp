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
    std::cout << "Vector\n";
    ifstream fin(book);
    if(!fin){
        if(fin.eof()){
            std::cout << "End of file." << std::endl;
        }
        else
            std::cout << "Error reading file" << std::endl;
    }
    string sentence, word;
    while(std::getline(fin, sentence)){
        std::istringstream iss(sentence);
        iss >> word;
        textVector.push_back(word);
    }
}

void fillList(const string &book, list<string> &textList){
    std::cout << "List\n";
    ifstream fin(book);
    if(!fin){
        if(fin.eof()){
            std::cout << "End of file." << std::endl;
        }
        else
            std::cout << "Error reading file" << std::endl;
    }
    string sentence, word;
    while(std::getline(fin, sentence)){
        std::istringstream iss(sentence);
        iss >> word;
        textList.push_back(word);
    }
}


void fillDeque(const string &book, deque<string> &textDeque){
    std::cout << "Deque\n";
    ifstream fin(book);
    if(!fin){
        if(fin.eof()){
            std::cout << "End of file." << std::endl;
        }
        else
            std::cout << "Error reading file" << std::endl;
    }
    string sentence, word;
    while(std::getline(fin, sentence)){
        std::istringstream iss(sentence);
        iss >> word;
        textDeque.push_back(word);
    }
}

void findVector(vector<string> &textVector){
    std::cout << "Find\n";
    std::find(textVector.begin(), textVector.end(), "Hello");
}

void reportResults(StopWatch myClock, string &book){
    auto endTime = std::chrono::system_clock::to_time_t(myClock.setStop());
    auto myDiff = myClock.getDiff(myClock.setStop());
    double time_in_seconds = myClock.seconds(myDiff);
    std::cout << "Completed " << book << " at: " << std::ctime(&endTime)
    << " in " << time_in_seconds << " seconds" << std::endl;
}

int main(int argc, const char * argv[]) {
    std::vector<string> books {"AliceInWonderland.txt", "Beowulf.txt", "PrideAndPrejudice.txt", "SoulsOfBlackFolk.txt", "TreasureIsland.txt"};
    StopWatch myClock;
    vector<string> textVector;
    list<string> textList;
    deque<string> textDeque;
    for(size_t i = 0; i < books.size(); i++){
        fillVector(books[i], textVector);
        reportResults(myClock, books[i]);
        fillList(books[i], textList);
        reportResults(myClock, books[i]);
        fillDeque(books[i], textDeque);
        reportResults(myClock, books[i]);
    }
    return 0;
}
