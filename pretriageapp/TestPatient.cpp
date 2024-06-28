/*
* Kenny Kwok
* kkwok21@nyseneca.ca
* 130049232
* 01/04/2024
Citation and Sources...
Final Project Milestone 4
Module: TestPatient.cpp
Filename: TestPatient.cpp
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

#include "TestPatient.h"

using namespace std;
namespace seneca {

    int TestPatient::nextTestTicket = 1; // initialized to one

    // passes the nextTestTicket global variable to the constructor of the base class Patient   
    TestPatient::TestPatient() : Patient(nextTestTicket) {
        // increase the value of nextTestTicket global variable by one
        nextTestTicket++;
    }

    // only returns the character 'C'
    char TestPatient::type() const {
        return 'C';
    }

    // write virtual function override
    std::ostream& TestPatient::write(std::ostream& os) const {
        // if the ostream is cout
        if (&os == &cout) {
            os << "Contagion TEST" << endl;
        }
        Patient::write(os); // call the write() function of the base class Patient
        return os;
    }

    // read virtual function override
    std::istream& TestPatient::read(std::istream& is) {
        Patient::read(is); // call the read function of the base class Patient
        // if the istream is not cin
        if (&is != &cin) {
            // set the nextTestTicket to the ticket number of this patient + 1
            nextTestTicket = number() + 1;
        }
        return is;
    }

}