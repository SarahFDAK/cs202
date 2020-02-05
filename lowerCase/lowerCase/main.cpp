//
//  main.cpp
//  lowerCase
//
//  Created by Sarah Carter on 2/4/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>

void to_lower(char* s){
    for(int i = 0; s[i] != 0; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i]+=32;
            std::cout << s[i];
        }
    }
}


int main(int argc, const char * argv[]) {
    char str[13] = "HelLo ThErE!";
    char* s;
    s = str;
    return 0;
}
