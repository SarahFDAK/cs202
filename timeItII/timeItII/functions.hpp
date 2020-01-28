//
//  functions.hpp
//  timeItII
//
//  Created by Sarah Carter on 1/28/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <vector>
#include <list>
#include <deque>
#include <sstream>
#include <fstream>
#include "StopWatch.hpp"

using std::string;
using std::vector;
using std::list;
using std::deque;
using std::ifstream;

void reportResults(StopWatch myClock, const string &book);

void fillVector(const string &book, vector<string> &textVector, StopWatch &myClock);
void fillList(const string &book, list<string> &textList, StopWatch &myClock);
void fillDeque(const string &book, deque<string> &textDeque, StopWatch &myClock);

void findVector(vector<string> &textVector, const string &book, StopWatch &myClock);
void findList(list<string> &textList, const string &book, StopWatch &myClock);
void findDeque(deque<string> &textDeque, const string &book, StopWatch &myClock);

void sortVector(vector<string> &textVector, const string &book, StopWatch &myClock);
void sortList(list<string> &textList, const string &book, StopWatch &myClock);
void sortDeque(deque<string> &textDeque, const string &book, StopWatch &myClock);


#endif /* functions_hpp */
