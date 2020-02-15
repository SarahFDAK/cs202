//
//  tokenizer.cpp
//  hw03
//
//  Created by Sarah Carter on 2/12/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <sstream>

#include "tokenizer.hpp"

bool LineToTokens(const std::string& line, std::vector<std::string>& tokens){
    if(line == "")
        return false;
    tokens.push_back(line);
    return true;
}
bool ReadLine(std::istream& is, std::vector<std::string>& tokens,
              std::vector<std::pair<int, int>>& linecols){
    std::string textLine;
    int lines = 0;
    int columns = 0;
    if(!is){
        if(is.eof()){
            std::cout << "That's the end!" << std::endl;
            return false;
        }
        return false;
    }
    while(is){
        ++lines;
        while(is >> textLine){
            ++columns;
            LineToTokens(textLine, tokens);
            linecols.push_back(std::make_pair(lines, columns));
        }
    }
    return true;
}
void PrintTokens(std::ostream& os, const std::vector<std::string>& tokens,
                 const std::vector<std::pair<int, int>>& linecols){
    
}
