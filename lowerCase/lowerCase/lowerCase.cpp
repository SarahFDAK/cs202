//
//  lowerCase.cpp
//  Sarah Carter
//  2/4/20
//  This program takes a char* c-string and checks for upper case letters.
//  Any upper case letters it finds are converted to lower case and the new,
//  all lower case string is printed.
//

#include <iostream>

//Function to take a char* string and convert it all to lowercase
void to_lower(char* s){
    //Iterate through string until the null character is reached
    for(int i = 0; s[i] != 0; i++){
        //Check if the character is in the upper case alphabet
        if(s[i] >= 'A' && s[i] <= 'Z'){
            //If so, add 32 to convert it to lower case
            s[i]+=32;
            std::cout << s[i];
        }
        //Otherwise, just print the character as-is and continue the loop
        else {
            std::cout << s[i];
            continue;
        }
    }
}


int main(int argc, const char * argv[]) {
    //Declare an initial char array
    char str[13] = "HelLo ThErE!";
    //Create a char* and point it at the char array
    char* s;
    s = str;
    //Pass the char* to the function and end the program.
    to_lower(s);
    std::cout << std::endl;
    return 0;
}
