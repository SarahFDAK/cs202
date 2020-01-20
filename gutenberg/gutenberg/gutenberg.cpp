//
//  main.cpp
//  gutenberg
//
//  Created by Sarah Carter on 1/19/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::istream;

string paragraph(const istream &in){
    string line, concat;
    while(getline(cin, line)){
        if(line.empty())
            break;
        concat += (line + "\n");
    }
    return concat;
}

string choice(){
    int choice;
    cout << "Select which book you want to see part of:\n"
    <<"1 - A Tale of Two Cities by Charles Dickens\n"
    <<"2 - Pride And Prejudice by Jane Austen\n"
    <<"3 - The Raven by Edgar Allen Poe\n"
    <<"4 - MacBeth by Shakespeare" << endl;
    switch(std::cin(choice)){
        case 1:
            return "98-0.txt"
        case 2:
            return "1342-0.txt"
        case 3:
            return "pg17192.txt"
        case 4:
            return "pg2264.txt"
        default:
            break;
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
