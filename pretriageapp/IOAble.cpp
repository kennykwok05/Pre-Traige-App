/*
* Kenny Kwok
* kkwok21@nyseneca.ca
* 130049232
* 12/03/2024
Citation and Sources...
Final Project Milestone 2
Module: IOAble.cpp
Filename: IOAble.cpp
Version 1.0
Author   John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include"IOAble.h"
#include <iostream>

using namespace std;
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