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
        
    void printHelpToTerminal();
    
private:
    //here all options and parameter
    int argc_;
    char** argv_;
    
    void parseCLOptions();
    
    bool validateParameter();
    
    std::map<std::string, std::string> options;
    
};
