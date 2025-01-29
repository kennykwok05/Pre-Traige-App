#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include <cstring>

using namespace std;
// Handles triage patient details, including symptoms, ticket management, and customized input/output formatting.
namespace seneca {

    int TriagePatient::nextTriageTicket = 1; // initialized to one

    // passes the nextTriageTicket global variable to the constructor of the base class Patient
    TriagePatient::TriagePatient() : Patient(nextTriageTicket){
        m_symptoms = nullptr; // initializes the character pointer member variable to null
        nextTriageTicket++; // increases the value of nextTriageTicket by one
    }

    // returns the character 'T'
    char TriagePatient::type() const {
        return 'T';
    }

    // inserts the patient information into different instances of ostream
    std::ostream& TriagePatient::write(std::ostream& os) const {
        // if the ostream reference is cout
        if (&os == &cout) {
            os << "TRIAGE" << endl; // prints a "TRIAGE" label
        }
        Patient::write(os); // inserts the patient
        // displays the symptoms
        if (&os == &cout) {
            os << "Symptoms: " << m_symptoms << endl; 
        }
        // comma-separated format
        else if (&os != &clog){
            os << ',' << m_symptoms;
        }
        return os;
    }

    // extracts patient information from different instances of istream
    std::istream& TriagePatient::read(std::istream& is) {
        delete[] m_symptoms; // deletes the memory pointed to by the symptoms member variable
        Patient::read(is); // calls the Read function of the base class Patient
        // if the istream reference is not cin
        if (&is != &cin) {
            char comma;
            is >> comma; // ignores the comma character
            char local[512];
            is.getline(local, 512, '\n'); // reads the symptoms
            m_symptoms = new char[strlen(local) + 1]; // dynamic allocation
            strcpy(m_symptoms, local); // copies to allocated memory
            nextTriageTicket = number() + 1; // return value of the number() plus one
        }
        else {
            std::cout << "Symptoms: ";
            char local[512];
            is.getline(local, 512); // reads the symptoms
            m_symptoms = new char[strlen(local) + 1]; // dynamic allocation
            strcpy(m_symptoms, local); // copies to allocated memory
        }
        return is;
    }

    // deletes the memory pointed by the symptoms member variable
    TriagePatient::~TriagePatient() {
        delete[] m_symptoms;
    }

}