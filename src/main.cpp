#include "wordlist.h"

int main(int argc, char* argv[]) {

    try {
        
        Wordlist wl(argc, argv);

    } catch (const std::exception& e) {
        
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}
