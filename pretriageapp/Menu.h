/*
* Kenny Kwok
* kkwok21@nyseneca.ca
* 130049232
* 05/03/2024
Citation and Sources...
Final Project Milestone 1
Module: Time.h
Filename: Time.h
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

#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_

namespace seneca {
    class Menu {
        char* m_text; // constant char pointer to hold the content of the menu to be displayed
        int m_numOptions; // integer to hold the number of options in the menu
        int m_numTabs; // integer to hold the number of indetation tabs
    public:
        Menu(const char* menuContent, int numberOfTabs = 0); // initialize a Menu object
        ~Menu(); // deallocates the dynamically allocated memory

        Menu(const Menu& other) = delete; // makes sure the Menu can not be copied or assigned to another Menu object
        Menu& operator=(const Menu& other) = delete; // copy assignment operator


        void display() const; // presenting the Menu content to the user
        int& operator>>(int& Selection); // insertion operator first calls the display function and then receives the user's selection as an integer value
    };

}
#endif // !SENECA_MENU_H_