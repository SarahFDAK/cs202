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


int main(int argc, const char * argv[]) {
    std::ifstream fin("pAndP.txt");
    std::vector<string> paragraphs;
    while(openFile(fin)){
        if(fin.eof())
            break;
        ReadLine(fin, paragraphs);
    }
    
    return 0;
}
