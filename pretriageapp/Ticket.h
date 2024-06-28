/*
* Kenny Kwok
* kkwok21@nyseneca.ca
* 130049232
* 30/03/2024
Citation and Sources...
Final Project Milestone 3
Module: Ticket.h
Filename: Ticket.h
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