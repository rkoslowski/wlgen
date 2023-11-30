#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include "bitflags.h"

class Options {
public:
    
    Options();
    Options(int argc, char* argv[]);
    ~Options();
    
private:
    //here all options and parameter
    int argc_;
    char** argv_;
    
    BitFlags flags_;
    
    void parseCLOptions();
    
    //void handleNonParameterOption(std::string op);
    
    //void handleParameterOption(std::string op, const char* arg);
    
    std::string fileArg;
    std::string urlArg;
    int lowerLimit;
    int upperLimit;
    
    void printHelpToTerminal();
    
    using HandlerFunction1 = std::function<void(Options&, std::string, const char* parameter)>;
    
    using HandlerFunction2 = std::function<void(Options&, std::string)>;
};
