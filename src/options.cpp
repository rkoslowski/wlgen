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
    /*
    std::cout << "initial flagvalue: " <<  flags_.flagsValue() << std::endl;
    std::cout << "argc_: " << argc_ << std::endl;
    for (int i = 0; argv_[i] != nullptr; ++i) {
        std::cout << "argv_[" << i << "]: " << argv_[i] << std::endl;
    }
    */
    
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
                    exit(EXIT_FAILURE);
                };
                ++i;
            } else {
                std::cerr << argv_[i] << " flag requires a non-flag parameter." << std::endl;
                exit(EXIT_FAILURE);
            }
        } else {
            auto it = nonParHandlers.find(argv_[i]);
            
            if (it != nonParHandlers.end()) {
                const int bitpos = flags_.getBitOfFlag(argv_[i]);
                flags_.setFlag(bitpos);
                it->second(*this, argv_[i]);
                
                if(std::strcmp(argv_[i], "-h") == 0){
                    if (flags_.flagsValue() != 1) {
                        std::cout << "-help option detected - further input will be ignored" << std::endl;
                    }
                    printHelpToTerminal();
                    exit(EXIT_SUCCESS);
                    
                }else{
                    std::cerr << argv_[i] << " - invalid argument." << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    
    std::cout << flags_.flagsValue() << std::endl;
    if(!(upperLimit >= lowerLimit)){
        std::cerr << "-- upper limit can not be equal or less than the lower limit for the characterlength!" << std::endl;
    };
    
}
    

void Options::printHelpToTerminal(){
    std::cout << "wlgen 1.0 (https://github.com/rkoslowski/wlgen)" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "usage: wlgen [OPTIONS] -f [SOURCE]" << std::endl;
    std::cout << std::left << std::setfill('.') << std::setw(20) << "-h" << std::right << std::setfill('.') << std::setw(25) << "[help]" << " Displays the help interface you are currently looking at." << std::endl;
    std::cout << std::left << std::setfill('.') << std::setw(20) << "-f" << std::right << std::setfill('.') << std::setw(25) << "[file]" << " File containing the source/original text." << std::endl;
    std::cout << std::left << std::setfill('.') << std::setw(20) << "-a" << std::right << std::setfill('.') << std::setw(25) << "[address]" << " Internet address used by the program as source." << std::endl;
    std::cout << std::left << std::setfill('.') << std::setw(20) << "-ow" << std::right << std::setfill('.') << std::setw(25) << "[format wordlist]" << " Outputs the words in a classic wordlist; this option is set by default." << std::endl;
    std::cout << std::left << std::setfill('.') << std::setw(20) << "-oj" << std::right << std::setfill('.') << std::setw(25) << "[format json]" << " Outputs the words in a json-formatted file." << std::endl;
    std::cout << std::left << std::setfill('.') << std::setw(20) << "-oc" << std::right << std::setfill('.') << std::setw(25) << "[format csv]" << " Outputs the words in a csv-formatted file." << std::endl;
    std::cout << std::left << std::setfill('.') << std::setw(20) << "-ll" << std::right << std::setfill('.') << std::setw(25) << "[char limit lower]" << " Sets the lower boundry for the number of characters each word has to have; default is 0." << std::endl;
    std::cout << std::left << std::setfill('.') << std::setw(20) << "-lu" << std::right << std::setfill('.') << std::setw(25) << "[char limit upper]" << " Sets the upper boundry for the number of characters each word has to have." << std::endl;
    std::cout << std::left << std::setfill('.') << std::setw(20) << "-ean" << std::right << std::setfill('.') << std::setw(25) << "[encoding alphanumeric]" << " Specifies the encoding to be alphanumerical so words containing other characters will be ignored." << std::endl;
    std::cout << std::left << std::setfill('.') << std::setw(20) << "-ea7" << std::right << std::setfill('.') << std::setw(25) << "[encoding ascii 7 bit]" << " Specifies the encoding to be ascii with characters 0-127." << std::endl;
    std::cout << std::left << std::setfill('.') << std::setw(20) << "-ea8" << std::right << std::setfill('.') << std::setw(25) << "[encoding ascii 8 bit]" << " Specifies the encoding to be ascii with characters 0-255." << std::endl;
    std::cout << std::left << std::setfill('.') << std::setw(20) << "-s" << std::right << std::setfill('.') << std::setw(25) << "[statistics]" << " Displays statistics after a sucessfull run." << std::endl;

}

