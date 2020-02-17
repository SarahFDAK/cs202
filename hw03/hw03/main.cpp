//
//  main.cpp
//  Sarah Carter
//  2/15/20
//  This program takes user input in command prompt, and, depending on the command entered,
//  will open a requested file, or will read user input into the console. Whichever text input
//  it receives will be tokenized, and each word entered will be listed by line and column number.
//

#include <fstream>
#include <sstream>

#include "tokenizer.hpp"
#include "StopWatch.hpp"

void ReadFile(std::vector<std::string>& args, std::vector<std::string>& tokens, std::vector<std::pair<int,int> >& linecols){
    std::ifstream fin(args[2]);
    int line = 0;
    if(args[1] == "--read"){
        if(!ReadLine(fin, tokens, linecols, line)){
            if(fin.eof()){
                std::cout << "That's the end" << std::endl;
            }
            else
                std::cout << "Error opening file" << std::endl;
        }
        else
            line++;
            ReadLine(fin, tokens, linecols, line);
    }
}

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
    for(int i = 0; i < argc; i++){
        args.push_back(argv[i]);
    }
    if(argc >=2 && args[1] == "--read"){
        std::ifstream fin(args[2]);
        fin.seekg(0, std::ios_base::seekdir::end);
        double MB = fin.tellg()/1000;
        timer.setStart();
        ReadFile(args, tokens, linecols);
        PrintTokens(std::cout, tokens, linecols);
        timer.setStop();
        reportResults(timer, MB);
    }
    else if(argc >= 2 && args[1] == "--lineonly"){
        std::ifstream fin(args[2]);
        fin.seekg(0, std::ios_base::seekdir::end);
        double MB = fin.tellg()/1000;
        timer.setStart();
        ReadFileLine(args, tokens);
        timer.setStop();
        reportResults(timer, MB);
    }
    else{
        std::cout << "Please enter some text to be processed. It can be as much text as you'd like, with blank lines if desired. Type \"end\" to exit.\n";
        std::string input;
        int line = 0;
        do{
            std::getline(std::cin, input);
            if(input.empty())
                line++;
            std::istringstream iss(input);
            ReadLine(iss, tokens, linecols,line);
        } while(input != "end");
        PrintTokens(std::cout, tokens, linecols);
        std::cout << "Called console input" << std::endl;
    }
    return 0;
}
