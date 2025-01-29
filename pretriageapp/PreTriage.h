#ifndef SENECA_PRETRIAGE_H_
#define SENECA_PRETRIAGE_H_

#include "Patient.h"
#include "Time.h"

namespace seneca {

    const int maxPatient = 100; // maximum number of patients in the lineup
    
    class PreTriage {
        // private member variables
        Time m_avgWaitC, m_avgWaitT; // keep track of the average wait time (contagigen & triage)
        Patient* m_lineup[maxPatient]; // array of pointers to Patient objects
        char m_dataFilename[100]; // hold the path and name of the data file
        int m_nLineup; // hold the actual number of patients in the lineup
        // private methods
        Time getWaitTime(const Patient& p) const; // returns the total estimated wait time for that type of Patient
        void setAverageWaitTime(const Patient& p); // adjusts the average wait time based on the admittance time
        int indexOfFirstInLine(char type) const; // finds the index of the first patient in line that matches a specified type
        void load(); // Loads the average wait times and the patient records
        void save(); // insert wait times into data file
        void reg(); // registers a new patient
        void admit(); // calls the next patient in line to be admitted
        void lineup(); // prints a report on patients currently in the lineup
    public:
        PreTriage(const char* dataFilename); // constructor
        ~PreTriage(); // destructor
        void run(); // runs the PreTriage main application
    };
}

#endif // !SENECA_PRETRIAGE_H_