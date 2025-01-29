#define _CRT_SECURE_NO_WARNINGS
#include"IOAble.h"
#include <iostream>

using namespace std;

// provides functionality for reading from and writing to input and output streams
namespace seneca {
    // insert the information of an IOAble object into ostream
    ostream& operator<<(ostream& os, const IOAble& ioable) {
        ioable.write(os);
        return os;
    }
    // extract information from an istream into an IOAble object
    istream& operator>>(istream& is, IOAble& ioable) {
        ioable.read(is);
        return is;
    }

}