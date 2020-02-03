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
    std::cout << "Pushing pointers to the back of the list.\n\n";
    push(riders2020, ValR);
    push(riders2020, MarM);
    push(riders2020, MavV);
    push(riders2020, AndD);
    printList(riders2020);
    std::cout << "Removing pointers from the beginning of the list.\n\n";
    popQueue(riders2020);
    std::cout << "Add more pointers to the back of the list.\n\n";
    push(riders2020, TakN);
    push(riders2020, ValR);
    printList(riders2020);
    std::cout << "Removing pointers from the end of the list.\n\n";
    popStack(riders2020);
    std::cout << "Inserting pointer into list.\n\n";
//    insert(riders2020, ValR, 1);
}
