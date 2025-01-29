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