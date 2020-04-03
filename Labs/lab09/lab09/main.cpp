//
//  main.cpp
//  lab09
//
//  Created by Sarah Carter on 4/2/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>

class IPA_ftw {
public:
    IPA_ftw() {
        std::cout << count_ << " bottles of beer on the wall.\n";
    }

    ~IPA_ftw() {
        std::cout << count_ << " bottles of beer destroyed.\n";
    }
    
    static void printIPACount() {
        std::cout << "Static " << count_ << " bottles of beer on the wall\n";
    }
    
private:
    static int count_;
};

int IPA_ftw::count_ { 0 };

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
    IPA_ftw myBeer;
    myBeer.printIPACount();
    static_Local();
    static_Local();
    static_Local();
    static_Local();
    return 0;
}
