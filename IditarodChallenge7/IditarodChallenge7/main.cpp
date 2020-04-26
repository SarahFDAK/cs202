//
//  main.cpp
//  IditarodChallenge7
//  Sarah Carter
//  CS202
//  This program creates a GUI via FLTK for user interaction with the Traveling
//  Salesperson Problem program I created for previous homeworks.
//

#include <iostream>

#include "fltkCode.hpp"
#include "SVGcode.hpp"

int main(int argc, const char * argv[]) {
    Fl_Window* program = CreateWindow();
    
    program->show();
    return Fl::run();
}
