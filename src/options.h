#pragma once

#include <iostream>
#include <map>
#include <cstring>
#include <iomanip>
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
    
    //friend void handleNonParameterOption(std::string op);
    
    //friend void handleParameterOption(std::string op, const char* arg);
    
    std::string fileArg = "";
    std::string urlArg = "";
    int lowerLimit = 0;
    int upperLimit = 64; //serving as "everything is okay" since the longest word in english major dict is 45 char long
    
    void printHelpToTerminal();
    
    using HandlerFunction1 = std::function<void(Options&, std::string, const char* parameter)>;
    
    using HandlerFunction2 = std::function<void(Options&, std::string)>;
};
