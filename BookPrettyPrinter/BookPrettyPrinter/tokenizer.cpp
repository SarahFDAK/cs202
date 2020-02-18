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

//Fills tokens vector with each element read
bool LineToTokens(const std::string& line, std::vector<std::string>& tokens){
    //This doesn't seem to actually do anything
    if(line.empty()){
        tokens.push_back("Blank Line");
        return false;
    }
    else
        tokens.push_back(line);
    return true;
}

//Calls LineToTokens to fill the tokens vector, and also fills the linecols vector to report
//which line and column each word was in

//Modified for the current program - does not count lines or columns
bool ReadLine(std::istream& is, std::vector<std::string>& tokens){
    std::string textLine;
    if(!is){
        return false;
    }
    while(std::getline(is, textLine)){

        //Create Blank Line entry in tokens vector
        if(textLine.empty()){
            LineToTokens("Blank Line", tokens);

        }
        std::string token;
        std::istringstream iss(textLine);
        //Fill the tokens and linecols vectors from input stream
        while(std::getline(iss,token)){
            LineToTokens(token, tokens);

        }
    }
    return true;
}

//Prints a formatted list of the lines, columns, and words from the input stream
void PrintTokens(std::ostream& os, const std::vector<std::string>& tokens,
                 const std::vector<std::pair<int, int>>& linecols){
    for(auto i = 0; i < tokens.size(); i++){
        if(tokens[i] != " "){
            std::cout << "Line " << setw(3) << linecols[i].first << ", Column "
            << setw(3) << linecols[i].second << ": \"" << tokens[i] << "\"\n";
        }
    }
    
}
