//
//  main.cpp
//  BookPrettyPrinter
//
//  Created by Sarah Carter on 2/17/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include "tokenizer.hpp"

using std::cout;
using std::endl;
using std::string;

bool openFile(std::ifstream& fin){
    if(!fin){
        if(fin.eof()){
            cout << "End of file" << endl;
            return true;
        }
        else{
            cout << "Error opening file" << endl;
            return false;
        }
    }
    return true;
}

void fillParagraphs(std::vector<string>& paragraphs, const std::vector<string>& tokens){
    string par;
    for(auto it:tokens){
        cout << it << endl;
    }
}

int main(int argc, const char * argv[]) {
    std::ifstream fin("pAndP.txt");
    string text;
    std::vector<string> paragraphs;
    std::vector<string> tokens;
    while(openFile(fin)){
        if(fin.eof())
            break;
        string words;
        std::getline(fin, text);
        ReadLine(fin, tokens)
    }
    fillParagraphs(paragraphs, tokens);
    return 0;
}
