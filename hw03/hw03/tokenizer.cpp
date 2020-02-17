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
    std::cout << line << std::endl;
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
        std::cout << textLine << std::endl;
        lines++;
        int columns = 0;
        std::string token;
        for(char& c: textLine){
            if(c == ' '){
                LineToTokens(" ", tokens);
                columns++;
            }
            else if(c == '\n'){
                LineToTokens("Blank Line", tokens);
            }
            else{
                std::istringstream iss(textLine);
                std::string token;
                iss >> token;
                LineToTokens(token, tokens);
                columns++;
            }
            linecols.push_back(std::make_pair(lines, columns));
        }
//        std::istringstream iss(textLine);
//        while(iss >> token){
//            std::cout << token << std::endl;
//            columns++;
//            if(LineToTokens(token, tokens)){
//                linecols.push_back(std::make_pair(lines, columns));
//            }
//        }
    }
    return true;
}

void PrintTokens(std::ostream& os, const std::vector<std::string>& tokens,
                 const std::vector<std::pair<int, int>>& linecols){
    std::cout << "Printing...\n";
    for(size_t i = 0; i < tokens.size(); i++){
        if(tokens[i] != " "){
            std::cout << "Line " << setw(3) << linecols[i].first << ", Column "
            << setw(3) << linecols[i].second << ": \"" << tokens[i] << "\"\n";
        }
    }
    
}
