//
//  BookPrettyPrinter
//  Sarah Carter
//  2/17/20
//  This program is meant to read a file containing a couple paragraphs
//  from Pride and Prejudice by Jane Austen, then print it in wrapped
//  text format, with the option to print with HTML tags. I spent so long on
//  the main program for this homework, that this is as far as I could get
//  without turning it in any later. At this point, it puts the paragraphs
//  into the vector and prints them.

#include <iostream>
#include <fstream>
#include <sstream>

#include "tokenizer.hpp"

using std::cout;
using std::endl;
using std::string;

//Check that the file opens correctly
bool openFile(std::ifstream& fin){
    if(!fin){
        if(fin.eof()){
            return true;
        }
        else{
            cout << "Error opening file" << endl;
            return false;
        }
    }
    return true;
}

//Print the contents of the paragraphs vector
void printWrap(const std::vector<string>& paragraphs){
    for(auto it:paragraphs){
        cout << it << endl;
    }
}

int main(int argc, const char * argv[]) {
    std::ifstream fin("pAndP.txt");
    std::vector<string> paragraphs;
    //Call the ReadLine function from the tokenizer source and pass
    //the paragraphs vector to it
    while(openFile(fin)){
        if(fin.eof())
            break;
        ReadLine(fin, paragraphs);
    }
    printWrap(paragraphs);
    return 0;
}
