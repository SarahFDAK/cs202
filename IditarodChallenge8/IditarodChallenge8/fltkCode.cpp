//
//  fltkCode.cpp
//  IditarodChallenge8
//
//  Created by Sarah Carter on 4/26/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <FL/Fl_Widget.H>
#include <FL/Fl_Box.H>

#include "fltkCode.hpp"


Fl_Window* CreateWindow(){
    Fl_Window* win = new Fl_Window(800, 800, "Hunt The Wumpus Layout");
    win->begin();
    
    
    
    win->end();
    return win;
}
