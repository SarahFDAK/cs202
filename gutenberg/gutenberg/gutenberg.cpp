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
#include <cctype>

using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::istream;
using std::ifstream;

//Check if the line read from the book is blank, i.e. the end of
//a paragraph.
bool blank(const string &line){
    return std::all_of(line.begin(), line.end(), isspace);
}

//Pass the selected book file to be read, line by line.
string paragraph(istream &in){
    string line, concat;
    int linecount = 0;
    
    while(getline(in, line)){
        linecount++;
        //Check if the line is blank, and then how many lines have been read
        if(blank(line)){
            //If it hasn't read at least 20 lines, continue the loop.
            //Otherwise, break.
            if(linecount <= 20)
                continue;
            break;
        }
        //Concatenate the lines into a new string object to be printed.
            else
                concat += (line + "\n");
    }
    return concat;
}

//Give the user the choice of 4 books to see an exerpt from.
string choice(){
    int choice;
    cout << "Select which book you want to see part of:\n"
    <<"1 - A Tale of Two Cities by Charles Dickens\n"
    <<"2 - Pride And Prejudice by Jane Austen\n"
    <<"3 - The Raven by Edgar Allen Poe\n"
    <<"4 - MacBeth by Shakespeare\n" << endl;
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
    }
    return book;
}

int main(int argc, const char * argv[]) {
    //Open the file chosen by the user
    ifstream file(choice());
    if(!file){
        if(eof())
            cout << "That is the end of the book." << endl;
        else{
            cout << "Error opening file." << endl;
            return 9;
        }
    }
    string text = paragraph(file);
    file.close();
    
    cout << text << endl;
    return 0;
}
