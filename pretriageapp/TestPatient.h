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