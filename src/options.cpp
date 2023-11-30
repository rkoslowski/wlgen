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


void handleNonParameterOption(Options& options, std::string op) {
    
    //options.flags_.setFlag(const int FLAG_H);
    /*
     std::string bitflag = (op.length() > 0 && op[0] == '-') ? op.substr(1) : op;
     
     for (char& c : bitflag) {
         c = std::toupper(static_cast<unsigned char>(c));
     }
     
     bitflag = "FLAG_" + bitflag;
     
     flags_ = 1;
     */
    
}

void handleParameterOption(Options& options, std::string op, const char* arg) {
    
}

void Options::parseCLOptions(){
    
    std::cout << flags_.flagsValue() << std::endl;
    
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
            // Check if the next argument exists
            if (i + 1 < argc_ && argv_[i + 1][0] != '-') {
                // Call the associated handling function with the parameter
                it->second(*this, argv_[i],argv_[i + 1]);
                const int bitpos = flags_.getBitOfFlag(argv_[i]);
                flags_.setFlag(bitpos);
                ++i; // Skip the next argument (parameter)
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
    
}
    

void Options::printHelpToTerminal(){
    std::cout << "Usage: wlgen" << std::endl;
}

