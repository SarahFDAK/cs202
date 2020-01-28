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

void reportResults(StopWatch myClock, const string &book){
    auto endTime = std::chrono::system_clock::to_time_t(myClock.setStop());
    auto myDiff = myClock.getDiff(myClock.setStop());
    double time_in_seconds = myClock.seconds(myDiff);
    std::cout << "Completed " << book << " at: " << std::ctime(&endTime)
    << " in " << time_in_seconds << " seconds" << std::endl;
}

void fillVector(const string &book, vector<string> &textVector, StopWatch &myClock){
    std::cout << "Vector\n";
    myClock.setStart();
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
    reportResults(myClock, book);
}

void fillList(const string &book, list<string> &textList, StopWatch &myClock){
    std::cout << "List\n";
    myClock.setStart();
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
    reportResults(myClock, book);
}


void fillDeque(const string &book, deque<string> &textDeque, StopWatch &myClock){
    std::cout << "Deque\n";
    myClock.setStart();
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
    reportResults(myClock, book);
}

void findVector(vector<string> &textVector, const string &book, StopWatch &myClock){
    std::cout << "Find Vector\n";
    myClock.setStart();
    std::find(textVector.begin(), textVector.end(), "hello");
    reportResults(myClock, book);
}

void findList(list<string> &textList, const string &book, StopWatch &myClock){
    std::cout << "Find List\n";
    myClock.setStart();
    std::find(textList.begin(), textList.end(), "hello");
    reportResults(myClock, book);
}

void findDeque(deque<string> &textDeque, const string &book, StopWatch &myClock){
    std::cout << "Find Deque\n";
    myClock.setStart();
    std::find(textDeque.begin(), textDeque.end(), "hello");
    reportResults(myClock, book);
}

void sortVector(vector<string> &textVector, const string &book, StopWatch &myClock){
    std::cout << "Sort Vector\n";
    myClock.setStart();
    std::sort(textVector.begin(), textVector.end());
    reportResults(myClock, book);
}

void sortList(list<string> &textList, const string &book, StopWatch &myClock){
    std::cout << "Sort List\n";
    myClock.setStart();
    textList.sort();
    reportResults(myClock, book);
}

void sortDeque(deque<string> &textDeque, const string &book, StopWatch &myClock){
    std::cout << "Sort Deque\n";
    myClock.setStart();
    std::sort(textDeque.begin(), textDeque.end());
    reportResults(myClock, book);
}

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
