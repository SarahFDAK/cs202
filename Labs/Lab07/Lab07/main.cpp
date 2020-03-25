//
//  main.cpp
//  Lab07
//
//  Created by Sarah Carter on 3/25/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "SnowDump.hpp"

int main(int argc, const char * argv[]) {
    const SnowDump myTown;
    std::cout << myTown << "\n";
    
    SnowDump otherTown;
    otherTown.setCity( "Anchorage" );
    otherTown.setState( "Alaska" );
    otherTown.setSnowFall( 2000.0 );
    
    std::cout << otherTown << "\n";
    
    SnowDump town3;
    town3 = otherTown;
    std::cout << town3 << "\n";
    return 0;
}
