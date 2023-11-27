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
    //std::cout << inputWordSize << std::endl;
    //std::cout << uniqueWords.size() << std::endl;
    
    generateFile();
}

void Wordlist::extractWords(const std::string &line, std::set<std::string> &uniqueWords){
    
    std::string word;
        for (char c : line) {
            // maybe only if there is no character following?
            // maybe as option a mode like textmode or password mode
            if (std::isalnum(c)) {
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

void Wordlist::generateFile(){
    
    std::string outputFilename = "outputWL.txt";
    // Create an output file stream
    std::ofstream outputFile(outputFilename);

    // Check if the output file is successfully opened
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing: " << outputFilename << std::endl;
        return 1; // Exit with an error code
    }

    // Write unique words to the output file
    for (const auto &word : uniqueWords) {
        outputFile << word << std::endl;
    }

    // Close the output file
    outputFile.close();

    std::cout << uniqueWords.size() << " unique words written to: " << outputFilename << std::endl;
}

bool Wordlist::isAsciiChar(char c){
    
    // Check if the character value is in the ASCII range (0 to 127)
    return static_cast<unsigned char>(c) <= 127;
    
}
