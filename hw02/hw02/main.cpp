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
    REQUIRE(*riders2020.back() == ValR);
    push(riders2020, MarM);
    REQUIRE(*riders2020.back() != ValR);
    push(riders2020, MavV);
    push(riders2020, AndD);
    REQUIRE(*riders2020.front() == ValR);
    std::cout << "Removing pointer from the beginning of the list.\n\n";
    popQueue(riders2020);
    REQUIRE(*riders2020.front() != ValR);
    std::cout << "Add more pointers to the back of the list.\n\n";
    push(riders2020, TakN);
    push(riders2020, ValR);
    std::cout << "Removing pointer from the end of the list.\n\n";
    popStack(riders2020);
    REQUIRE(*riders2020.back() != ValR);
    std::cout << "Inserting pointer into list.\n\n";
    insertPtr(riders2020, MarM, ValR);
    REQUIRE(*riders2020.front() == ValR);
    printList(riders2020);
}
