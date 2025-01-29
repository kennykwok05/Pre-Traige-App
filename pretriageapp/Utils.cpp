#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Utils.h"
#include "Time.h"
using namespace std;
// provides utility functions for time handling and string comparison, with an optional debug mode for testing.
namespace seneca {
    // start provided code
    bool debug = false;
    Utils U;
    // Retrieves the current time in minutes
    int Utils::getTime() {
        int mins = -1;
        // Simulates time increments for debugging
        if (debug) {
            int duration[]{ 3,5,9,20,30 };
            mins = (m_testMins %= 1440);
            m_testMins += duration[m_testIndex++ % 5];
        }
        // Get actual system time in minutes
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    // Sets the debug mode and initializes a custom test time
    void Utils::setDebugTime(int hour, int min) {
        seneca::debug = true;
        m_testMins = hour * 60 + min;
    }
    // Custom string comparison function (returns difference of first mismatched character)
    int Utils::strcmp(const char* s1, const char* s2)const {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }
    // end provided code
}