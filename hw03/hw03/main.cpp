//
//  main.cpp
//  Sarah Carter
//  2/15/20
//  This program takes user input in command prompt, and, depending on the command entered,
//  will open a requested file, or will read user input into the console. Whichever text input
//  it receives will be tokenized, and each word entered will be listed by line and column number.
//  It also reports, if the user has it open a file, how many MB the file was and how quickly the
//  requested operation was completed.

#include <fstream>
#include <sstream>

#include "tokenizer.hpp"
#include "StopWatch.hpp"

//Opens a requested file and passes it to the ReadLine function
void ReadFile(std::vector<std::string>& args, std::vector<std::string>& tokens,
              std::vector<std::pair<int,int> >& linecols){
    std::ifstream fin(args[2]);
    int line = 0;
    if(args[1] == "--read"){
        //Checks for errors in reading/opening the file
        if(!ReadLine(fin, tokens, linecols, line)){
            if(fin.eof()){
                std::cout << "That's the end" << std::endl;
            }
            else
                std::cout << "Error opening file" << std::endl;
        }
        else
            //Increments the line count (to line 1) and passes all information to ReadLine
            line++;
            ReadLine(fin, tokens, linecols, line);
    }
}

//If the user requests lineonly, passes the opened file only to the LineToTokens function
void ReadFileLine(std::vector<std::string>& args, std::vector<std::string>& tokens){
    std::ifstream fin(args[2]);
    std::string line;
    if(!fin){
        if(fin.eof()){
            std::cout << "That's the end" << std::endl;
        }
        else{
            std::cout << "Error opening file" << std::endl;
        }
    }
    fin >> line;
    LineToTokens(line, tokens);
    std::cout << "Finished\n";
}

//Calculates and prints the time taken to process the file, as well as its size and MB/second
void reportResults(StopWatch myClock, double MB){
    auto myDiff = myClock.getDiff(myClock.setStop());
    double time_in_seconds = myClock.seconds(myDiff);
    double MBps = MB/time_in_seconds;
    std::cout << "Processed " << MB << " MB at: " << " in " << time_in_seconds << " seconds.\n"
    << MBps << "ps" <<std::endl;
}

int main(int argc, const char * argv[]) {
    std::vector<std::string> args;
    std::vector<std::string> tokens;
    std::vector<std::pair<int,int> > linecols;
    StopWatch timer;
    //Fill args vector from argc array
    for(int i = 0; i < argc; i++){
        args.push_back(argv[i]);
    }
    //Checks for user input in command prompt and calls the correct function
    if(argc >=2 && args[1] == "--tokenize"){
        std::ifstream fin(args[2]);
        fin.seekg(0, std::ios_base::seekdir::end);
        double MB = fin.tellg()/1000;
        timer.setStart();
        ReadFile(args, tokens, linecols);
        PrintTokens(std::cout, tokens, linecols);
        timer.setStop();
        reportResults(timer, MB);
    }
    //Checks for user input in command prompt and calls the correct function
    else if(argc >= 3 && args[3] == "--lineonly"){
        std::ifstream fin(args[2]);
        fin.seekg(0, std::ios_base::seekdir::end);
        double MB = fin.tellg()/1000;
        timer.setStart();
        ReadFileLine(args, tokens);
        timer.setStop();
        reportResults(timer, MB);
    }
    //If the user only ran the program with no further specifcations, it requests user input in the console
    else{
        std::cout << "Please enter some text to be processed. It can be as much text "
                  << "as you'd like with blank lines if desired. Type \"end\" to exit.\n";
        std::string input;
        int line = 0;
        //Passes user input to ReadLine function
        do{
            std::getline(std::cin, input);
            //Increments the line count if the user enters a blank line
            if(input.empty()){
                line++;
                LineToTokens("Blank Line", tokens);
            }
            std::istringstream iss(input);
            ReadLine(iss, tokens, linecols,line);
        } while(input != "end");
        PrintTokens(std::cout, tokens, linecols);
        std::cout << "Called console input" << std::endl;
    }
    return 0;
}
