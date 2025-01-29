#ifndef SENECA_TICKET_H_
#define SENECA_TICKET_H_
#include <iostream>
#include "Time.h"
#include "IOAble.h"
namespace seneca {
    class Ticket :public IOAble {
        Time m_time; // The time the Ticket was issued
        int m_number; // The ticket number; A sequential integer
    public:
        Ticket(int number); // Constructs a Ticket by setting the m_number member variable
        Time time()const; // returns the time when the ticket was issued
        int number()const; // A query returning the number of the ticket
        void resetTime(); // Sets the Ticket time to the current time
        std::ostream& write(std::ostream& ostr)const; // Inserts a ticket into the ostream to be displayed
        std::istream& read(std::istream& istr); // Extracts the ticket number and time from istream
    };
}
#endif // !SENECA_TICKET_H_