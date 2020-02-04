//
//  main.cpp
//  lab04
//
//  Created by Sarah Carter on 2/4/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using std::ifstream;
using std::ofstream;

int main(int argc, const char * argv[]) {

    std::cout << "Please enter a number\n";
    int entered;
    std::cin >> entered;
    std::cin.ignore();
    ofstream fout("lab.txt", std::ios::app);
    std::string s;
    while(s != "end"){
        std::getline(std::cin, s);
        if(s != "end")
            for(int i = 0; i < entered; i++){
                fout << s << std::endl;
            }
    }
    ifstream fin("lab.txt");
    std::string read;
    while(std::getline(fin, read))
        std::cout << read << std::endl;
    return 0;
}
