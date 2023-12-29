#include "options.h"

Options::Options()
{
    
}

Options::Options(int argc, char* argv[]) :
argc_(argc),
argv_(argv){
    parseCLOptions();
};

Options::~Options(){
    
}

void handleNonParameterOption(Options& options, std::string op){
    //options.lowerLimit = 11;
}

void handleParameterOption(Options& options, std::string op, const char* arg){
    
    
}

void Options::parseCLOptions(){
    
    //std::cout << flags_.flagsValue() << std::endl;
    
    //std::cout << argc_ << std::endl;
    
    for (int i = 0; argv_[i] != nullptr; ++i) {
        std::cout << "argv_[" << i << "]: " << argv_[i] << std::endl;
    }
    
    std::map<std::string, HandlerFunction2> nonParHandlers = {
        {"-h", handleNonParameterOption},
        {"-ow", handleNonParameterOption},
        {"-oj", handleNonParameterOption},
        {"-oc", handleNonParameterOption},
        {"-ean", handleNonParameterOption},
        {"-ea7", handleNonParameterOption},
        {"-ea8", handleNonParameterOption},
        {"-s", handleNonParameterOption}
    };
    
    std::map<std::string, HandlerFunction1> ParHandlers = {
        {"-f", handleParameterOption},
        {"-a", handleParameterOption},
        {"-ll", handleParameterOption},
        {"-lu", handleParameterOption}
    };
    
    for (int i = 1; i < argc_; ++i) {
        auto it = ParHandlers.find(argv_[i]);
        
        if (it != ParHandlers.end()) {
            if (i + 1 < argc_ && argv_[i + 1][0] != '-') {
                it->second(*this, argv_[i],argv_[i + 1]);
                const int bitpos = flags_.getBitOfFlag(argv_[i]);
                flags_.setFlag(bitpos);
                
                if(std::strcmp(argv_[i], "-f") == 0){
                    fileArg = argv_[i + 1];
                }else if(std::strcmp(argv_[i], "-a") == 0){
                    urlArg = argv_[i + 1];
                }else if(std::strcmp(argv_[i], "-ll") == 0){
                    lowerLimit = std::stoi(argv_[i + 1]);
                }else if(std::strcmp(argv_[i], "-lu") == 0){
                    upperLimit = std::stoi(argv_[i + 1]);
                }else{
                    std::cerr << "Error parsing the option: " << argv_[i] << "and its value" << argv_[i + 1] << std::endl;
                };
                ++i;
            } else {
                std::cerr << argv_[i] << " flag requires a non-flag parameter." << std::endl;
            }
        } else {
            auto it = nonParHandlers.find(argv_[i]);
            
            if (it != nonParHandlers.end()) {
                const int bitpos = flags_.getBitOfFlag(argv_[i]);
                flags_.setFlag(bitpos);
                it->second(*this, argv_[i]);
                
            }else{
                std::cerr << argv_[i] << " - invalid argument." << std::endl;
            }
        }
        
    }
    
    std::cout << flags_.flagsValue() << std::endl;
    if(!(upperLimit >= lowerLimit)){
        std::cerr << "-- upper limit can not be equal or less than the lower limit for the characterlength!" << std::endl;
    }
}
    

void Options::printHelpToTerminal(){
    std::cout << "Usage: wlgen" << std::endl;
}

