//
//  main.cpp
//  Sarah Carter
//  1/27/20
//  This program enters the text from classic novels into vector, list, and
//  deque containers, times how long it takes to read; then runs a find for a
//  specific word and times how long it takes; then runs a sort on each
//  container and times how long that takes.
//

#include "functions.hpp"

using std::string;
using std::vector;
using std::list;
using std::deque;

int main(int argc, const char * argv[]) {
    //Create a vector to hold 5 book titles for use in the program.
    std::vector<string> books {"AliceInWonderland.txt", "Beowulf.txt", "PrideAndPrejudice.txt", "SoulsOfBlackFolk.txt", "TreasureIsland.txt"};
    //Create StopWatch object, and vector, list and deque to hold texts.
    StopWatch myClock;
    vector<string> textVector;
    list<string> textList;
    deque<string> textDeque;
    //Run all functions for each book in the books vector
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
        //Clear containers for next book
        textVector.clear();
        textList.clear();
        textDeque.clear();
    }
    return 0;
}
