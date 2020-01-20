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

int main(int argc, const char * argv[]) {
    
    return 0;
}
