//
//  main.cpp
//  hw0
//
//  Created by Sarah Carter on 1/18/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;

double cpp_ftoc(const char* str){
    std::stringstream read;
    double F = 0.0;
    read << str;
    if(read >> F)
        cout << F << endl;
    double C = ((F - 32.0) * (5/9));
    return C;
}

int main(int argc, const char * argv[]) {
    std::vector <std::string> args;

    for(int index = 0; index < argc; index++){
        args.push_back(argv[index]);
    }
    if(argc >= 2 and args[1] == "--ftoc"){
        cout << args[2] << " Fahrenheit = " << cpp_ftoc(args[2].c_str()) << " Celcius." << endl;
    }
    return 0;
}


