//
//  functions.cpp
//  timeItII
//
//  Created by Sarah Carter on 1/28/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "functions.hpp"

//Stop the timer, calculate the duration, and report end time and duration
//in seconds for each function operation.
void reportResults(StopWatch myClock, const string &book){
    auto endTime = std::chrono::system_clock::to_time_t(myClock.setStop());
    auto myDiff = myClock.getDiff(myClock.setStop());
    double time_in_seconds = myClock.seconds(myDiff);
    std::cout << "Completed " << book << " at: " << std::ctime(&endTime)
    << " in " << time_in_seconds << " seconds" << std::endl;
}

//Fill the vector container from the book file, the run reportResults function
//to stop the timer and report how long it took. Also report the number of elements
//in each book to compare lengths.
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
    std::cout << "Contains " << textVector.size() << " elements." << std:: endl;
}

//Fill the list container from the book file and report the times to read
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

//Fill the deque container and report the time it took to read
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

//Functions to apply find algorithm to each container, with a cloch restart method
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

//Functions to apply sort algorithm to each container, with a cloch restart method
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
