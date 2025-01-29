#ifndef SENECA_PATIENT_H_
#define SENECA_PATIENT_H_

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

namespace seneca {

    class Patient : public IOAble {
        char* m_name;; // store the patient’s name
        int m_ohip; // to store the patient’s OHIP numbers.
        Ticket m_ticket; // represent the patient’s ticket for the lineup
    public:
        Patient(int ticketNumber); // constructor
        Patient(const Patient& other); // copy operator
        Patient& operator=(const Patient& other); // assignment operator
        ~Patient(); // destructor

        virtual char type() const = 0; // pure virtual function, returns a char, can't modify current object
        bool operator==(char otherType) const; // to compare with a single character
        bool operator==(const Patient& other) const; // to compare with another patient

        void setArrivalTime(); // sets the time of the patient's ticket to the current time
        Time time() const; // retrieve the time of the patient's ticket and return it
        int number() const; // returns the number associated with the patient's ticket

        explicit operator bool() const; // boolean cast, return true if the Patient is in a valid state
        operator const char* () const; // const char pointer cast, return the address of the patient's name

        std::ostream& write(std::ostream& ostr) const; // writing patient info into ostream
        std::istream& read(std::istream& istr); // reading patient info into istream
    };

}
#endif // !SENECA_PATIENT_H_
