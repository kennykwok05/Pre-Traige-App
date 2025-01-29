#include <iostream>
#include "Ticket.h"
using namespace std;

//  manage and display ticket information with unique numbers and timestamps
namespace seneca {
    // Constructs a Ticket by setting the m_number member variable
    Ticket::Ticket(int number) {
        m_number = number;
    }
    // returns the time when the ticket was issued
    Time Ticket::time() const
    {
        return m_time;
    }
    // A query returning the number of the ticket
    int Ticket::number() const {
        return m_number;
    }
    // Sets the Ticket time to the current time
    void Ticket::resetTime() {
        m_time.reset();
    }
    // Inserts a ticket into the ostream to be displayed
    std::ostream& Ticket::write(std::ostream& ostr) const {
        if (&ostr != &cout) {
            ostr << m_number << "," << m_time;
        }
        else {
            ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
        }
        return  ostr;
    }
    // Extracts the ticket number and time from istream
    std::istream& Ticket::read(std::istream& istr) {
        istr >> m_number;
        istr.ignore();
        return istr >> m_time;
    }
}