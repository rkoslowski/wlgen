#include "wordlist.h"

Wordlist::Wordlist():
inputWordSize(0){
}

Wordlist::Wordlist(int argc, char* argv[]) :
op(argc, argv),
inputWordSize(0){
    
    //generateWordlist();
}

Wordlist::~Wordlist(){
}


void Wordlist::generateWordlist(){
    
    // get options from options object
    uniqueWords = res.getUniqueWords("file");
    generateFile();
}

void Wordlist::generateFile(){
    
    std::string outputFilename = "outputWL.txt";
    // Create an output file stream
    std::ofstream outputFile(outputFilename);

    // Check if the output file is successfully opened
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing: " << outputFilename << std::endl;
    }

    // Write unique words to the output file
    for (const auto &word : uniqueWords) {
        outputFile << word << std::endl;
    }

    // Close the output file
    outputFile.close();
    
    std::cout << uniqueWords.size() << " unique words written to: " << outputFilename << std::endl;
}

