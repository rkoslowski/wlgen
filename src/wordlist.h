#pragma once

#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <set>

class Wordlist {
public:

    Wordlist();
    ~Wordlist();
    
    bool validateParameter();
    
    void generateWordlist();
    
    void printHelpToTerminal();

 private:
    
    int inputWordSize;
    std::set<std::string> uniqueWords;
    // arguments, parameters and option here
    
    void extractWords(const std::string& line, std::set<std::string>& uniqueWords);
    
    void generateFile();
    
    bool isAsciiChar(char c);
};
