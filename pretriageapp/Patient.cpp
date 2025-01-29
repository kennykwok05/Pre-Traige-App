#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include <cstring>
#include <iomanip> 

using namespace std;

// manage patient records in a healthcare pre-triage system by storing, validating, and processing patient information efficiently
namespace seneca {

    // constructor
    Patient::Patient(int ticketNumber) : m_ticket(ticketNumber) {
        m_name = nullptr;
        m_ohip = 0;
    }

    // copy constructor
    Patient::Patient(const Patient& other) : m_ticket(other.m_ticket) {
        m_name = new char[strlen(other.m_name) + 1];
        strcpy(m_name, other.m_name);
        m_ohip = other.m_ohip;
    }

    // assignment operator
    Patient& Patient::operator=(const Patient& other) {
        if (this != &other) { // self assignment check
            delete[] m_name;
            m_name = new char[strlen(other.m_name) + 1];
            strcpy(m_name, other.m_name);
            m_ohip = other.m_ohip;
            m_ticket = other.m_ticket;
        }
        return *this;
    }

    // destructor
    Patient::~Patient() {
        delete[] m_name;
    }

    // to compare with a single character
    bool Patient::operator==(char otherType) const {
        if (type() == otherType) {
            return true;
        }
        return false;
    }

    // to compare with another patient
    bool Patient::operator==(const Patient& other) const {
        if (type() == other.type()) {
            return true;
        }
        return false;
    }

    // sets the time of the patient's ticket to the current time
    void Patient::setArrivalTime() {
        m_ticket.resetTime();
    }

    // retrieve the time of the patient's ticket and return it
    Time Patient::time() const {
        return m_ticket.time();
    }

    // returns the number associated with the patient's ticket
    int Patient::number() const {
        return m_ticket.number(); // Return ticket number
    }

    // boolean cast, return true if the Patient is in a valid state
    Patient::operator bool() const {
        if (m_name != nullptr) {
            return true;
        }
        return false;
    }

    // const char pointer cast, return the address of the patient's name
    Patient::operator const char* () const {
        return m_name;
    }

    // writing patient info into ostream
    std::ostream& Patient::write(std::ostream& ostr) const {
        // if patient is in invalid empty state
        if (!m_name) {
            ostr << "Invalid Patient Record" << endl;
        }
        else {
            // format for clog
            if (&ostr == &clog) {
                ostr << setw(53) << left << setfill('.') << m_name << m_ohip << setw(5)
                    << right << setfill(' ') << m_ticket.number() << " " << m_ticket.time();
            }
            // format for cout
            else if (&ostr == &cout) {
                ostr << m_ticket << "\n";
                ostr << m_name << ", OHIP: " << m_ohip << "\n";
                return ostr;
            }
            // comma-separated format
            else {
                ostr << type() << "," << m_name << "," << m_ohip << ",";
                m_ticket.write(ostr); // insert ticket information
            }
        }
        return ostr;
    }

    // reading patient info into istream
    std::istream& Patient::read(std::istream& istr) {
        if (&istr == &cin) {
            char local[51];
            int local1 = 0;
            bool flag = true;

            cout << "Name: ";
            istr.get(local, 51); // read name up to 50 characters or newline
            istr.ignore(10000, '\n');

            delete[] m_name;
            m_name = new char[strlen(local) + 1];
            strcpy(m_name, local); // copy the extracted name

            cout << "OHIP: ";
            // keep asking for OHIP if input is invalid
            while (flag == true) {
                if (!(istr >> local1)) {
                    cout << "Bad integer value, try again: ";
                    istr.clear();
                    istr.ignore(10000, '\n');
                }
                else if (local1 < 100000000 || local1 > 999999999) {
                    cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
                    istr.ignore(10000, '\n');
                }
                else {
                    istr.ignore(10000, '\n');
                    flag = false;
                }

            }
            m_ohip = local1;
        }
        else {
            delete[] m_name;
            char local[51];
            istr.get(local, 51, ','); // Read name up to comma
            istr.ignore(10000, ',');
            m_name = new char[strlen(local) + 1];
            strcpy(m_name, local); // copy the extracted name
            istr >> m_ohip; // reads the OHIP
            istr.ignore(10000, ',');
            m_ticket.read(istr); // read method of the patient's ticket
        }
        return istr;
    }

}