/*
* Kenny Kwok
* kkwok21@nyseneca.ca
* 130049232
* 01/04/2024
Citation and Sources...
Final Project Milestone 4
Module: TestPatient.h
Filename: TestPatient.h
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

#ifndef SENECA_TESTPATIENT_H_
#define SENECA_TESTPATIENT_H_

#include "Patient.h"

namespace seneca {

    class TestPatient : public Patient {
        static int nextTestTicket; // to determine what is the ticket number of the next contagion test Patient
    public:
        TestPatient(); // default constructor
        virtual char type() const; // type() virtual function
        virtual std::ostream& write(std::ostream& os) const override; // write virtual function override
        virtual std::istream& read(std::istream& is) override; // read virtual function override
        ~TestPatient() = default; // destructor
    };

}
#endif // !SENECA_TESTPATIENT_H_