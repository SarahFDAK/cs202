//
//  fltkCode.cpp
//  IditarodChallenge7
//
//  Created by Sarah Carter on 4/25/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <FL/Fl_Button.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>

#include "fltkCode.hpp"

Fl_Button* quit = nullptr;

Fl_Window* CreateWindow(){
    Fl_Window* win = new Fl_Window(800, 400, "Traveling Salesperson Problem");
    win->begin();
    
    quit = new Fl_Button(350, 350, 100, 25, "Quit");
    quit->color(FL_MAGENTA);
    quit->labelfont(FL_BOLD);
    quit->labelsize(20);
    
    win->end();
    return win;
}
