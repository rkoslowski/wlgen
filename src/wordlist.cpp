#include "wordlist.h"

Wordlist::Wordlist():
inputWordSize(0){
}

Wordlist::~Wordlist(){
}

bool Wordlist::validateParameter(){
    
}

void Wordlist::generateWordlist(){
    
    //später abgelöst durch private member
    std::string temp = "../input.txt";
    
    // Create an input file stream
    std::ifstream inputFile(temp);

    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << temp << std::endl;
        return 1; // Exit with an error code
    }

    // Read the file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        // Process each line to extract and insert unique words
        extractWords(line, uniqueWords);
    }

    // Close the file
    inputFile.close();
    std::cout << inputWordSize << std::endl;
    std::cout << uniqueWords.size() << std::endl;
}

void Wordlist::extractWords(const std::string &line, std::set<std::string> &uniqueWords){
    
    std::string word;
        for (char c : line) {
            // Ignore commas and sentence-ending characters
            // maybe only if there is no character following?
            // maybe as option a mode like textmode or password mode
            //if (c == ',' || c == '.') {
            //    continue;
            //}
            if (c != ' ' && c != '\n') {
                word += c;
            } else {
                if (!word.empty()) {
                    uniqueWords.insert(word);
                    //std::cout << "added " << word << std::endl;
                    word.clear();
                    inputWordSize++;
                }
            }
        }
        if (!word.empty()) {
            uniqueWords.insert(word);
            inputWordSize++;
        }
}
