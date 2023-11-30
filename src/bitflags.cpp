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
