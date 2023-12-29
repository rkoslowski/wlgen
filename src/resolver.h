#pragma once

#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <set>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>

class Resolver {
public:
    
    Resolver();
    //Resolver(/*FILE SOURCE*/);
    //Resolver(/*URL SOURCE*/);
    ~Resolver();
    
    std::set<std::string> getUniqueWords(std::string src);
    
private:
    
    std::string htmlContent;
    
    void fetchURLContent(const char* url);
    
    std::string extractHTMLBody(const std::string& html);
    
    std::string removeHTMLTags(const std::string& html);
    
    void extractWords(const std::string& line, std::set<std::string>& uniqueWords);
    
    void extractFromFile(std::string file);
    
    std::set<std::string> resolvedWords;
    
    int inputWordSize;
    
    void htmlToWords(std::string s);
    
    bool isAsciiChar(char c);
    
};
