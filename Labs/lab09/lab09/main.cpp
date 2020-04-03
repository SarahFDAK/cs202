//
//  main.cpp
//  lab09
//
//  Created by Sarah Carter on 4/2/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>

void static_Local(){
    static int thisInt = 0;
    if(!thisInt){
        std::cout << __FUNCTION__ << " is not initialized\n";
        thisInt = 1;
    }
    else{
        std::cout<< __FUNCTION__ << " called " << thisInt << " times.\n";
        thisInt++;
    }
}

int main(int argc, const char * argv[]) {
    static_Local();
    static_Local();
    static_Local();
    static_Local();
    return 0;
}
