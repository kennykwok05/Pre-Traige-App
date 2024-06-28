/*
* Kenny Kwok
* kkwok21@nyseneca.ca
* 130049232
* 05/03/2024
Citation and Sources...
Final Project Milestone 1
Module: Time.h
Filename: Time.h
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

#ifndef SENECA_TIME_H_
#define SENECA_TIME_H_
#include <iostream>


namespace seneca {
    class Time {
        unsigned int m_minutes; // to keep number of minutes

    public:
        Time& reset(); // resets the Time object to the current time 
        Time(unsigned int min = 0u); // constructor that initializes a Time object
        void write(std::ostream& ostr) const; // writes the time into ostream in the HH:MM format
        bool read(std::istream& istr); // reads the time from istream in the H:M format
        operator unsigned int() const; // overloads the cast to unsigned int for the Time class

        Time& operator*=(int val); // overloads the multipimecation assignment *= for the Time class
        Time& operator-=(const Time& D); // overloads the subtraction assignment -= for the Time class
        Time operator-(const Time& T) const; // same as -=, except that it does not have a side effect
    };
    std::ostream& operator<<(std::ostream& ostr, const Time& time); // overload the insertion operator to insert a Time object into an ostream
    std::istream& operator>>(std::istream& istr, Time& time); // overload the extraction operator to extract data from an istream object into the Time object
}
#endif // !SENECA_TIME_H_