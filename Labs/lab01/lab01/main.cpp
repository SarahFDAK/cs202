//
//  main.cpp
//  lab01
//
//  Created by Sarah Carter on 1/21/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void status(string jumpsuit){
    if(jumpsuit == "on")
        cout << "You're safe!\n" << endl;
    else if(jumpsuit == "torn")
        cout << "You might want to fix the tear...\n" << endl;
    else
        cout << "WTF Put your jumpsuit on!!\n" << endl;
}

int main(int argc, const char * argv[]) {
    int condition;
    string response;
    vector<string> jumpsuit {"exit", "on", "torn", "off"};
    do{
        cout << "What is the condition of your jumpsuit?" << endl;
        for(size_t i = 0; i < jumpsuit.size(); i++){
            cout << i << " = " << jumpsuit[i]  << endl;
        }
        cin >> condition;
        switch(condition){
            case 0: response = jumpsuit[0];
                break;
            case 1: response = jumpsuit[1];
                break;
            case 2: response = jumpsuit[2];
                break;
            case 3: response = jumpsuit[3];
                break;
            default: response = jumpsuit[0];
                break;
        }
        status(response);
    } while (response != "exit");
    return 0;
}
