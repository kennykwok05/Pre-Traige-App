#include "TestPatient.h"

using namespace std;

// manages TestPatient details, including assigning test tickets and customizing input/output
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