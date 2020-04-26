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
#include "SVGcode.hpp"

Fl_Button* quit = nullptr;
Fl_Button* browse = nullptr;
Fl_Button* randomly = nullptr;
Fl_Button* greedy = nullptr;
Fl_Button* sorted = nullptr;
Fl_Output* fileChoice = nullptr;

std::string userFile;

void browseClicked(Fl_Widget*, void* data){
    Fl_Native_File_Chooser fileFind;
    fileFind.title("Select File to Analyze");
    fileFind.type(Fl_Native_File_Chooser::BROWSE_FILE);
    switch( fileFind.show() ){
        case -1: fprintf(stderr, "ERROR: %s\n", fileFind.errmsg()); break;    // ERROR
        case  1: fprintf(stderr, "*** CANCEL\n"); break;        // CANCEL
        default:                                 // PICKED FILE
            fileChoice->value(fileFind.filename());
          break;
    }
    std::string choice = fileChoice->value();
    std::istringstream is(choice);
    is >> userFile;
}

Fl_Window* CreateWindow(){
    Fl_Window* win = new Fl_Window(800, 400, "Traveling Salesperson Problem");
    win->begin();
    
    fileChoice = new Fl_Output(140, 145, 630, 30);
    
    browse = new Fl_Button(30, 150, 100, 20, "Browse Files");
    randomly = new Fl_Button(212, 180, 125, 20, "Solve Randomly");
    greedy = new Fl_Button(340, 180, 125, 20, "Solve Greedy");
    sorted = new Fl_Button(468, 180, 125, 20, "Solve Sorted");
    
    browse->callback(browseClicked);
    
    quit = new Fl_Button(350, 350, 100, 25, "Quit");
    quit->color(FL_MAGENTA);
    quit->labelfont(FL_BOLD);
    quit->labelsize(20);
    
    win->end();
    return win;
}
