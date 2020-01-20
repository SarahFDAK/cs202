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
using std::ifstream;

string paragraph(const istream &in){
    string line, concat;
    while(getline(std::cin, line)){
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
    <<"4 - MacBeth by Shakespeare"
    <<"If you make no choice, the automatic selection is The Brothers Grimm"
    << endl;
    std::cin >> choice;
    string book;
    switch(choice){
        case 1:
            book = "98-0.txt";
            break;
        case 2:
            book = "1342-0.txt";
            break;
        case 3:
            book = "pg17192.txt";
            break;
        case 4:
            book = "pg2264.txt";
            break;
        default:
            book = "52521-0.txt";
            break;
    }
    return book;
}

int main(int argc, const char * argv[]) {
    ifstream file(choice());
    string text = paragraph(file);
    file.close();
    
    cout << text << endl;
    return 0;
}
