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
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>

#include "fltkCode.hpp"
#include "SVGcode.hpp"

Fl_Button* quit = nullptr;
Fl_Button* browse = nullptr;
Fl_Button* readFile = nullptr;
Fl_Button* randomly = nullptr;
Fl_Button* greedy = nullptr;
Fl_Button* sorted = nullptr;
Fl_Output* fileChoice = nullptr;

Fl_Button* runSVG = nullptr;
Fl_Button* close = nullptr;
Fl_Text_Display* results = nullptr;
Fl_Text_Buffer* buff = nullptr;

std::string userFile;
CityList list;
CityNode node;
TSPSolver solveIt;

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

void fileReader_cb(Fl_Widget*, void* data) {
    
    std::ifstream fin(userFile);
    
    //Read contents of file while checkFile tests are true
    while(list.checkFile(fin)){
        list.readFile(fin, node);
    }
}



//Close window when "Exit" button is clicked
void OnExitClicked_cb(Fl_Widget* w, void* data){
    if(!data) return;
    Fl_Window* win = (Fl_Window*)data;
    win->hide();
}

Fl_Window* PopupWindow(){
    Fl_Window* display = new Fl_Window(600, 300, "Results");
    display->begin();
    
    results = new Fl_Text_Display(10, 30, 580, 200);
    close = new Fl_Button(250, 275, 100, 30, "Close");
    close->color(FL_DARK_RED);
    close->labelsize(20);
    close->labelfont(FL_BOLD);
    
    close->callback(OnExitClicked_cb, (void*) display);
    
    display->end();
    return display;
}

Fl_Window* CreateWindow(){
    Fl_Window* win = new Fl_Window(800, 400, "Traveling Salesperson Problem");
    win->begin();
    
    fileChoice = new Fl_Output(140, 145, 630, 30);
    
    browse = new Fl_Button(30, 150, 100, 20, "Browse Files");
    readFile = new Fl_Button(350, 180, 100, 20, "Read File");
    randomly = new Fl_Button(212, 210, 125, 20, "Solve Randomly");
    greedy = new Fl_Button(340, 210, 125, 20, "Solve Greedy");
    sorted = new Fl_Button(468, 210, 125, 20, "Solve Sorted");
    
    browse->callback(browseClicked);
    readFile->callback(fileReader_cb);
    
    quit = new Fl_Button(350, 350, 100, 25, "Quit");
    quit->color(FL_MAGENTA);
    quit->labelfont(FL_BOLD);
    quit->labelsize(20);
    
    quit->callback(OnExitClicked_cb, (void*) win);
    
    win->end();
    return win;
}
