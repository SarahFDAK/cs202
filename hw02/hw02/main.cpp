//
//  main.cpp
//  Sarah Carter
//  2/4/20
//  This program creates a struct, then creates a linked list of shared pointers
//  to elements of that struct, and uses the Catch 2 test case to test if it
//  effectively pushes the ponters to the back of the list, pops them from the
//  front, pops them from the back, finds, and inserts them.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "MotoGP.hpp"

//Initialize struct objects
Riders ValR {"Valentino", "Rossi", "Yamaha", "Italy", 40, 46};
Riders MarM {"Marc", "Marquez", "Honda", "Spain", 27, 93};
Riders AndD {"Andrea", "Dovizioso", "Ducati", "Italy", 33, 4};
Riders MavV {"Maverick", "Viñales", "Yamaha", "Spain", 25, 12};
Riders TakN {"Takaaki", "Nakagami", "Honda", "Japan", 28, 30};

//Run the test case
TEST_CASE("Does it work?", "[Riders]"){
    //Create the list of shared pointers
    std::list<std::shared_ptr<Riders>> riders2020;
    std::cout << "Pushing pointers to the back of the list.\n\n";
    
    //Push objects to the back of the list, and run checks to make sure they are
    //entered in the correct order.
    push(riders2020, ValR);
    REQUIRE(*riders2020.back() == ValR);
    push(riders2020, MarM);
    REQUIRE(*riders2020.back() != ValR);
    push(riders2020, MavV);
    push(riders2020, AndD);
    REQUIRE(*riders2020.front() == ValR);
    std::cout << "Removing pointer from the beginning of the list.\n\n";
    
    //Remove a pointer from the front of the list and check to make sure it's gone
    popQueue(riders2020);
    REQUIRE(*riders2020.front() != ValR);
    std::cout << "Add more pointers to the back of the list.\n\n";
    push(riders2020, TakN);
    push(riders2020, ValR);
    
    //After adding objects to the list again, make sure the last added object
    //is at the end.
    REQUIRE(*riders2020.back() == ValR);
    std::cout << "Removing pointer from the end of the list.\n\n";
    
    //Remove a pointer from the end of the list and check that it is no longer
    //there.
    popStack(riders2020);
    REQUIRE(*riders2020.back() != ValR);
    std::cout << "Inserting pointer into list.\n\n";
    
    //Insert a pointer into the list in a place relative to another pointer already
    //in the list. Make sure the pointer being found is at the beginning.
    REQUIRE(*riders2020.front() == MarM);
    insertPtr(riders2020, MarM, ValR);
    REQUIRE(*riders2020.front() == ValR);
    
    //Print the final list to the console
    printList(riders2020);
}
