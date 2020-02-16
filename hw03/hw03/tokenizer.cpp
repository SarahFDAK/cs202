//
//  tokenizer.cpp
//  hw03
//
//  Created by Sarah Carter on 2/12/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <sstream>
#include <iomanip>

#include "tokenizer.hpp"

using std::setw;

bool LineToTokens(const std::string& line, std::vector<std::string>& tokens){
    tokens.push_back(line);
    if(line == "\n")
        return false;
    return true;
}

bool ReadLine(std::istream& is, std::vector<std::string>& tokens,
              std::vector<std::pair<int, int>>& linecols){
    std::string textLine;
    std::istringstream iss(textLine);
    std::string token;
    int lines = 1;
    int columns = 1;
    if(!is){
        return false;
    }
    while(std::getline(is, textLine)){
        lines++;
        while(iss >> token){
            columns++;
            while(LineToTokens(token, tokens)){
                linecols.push_back(std::make_pair(lines, columns));
            }
        }
    }
    return true;
}

void PrintTokens(std::ostream& os, const std::vector<std::string>& tokens,
                 const std::vector<std::pair<int, int>>& linecols){
    for(size_t i = 0; i < tokens.size(); i++){
        std::cout << "Line " << setw(3) << linecols[i].first << ", Column "
        << setw(3) << linecols[i].second << ": \"" << tokens[i] << "\n";
    }
    
}
