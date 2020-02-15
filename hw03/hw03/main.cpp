//
//  main.cpp
//  hw03
//
//  Created by Sarah Carter on 2/11/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <fstream>

#include "tokenizer.hpp"

void ReadFile(std::vector<std::string>& args, std::vector<std::string>& tokens, std::vector<std::pair<int,int>>& linecols){
    std::ifstream fin(args[2]);
    if(!ReadLine(fin, tokens, linecols)){
        if(fin.eof()){
            std::cout << "That's the end" << std::endl;
        }
        else
            std::cout << "Error opening file" << std::endl;
    }
    else
        ReadLine(fin, tokens, linecols);
}

int main(int argc, const char * argv[]) {
    std::vector<std::string> args;
    std::vector<std::string> tokens;
    std::vector<std::pair<int,int>> linecols;
    for(int i = 0; i < argc; i++){
        args.push_back(argv[i]);
    }
    if(argc >=2 && args[1] == "--read"){
        ReadFile(args, tokens, linecols);
    }
    else if(argc >= 2 && args[1] == "--lineonly"){
        
    }
    return 0;
}
