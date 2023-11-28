#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <map>

class Options {
public:
    
    Options();
    Options(int argc, char* argv[]);
    ~Options();
    
    // here parsing and assigning functions
    void parseCLOptions();
    
    void printHelpToTerminal();
    
private:
    //here all options and parameter
    int argc_;
    char** argv_;
    
    std::map<std::string, std::string> options;
    
};
