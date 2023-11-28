#include "options.h"

Options::Options()
{
    // constructor logic
}

Options::Options(int argc, char* argv[]) :
argc_(argc),
argv_(argv){
    
};

Options::~Options(){
    
}

void Options::parseCLOptions(){
    
}

void Options::printHelpToTerminal(){
    std::cout << "Usage: tenki" << std::endl;
}
