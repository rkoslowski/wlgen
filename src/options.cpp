#include "options.h"

Options::Options()
{
    // constructor logic
}

Options::Options(int argc, char* argv[]) :
argc_(argc),
argv_(argv){
    parseCLOptions();
};

Options::~Options(){
    
}

void Options::parseCLOptions(){
    
    
    std::cout << argc_ << std::endl;
    
    for (int i = 0; argv_[i] != nullptr; ++i) {
        std::cout << "argv_[" << i << "]: " << argv_[i] << std::endl;
    }
    
    
}

bool Options::validateParameter(){
    
}


void Options::printHelpToTerminal(){
    std::cout << "Usage: wlgen" << std::endl;
}

