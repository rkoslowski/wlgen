#include "resolver.h"

Resolver::Resolver() :
inputWordSize(0){
    // constructor logic
}

Resolver::~Resolver(){
    
}

void Resolver::fetchURLContent(const char *url) {
    // Create a stringstream to store the fetched content
    std::ostringstream oss;

    // Use system commands to fetch the content (curl or wget)
    const char* command = "curl -s ";  // Use "curl -s" for quiet mode
    char buffer[128];
    std::string result;

    // Open a pipe to the command
    FILE* pipe = popen((std::string(command) + url).c_str(), "r");
    if (!pipe) {
        std::cerr << "Error: Unable to execute the command." << std::endl;
        return EXIT_FAILURE;
    }

    // Read the command output into the stringstream
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        oss << buffer;
    }

    // Close the pipe
    pclose(pipe);

    // Get the fetched content as a string
    std::string fetchedContent = oss.str();
    
    //unneccessary, needs to be replaced properly!
    htmlContent = fetchedContent;

    // Print the fetched content
    std::cout << "Fetched content:\n" << fetchedContent << std::endl;
}

std::string Resolver::extractHTMLBody(const std::string &html){
    // Find the position of <body> and </body> tags
    size_t startPos = html.find("<body>");
    size_t endPos = html.find("</body>");

    // If either tag is not found, return an empty string
    if (startPos == std::string::npos || endPos == std::string::npos) {
        return "";
    }

    // Extract the text between <body> and </body> tags
    return html.substr(startPos + 6, endPos - startPos - 6);

}

std::string Resolver::removeHTMLTags(const std::string &html){
    
    std::string result = html;

    // Remove everything between < and >
    size_t startPos = 0;
    while ((startPos = result.find('<', startPos)) != std::string::npos) {
        size_t endPos = result.find('>', startPos);
        if (endPos != std::string::npos) {
            result.erase(startPos, endPos - startPos + 1);
        } else {
            break; // Break if a matching > is not found
        }
    }

    return result;
}

void Resolver::extractWords(const std::string& line, std::set<std::string>& uniqueWords){
    std::string word;
        for (char c : line) {
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

void Resolver::extractFromFile(std::string file){
    
    // Create an input file stream
    std::ifstream inputFile(file);

    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << file << std::endl;
        return 1; // Exit with an error code
    }

    // Read the file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        // Process each line to extract and insert unique words
        extractWords(line, resolvedWords);
    }

    // Close the file
    inputFile.close();
    std::cout << "Sourcefile contains " << inputWordSize << " words." <<std::endl;
    //std::cout << resolvedWords.size() << std::endl;
    
}

std::set<std::string> Resolver::getUniqueWords(std::string src){
    
    // later replaced by enum type in overloaded getUniqueWords function
    if(src == "url"){
        fetchURLContent("https://jisho.org/");
        std:: string webtext = removeHTMLTags(extractHTMLBody(htmlContent));
        htmlToWords(webtext);
        
    }else if (src == "file"){
        std::string file = "../input.txt";
        extractFromFile(file);
    }
    else{
        //throw (std::exception);
    }
    
    return resolvedWords;
}

void Resolver::htmlToWords(std::string s) { 
    
    // Split the text into words and populate the set
    size_t pos = 0;
    while (pos < s.size()) {
        // Find the next word
        size_t start = s.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", pos);
        size_t end = s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", start);

        if (start != std::string::npos) {
            
            std::string word = s.substr(start, end - start);

            // Add the word to the set
            resolvedWords.insert(word);

            // Move to the next position
            pos = end;
        } else {
            break; // No more words found
        }
    }

}

bool Resolver::isAsciiChar(char c){
    
    // Check if the character value is in the ASCII range (0 to 127)
    return static_cast<unsigned char>(c) <= 127;
    
}
