/*
* Kenny Kwok
* kkwok21@nyseneca.ca
* 130049232
* 01/04/2024
Citation and Sources...
Final Project Milestone 4
Module: TriagePatient.h
Filename: TriagePatient.h
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

#ifndef SENECA_TRIAGEPATIENT_H_
#define SENECA_TRIAGEPATIENT_H_

#include "Patient.h"

namespace seneca {

    class TriagePatient : public Patient {
        static int nextTriageTicket; // determines the ticket number of the next triage Patient
        char* m_symptoms; // dynamically hold the symptoms of the arriving patient
    public:
        TriagePatient(); // default consturctor
        virtual char type() const; // type() virtual function
        virtual std::ostream& write(std::ostream& os) const override; // write virtual function override
        virtual std::istream& read(std::istream& is) override; // read virtual function override
        ~TriagePatient(); // destructor
    };


}
#endif // !SENECA_TRIAGEPATIENT_H_