//
//  main.cpp
//  Sarah Carter
//  1/18/20
//  This program reads user input from the command line and returns
//  a conversion of their input from Fahrenheit to Celcius, or Celcius
//  to Fahrenheit.
//

#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;

// Takes a char* array entered in the command line, converts it to a
// double, and converts the double from a Fahrenheit to Celcius value, and
// returns the celcius value.
double cpp_ftoc(const char* str){
    //Use istringstream to change the input from chars to a double.
    std::istringstream convert(str);
    double f;
    convert >> f;
    //Convert from Fahrenheit to Celcius.
    double c = (f - 32.0) / 1.8;
    return c;
}

// Takes a char* array entered in the command line, converts it to a
// double, and converts the double from a Celcius to Fahrenheit value, and
// returns the Fahrenheit value.
double c_ctof(const char* str){
    //Create end pointer for strtod function
    char* end;
    //Interprets the char input as a double.
    double cel = strtod(str, &end);
    double f = (cel * 1.8) + 32.0;
    return f;
}

int main(int argc, const char * argv[]) {
    std::vector <std::string> args;
    //Push input into argv array into args string array
    for(int index = 0; index < argc; index++){
        args.push_back(argv[index]);
    }
    
    //Check if user input specifies ftoc
    if(argc >= 2 && (args[1] == "--ftoc" || args[1] == "-ftoc" || args[1]
                     == "ftoc")){
        //Cast input to a double to check if the temperature is below
        //absolute zero. Also check if input is digits and not text.
        std::istringstream checkc(args[2].c_str());
        double azf;
        //Make sure temperature is entered in correct format
        if(checkc >> azf){
            //If the temp is too cold, exit the program.
            if(azf < -459.67){
                cout << "That temperature does not exist." << endl;
                return 0;
            }
            //Print the results for the user.
            cout << args[2] << " Fahrenheit = " << cpp_ftoc(args[2].c_str())
            << " Celcius." << endl;
        }
        else{
            cout << "Please enter the temperature as digits, not text" << endl;
            return 0;
        }
    }
    //Check if user specifies ctof
    if(argc >= 2 && (args[1] == "--ctof" || args[1] == "-ctof" || args[1]
                     == "ctof")){
        //Use istringstream to check temp existence, and confirm temperature
        //was entered as digits and not text.
        std::istringstream checkc(args[2].c_str());
        double azc;
        if(checkc >> azc){
            //If temp is less than absolute zero, exit the program.
            if(azc < -273.15){
                cout << "That temperature does not exist." << endl;
                return 0;
            }
            //Print the results for the user.
            cout << args[2] << " Celcius = " << c_ctof(args[2].c_str())
            << " Fahrenheit." << endl;
        }
        else{
            cout << "Please enter the temperature as digits, not text" << endl;
            return 0;
        }
    }
    return 0;
}


