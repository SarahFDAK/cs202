//
//  main.cpp
//  hw02
//
//  Created by Sarah Carter on 2/2/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "MotoGP.hpp"

Riders ValR {"Valentino", "Rossi", "Yamaha", "Italy", 40, 46};
Riders MarM {"Marc", "Marquez", "Honda", "Spain", 27, 93};
Riders AndD {"Andrea", "Dovizioso", "Ducati", "Italy", 33, 4};
Riders MavV {"Maverick", "Viñales", "Yamaha", "Spain", 25, 12};
Riders TakN {"Takaaki", "Nakagami", "Honda", "Japan", 28, 30};

TEST_CASE("Does it work?", "[Riders]"){
    std::list<std::shared_ptr<Riders>> riders2020;
    push(riders2020, ValR);
    push(riders2020, MarM);
    printList(riders2020);
}
