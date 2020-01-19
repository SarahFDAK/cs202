//
//  main.cpp
//  hw0
//
//  Created by Sarah Carter on 1/18/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <charconv>

using std::cout;
using std::cin;
using std::endl;

double cpp_ftoc(const char* str){
    std::istringstream convert(str);
    double f;
    convert >> f;
    double c = (f - 32.0) / 1.8;
    return c;
}

double c_ctof(const char* str){
    char* end;
    double cel = strtod(str, &end);
    double f = (cel * 1.8) + 32.0;
    return f;
}

int main(int argc, const char * argv[]) {
    std::vector <std::string> args;

    for(int index = 0; index < argc; index++){
        args.push_back(argv[index]);
    }
    if(argc >= 2 && args[1] == "--ftoc"){
        std::istringstream checkc(args[2].c_str());
        double azf;
        checkc >> azf;
        if(azf < -459.67){
            cout << "That temperature does not exist." << endl;
            return 0;
        }
        cout << args[2] << " Fahrenheit = " << cpp_ftoc(args[2].c_str()) << " Celcius."
        << endl;
    }
    if(argc >= 2 && args[1] == "--ctof"){
        std::istringstream checkc(args[2].c_str());
        double azc;
        checkc >> azc;
        if(azc < -273.15){
            cout << "That temperature does not exist." << endl;
            return 0;
        }
        cout << args[2] << " Celcius = " << c_ctof(args[2].c_str()) << " Fahrenheit."
        << endl;
    }
    return 0;
}


