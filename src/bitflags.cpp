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
    if (op == "-h") {
        return FLAG_H;
    } else if (op == "-f") {
        return FLAG_F;
    } else if (op == "-a") {
        return FLAG_A;
    } else if (op == "-ow") {
        return FLAG_OW;
    } else if (op == "-oj") {
        return FLAG_OJ;
    } else if (op == "-oc") {
        return FLAG_OC;
    } else if (op == "-ll") {
        return FLAG_LL;
    } else if (op == "-lu") {
        return FLAG_LU;
    } else if (op == "-ean") {
        return FLAG_EAN;
    } else if (op == "-ea7") {
        return FLAG_EA7;
    } else if (op == "-ea8") {
        return FLAG_EA8;
    } else if (op == "-s") {
        return FLAG_S;
    } else {
        std::cerr << "no valid parameter here" << std::endl;
        return -1; // or some default value representing an error
    }
}
