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
    if(line == "\n"){
        tokens.push_back("Blank Line");
        return false;
    }
    else
        tokens.push_back(line);
    return true;
}

bool ReadLine(std::istream& is, std::vector<std::string>& tokens,
              std::vector<std::pair<int, int> >& linecols, int& lines){
    std::string textLine;
    if(!is){
        return false;
    }
    while(std::getline(is, textLine)){
        std::cout << textLine << std::endl;
        if(textLine == "end")
            return false;
        lines++;
        int columns = 0;
        if(textLine.empty()){
            LineToTokens("Blank Line", tokens);
            columns++;
            linecols.push_back(std::make_pair(lines, columns));
//            continue;
        }
        std::string token;
        std::istringstream iss(textLine);
        if(textLine[0] == ' '){
            LineToTokens(" ", tokens);
            columns++;
            linecols.push_back(std::make_pair(lines, columns));
        }
        while(iss >> token){
            columns++;
            LineToTokens(token, tokens);
            linecols.push_back(std::make_pair(lines, columns));
            columns++;
            LineToTokens(" ", tokens);
            linecols.push_back(std::make_pair(lines, columns));
        }
    }
    for(auto i: linecols)
        std::cout << i.first << " " << i.second << std::endl;
    return true;
}

void PrintTokens(std::ostream& os, const std::vector<std::string>& tokens,
                 const std::vector<std::pair<int, int>>& linecols){
    for(auto i = 0; i < tokens.size(); i++){
        if(tokens[i] != " "){
            std::cout << "Line " << setw(3) << linecols[i].first << ", Column "
            << setw(3) << linecols[i].second << ": \"" << tokens[i] << "\"\n";
        }
    }
    
}
