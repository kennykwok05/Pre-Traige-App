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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
#include "Time.h"
#include "iomanip"

using namespace std;

namespace seneca {
    // resets the Time object to the current time 
    Time& Time::reset() {
        m_minutes = U.getTime();
        return *this;
    }
    // constructor that initializes a Time object
    Time::Time(unsigned int min) {
        if (min >= 0) {
            m_minutes = min;
        }
        // if no value, then set to default (0)
        else {
            m_minutes = 0;
        }
    }
    // writes the time into ostream in the HH:MM format
    void Time::write(std::ostream& ostr) const {
        // convert to hour and minutes
        unsigned int hours = m_minutes / 60;
        unsigned int mins = m_minutes % 60;
        // if 1 digit, prints a 0 at start (hours)
        if (hours < 10) {
            ostr << "0" << hours;
        }
        else {
            ostr << hours;
        }
        ostr << ":";
        // if 1 digit, prints a 0 at start (minutes)
        if (mins < 10) {
            ostr << "0" << mins;
        }
        else {
            ostr << mins;
        }
    }
    // reads the time from istream in the H:M format
    bool Time::read(std::istream& istr) {
        char colon;
        unsigned int hours = 0u, mins = 0u;

        istr >> hours;
        if (istr.peek() == '\n') {
            istr.setstate(std::ios::failbit);
            return false;
        }

        istr >> colon;
        if (istr.fail() || colon != ':' || colon == '\n') {
            istr.setstate(std::ios::failbit);
            return false;
        }

        istr >> mins;

        m_minutes = hours * 60 + mins;
        return true;
    }
    // overloads the cast to unsigned int for the Time class
    Time::operator unsigned int() const {
        // if it is an unsigned int, return num of minutes
        if (m_minutes >= 0) {
            return m_minutes;
        }
        return 0;
    }
    // overloads the multiplication assignment *= for the Time class
    Time& Time::operator*=(int val) {
        m_minutes *= val;
        return *this;
    }
    // overloads the subtraction assignment -= for the Time class
    Time& Time::operator-=(const Time& D) {
        // adds 24 hours to the minutes if current time is smaller
        if (m_minutes < D.m_minutes) {
            m_minutes += 1440;
        }
        m_minutes -= D.m_minutes;
        return *this;
    }
    // same as -=, except that it does not have a side effect
    Time Time::operator-(const Time& T) const {
        // creates new object for time diff
        Time newTime;
        newTime.m_minutes = m_minutes;
        // adds 24 hours to the minutes if current time is smaller
        if (newTime.m_minutes < T.m_minutes) {
            newTime.m_minutes += 1440;
        }
        newTime.m_minutes -= T.m_minutes;
        return newTime;
    }
    // overload the insertion operator to insert a Time object into an ostream
    std::ostream& operator<<(std::ostream& ostr, const Time& time) {
        time.write(ostr);
        return ostr;
    }
    // overload the extraction operator to extract data from an istream object into the Time object
    std::istream& operator>>(std::istream& istr, Time& time) {
        time.read(istr);
        return istr;
    }
}
