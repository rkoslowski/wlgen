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
    
private:
    //here all options and parameter
    int argc_;
    char** argv_;
    
    void parseCLOptions();
    
    //void handleNonParameterOption(std::string op);
    
    //void handleParameterOption(std::string op, const char* arg);
    
    std::string fileArg;
    std::string urlArg;
    int lowerLimit;
    int upperLimit;
    
    void printHelpToTerminal();
    
    //------------------ BIT FLAGS ------------------//
    const int FLAG_H = 1 << 0;      // 000000000001
    const int FLAG_F = 1 << 1;      // 000000000010
    const int FLAG_A = 1 << 2;      // 000000000100
    const int FLAG_OW = 1 << 3;     // 000000001000
    const int FLAG_OJ = 1 << 4;     // 000000010000
    const int FLAG_OC = 1 << 5;     // 000000100000
    const int FLAG_LL = 1 << 6;     // 000001000000
    const int FLAG_LU = 1 << 7;     // 000010000000
    const int FLAG_EAN = 1 << 8;    // 000100000000
    const int FLAG_EA7 = 1 << 9;    // 001000000000
    const int FLAG_EA8 = 1 << 10;   // 010000000000
    const int FLAG_S = 1 << 11;     // 100000000000
    //---------------- BIT FLAGS END ----------------//
    
    int flags_;
    
    void setFlag(const int FLAG);
    
    bool checkFlag(const int FLAG);
    
    void unsetFlag(const int FLAG);
    
    void toggleFlag(const int FLAG);
    
    // Define a type for the handling functions
    using HandlerFunction1 = std::function<void(Options&, std::string, const char* parameter)>;
    
    // Define a type for the handling functions
    using HandlerFunction2 = std::function<void(Options&, std::string)>;
};

/*
 
 // Define individual flags using powers of 2
 const int FLAG_OPTION1 = 1 << 0; // 0001
 const int FLAG_OPTION2 = 1 << 1; // 0010
 const int FLAG_OPTION3 = 1 << 2; // 0100
 
 // Set individual flags
 flags |= FLAG_OPTION1; // Set flag 1
 flags |= FLAG_OPTION2; // Set flag 2

 // Alternatively, set multiple flags at once
 flags = FLAG_OPTION1 | FLAG_OPTION2; // Set both flag 1 and flag 2
 
 // Check if a specific flag is set
 if (flags & FLAG_OPTION1) {
     // Flag 1 is set
 }

 // Check if multiple flags are set
 if ((flags & (FLAG_OPTION1 | FLAG_OPTION2)) == (FLAG_OPTION1 | FLAG_OPTION2)) {
     // Both flag 1 and flag 2 are set
 }
 
 // Unset a specific flag
 flags &= ~FLAG_OPTION1; // Unset flag 1

 // Unset multiple flags
 flags &= ~(FLAG_OPTION1 | FLAG_OPTION2); // Unset both flag 1 and flag 2
 
 // Toggle a specific flag
 flags ^= FLAG_OPTION1; // Toggle flag 1

 // Toggle multiple flags
 flags ^= (FLAG_OPTION1 | FLAG_OPTION2); // Toggle both flag 1 and flag 2

 
 */
