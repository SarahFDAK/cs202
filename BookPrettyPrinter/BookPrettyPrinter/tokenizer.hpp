//
//  tokenizer.hpp
//  hw03
//
//  Created by Sarah Carter on 2/12/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef tokenizer_hpp
#define tokenizer_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

//Declare tokenizer functions
bool LineToTokens(const std::string& line, std::vector<std::string>& tokens);
bool ReadLine(std::istream& is, std::vector<std::string>& tokens);
void PrintTokens(std::ostream& os, const std::vector<std::string>& tokens,
                 const std::vector<std::pair<int, int> >& linecols);

#endif /* tokenizer_hpp */
