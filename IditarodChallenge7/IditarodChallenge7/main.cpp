//
//  main.cpp
//  IditarodChallenge7
//
//  Created by Sarah Carter on 4/24/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>

#include "fltkCode.hpp"
#include "SVGcode.hpp"

int main(int argc, const char * argv[]) {
    Fl_Window* program = CreateWindow();
    
    program->show();
    return Fl::run();
}
