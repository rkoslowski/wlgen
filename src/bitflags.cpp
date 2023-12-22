#include "bitflags.h"

BitFlags::BitFlags() :
flags_(0)
{
    
}

BitFlags::~BitFlags(){
    
}

void BitFlags::setFlag(const int FLAG) {
    flags_ |= FLAG;
}

bool BitFlags::checkFlag(const int FLAG) {
    return (flags_ & FLAG);
}

void BitFlags::unsetFlag(const int FLAG) {
    flags_ &= ~FLAG;
}

void BitFlags::toggleFlag(const int FLAG) {
    flags_ ^= FLAG;
}

int BitFlags::flagsValue(){
    return flags_;
}

const int BitFlags::getBitOfFlag(std::string op){
    auto it = flagMap.find(op);
    if (it != flagMap.end()) {
        return it->second;
    } else {
        std::cerr << "No valid parameter here" << std::endl;
        return -1;
    }
}
