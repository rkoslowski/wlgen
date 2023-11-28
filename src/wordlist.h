#pragma once

#include <fstream>
#include <set>
#include "options.h"

class Wordlist {
public:

    Wordlist();
    Wordlist(int argc, char* argv[]);
    ~Wordlist();
    
    bool validateParameter();
    
    void generateWordlist();

 private:
    
    Options op;
    
    int inputWordSize;
    std::set<std::string> uniqueWords;
    // arguments, parameters and option here
    
    void extractWords(const std::string& line, std::set<std::string>& uniqueWords);
    
    void generateFile();
    
    bool isAsciiChar(char c);
};
