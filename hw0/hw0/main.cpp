//
//  main.cpp
//  hw0
//
//  Created by Sarah Carter on 1/18/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    std::vector <std::string> args;
    for(int index = 0; index < argc; index++){
        args.push_back(argv[index]);
        std::cout << args[index] << std::endl;
    }
    return 0;
}
