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
std::string solution;
std::string solveType;
CityList list;
CityNode node;
TSPSolver solveIt;
CityPath randomPath;
CityPath greedyPath;
CityPath sortedPath;

//Open file browser for user to select a file to process
void browseClicked(Fl_Widget*, void* data){
    Fl_Native_File_Chooser fileFind;
    fileFind.title("Select File to Analyze");
    fileFind.filter("*.tsp");
    fileFind.type(Fl_Native_File_Chooser::BROWSE_FILE);
    switch( fileFind.show() ){
        case -1: fprintf(stderr, "ERROR: %s\n", fileFind.errmsg()); break;    // ERROR
        case  1: fprintf(stderr, "*** CANCEL\n"); break;        // CANCEL
        default:                                 // PICKED FILE
            fileChoice->value(fileFind.filename());
          break;
    }
    std::string choice = fileChoice->value();
    //Assign file path to userFile string
    std::istringstream is(choice);
    is >> userFile;
}

//Run readFile function
void fileReader_cb(Fl_Widget* w, void* data) {
    Fl_Window* win = (Fl_Window*)w;
    win = ErrorWindow();
    if(userFile.empty()){
        win->show();
        return;
    }
    
    std::ifstream fin(userFile);
    
    //Read contents of file while checkFile tests are true
    while(list.checkFile(fin)){
        list.readFile(fin, node);
    }
}

void randomClicked_cb(Fl_Widget* w, void* data){
    Fl_Window* win = (Fl_Window*)w;
    win = ErrorWindow();
    if(list.getCityVectorCount() == 0){
        win->show();
        return;
    }
    Fl_Text_Buffer* randomBuff = (Fl_Text_Buffer*)data;
    solution.clear();
    
    solveIt.SolveRandomly(list, 25, randomPath);
    solution = "The shortest distance solved randomly is " + std::to_string(solveIt.getBestDist()) + " miles.";
    results -> buffer(randomBuff);
    randomBuff->text(solution.c_str());
    solveType = "Random";
}

void greedyClicked_cb(Fl_Widget* w, void* data){
    Fl_Window* win = (Fl_Window*)w;
    win = ErrorWindow();
    if(list.getCityVectorCount() == 0){
        win->show();
        return;
    }
    
    Fl_Text_Buffer* greedyBuff = (Fl_Text_Buffer*)data;
    solution.clear();
    
    solveIt.SolveGreedy(list, greedyPath);
    solution = "The shortest distance solved greedily is " + std::to_string(solveIt.getBestDist()) + " miles.";
    results -> buffer(greedyBuff);
    greedyBuff->text(solution.c_str());
    solveType = "Greedy";
}

void sortedClicked_cb(Fl_Widget* w, void* data){
    Fl_Window* win = (Fl_Window*)w;
    win = ErrorWindow();
    if(list.getCityVectorCount() == 0){
        win->show();
        return;
    }
    
    Fl_Text_Buffer* sortedBuff = (Fl_Text_Buffer*)data;
    solution.clear();
    
    solveIt.SolveMyWay(list, sortedPath);
    solution = "The shortest distance with longitudes sorted is " + std::to_string(solveIt.getBestDist()) + " miles.";
    results -> buffer(sortedBuff);
    sortedBuff->text(solution.c_str());
    solveType = "MyWay";
}

//Close window when "Exit" button is clicked
void OnExitClicked_cb(Fl_Widget* w, void* data){
    if(!data) return;
    Fl_Window* win = (Fl_Window*)data;
    win->hide();
}

Fl_Window* ErrorWindow(){
    Fl_Window* error = new Fl_Window(400, 200, "Error");
    error->set_modal();
    
    error->begin();
    Fl_Box* msg = new Fl_Box(10, 20, 380, 70, "No file selected for analysis.");
    msg->labelsize(18);
    Fl_Button* close = new Fl_Button(150, 150, 100, 30, "Close");
    close->callback(OnExitClicked_cb, (void*)error);
    close->labelsize(16);
    close->labelfont(FL_BOLD);
    error->end();
    
    return error;
}

//Create an SVG file for whichever solve method was last run
void svgClicked_cb(Fl_Widget* w, void* data){
    CityPath option;
    Fl_Window* noFile = (Fl_Window*)w;
    noFile = ErrorWindow();
    //Create error window to let user know they haven't run a solve method yet
    Fl_Window* errorWin = new Fl_Window(400, 200, "Error");
    errorWin->set_modal();
    errorWin->align(FL_ALIGN_CENTER);
    errorWin->color(FL_RED);
    errorWin->begin();
    Fl_Box* message = new Fl_Box(10, 20, 380, 70, "You didn't run any solve functions!");
    message->labelsize(20);
    message->box(FL_UP_BOX);
    message->color(FL_WHITE);
    Fl_Button* close = new Fl_Button(150, 150, 100, 30, "Close");
    close->callback(OnExitClicked_cb, (void*)errorWin);
    close->labelsize(16);
    close->labelfont(FL_BOLD);
    errorWin->end();
    
    if(solveType == "Random")
        option = randomPath;
    else if(solveType == "Greedy")
        option = greedyPath;
    else if(solveType == "MyWay")
        option = sortedPath;
    else if(list.getCityVectorCount() == 0){
        noFile->show();
        return;
    }
    else{
        errorWin->show();
        return;
    }
    
    std::string path = ChartPath(list, option, list.getMinLong(), list.getMaxLong(), list.getMinLat(), list.getMaxLat());
    std::string points = ChartPoints(list, option, list.getMinLong(), list.getMaxLong(), list.getMinLat(), list.getMaxLat());
    std::string build = buildSVG(path, points, 2500, 2250);
    CreateFile(build, solveType);
    
    Fl_Window* done = new Fl_Window(200, 100, "Completed");
    done->set_modal();
    done->begin();
    Fl_Box* msg = new Fl_Box(20, 10, 160, 40, "SVG File Created!");
    msg->labelsize(18);
    Fl_Button* close2 = new Fl_Button(50, 60, 100, 30, "Close");
    close2->callback(OnExitClicked_cb, (void*)done);
    close2->labelsize(16);
    close2->labelfont(FL_BOLD);
    done->end();
    done->show();
}

Fl_Window* CreateWindow(){
    Fl_Window* win = new Fl_Window(800, 400, "Traveling Salesperson Problem");
    win->begin();
    
    fileChoice = new Fl_Output(140, 25, 630, 30);
    
    browse = new Fl_Button(30, 30, 100, 20, "Browse Files");
    readFile = new Fl_Button(325, 60, 150, 30, "Import Selected File");
    randomly = new Fl_Button(205, 130, 125, 30, "Solve Randomly");
    greedy = new Fl_Button(340, 130, 125, 30, "Solve Greedy");
    sorted = new Fl_Button(475, 130, 125, 30, "Solve Sorted");
    buff = new Fl_Text_Buffer();
    results = new Fl_Text_Display(10, 170, 780, 50);
    runSVG = new Fl_Button(325, 270, 150, 30, "Create SVG File");
    
    browse->callback(browseClicked);
    readFile->callback(fileReader_cb);
    
    randomly->callback(randomClicked_cb, (void*) buff);
    greedy->callback(greedyClicked_cb,(void*)buff);
    sorted->callback(sortedClicked_cb, (void*)buff);
    
    runSVG->callback(svgClicked_cb);
    
    quit = new Fl_Button(350, 350, 100, 25, "Quit");
    quit->color(FL_MAGENTA);
    quit->labelfont(FL_BOLD);
    quit->labelsize(20);
    
    quit->callback(OnExitClicked_cb, (void*) win);

    
    win->end();
    return win;
}
