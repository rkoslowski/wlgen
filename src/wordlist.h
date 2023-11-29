#pragma once

#include "options.h"
#include "resolver.h"

class Wordlist {
public:

    Wordlist();
    Wordlist(int argc, char* argv[]);
    ~Wordlist();
    
    void generateWordlist();
    
 private:
    
    Options op;
    
    Resolver res;
    
    //later in statistics class
    int inputWordSize;
    
    std::set<std::string> uniqueWords;
    
    void generateFile(/*filetype*/);
    
};
