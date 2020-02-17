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
//    if(line == "\n"){
//        tokens.push_back("Blank Line");
//        return false;
//    }
//    else
    tokens.push_back(line);
    return true;
}

bool ReadLine(std::istream& is, std::vector<std::string>& tokens,
              std::vector<std::pair<int, int> >& linecols){
    std::string textLine;
    int lines = 0;
    if(!is){
        return false;
    }
    while(std::getline(is, textLine)){
        if(textLine == "end")
            return false;
        lines++;
        if(textLine.empty()){
            LineToTokens("Blank Line", tokens);
            continue;
        }
        int columns = 0;
        std::string token;
        std::istringstream iss(textLine);
            while(iss >> token){
                std::cout << token << std::endl;
                columns++;
                LineToTokens(token, tokens);
            }
        for(char& c: textLine){
            if(c == ' '){
                columns++;
                auto it = tokens.begin();
                tokens.insert(it, columns, " ");
            }
            linecols.push_back(std::make_pair(lines, columns));
        }
    }
    return true;
}

void PrintTokens(std::ostream& os, const std::vector<std::string>& tokens,
                 const std::vector<std::pair<int, int>>& linecols){
    for(size_t i = 0; i < tokens.size(); i++){
        if(tokens[i] != " "){
            std::cout << "Line " << setw(3) << linecols[i].first << ", Column "
            << setw(3) << linecols[i].second << ": \"" << tokens[i] << "\"\n";
        }
    }
    
}
