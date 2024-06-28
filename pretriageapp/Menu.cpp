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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include "Utils.h"
#include "Menu.h"


using namespace std;

namespace seneca {
    // initialize a Menu object
    Menu::Menu(const char* menuContent, int numberOfTabs) {
        // set to empty state
        m_text = nullptr;
        m_numOptions = 0;
        // if not provided, no tabs will be applied by default.
        if (numberOfTabs < 0) {
            m_numTabs = 0;
        }
        else {
            m_numTabs = numberOfTabs;
        }
        // dynamically allocates memory to store the content
        m_text = new char[strlen(menuContent) + 1]; // Allocate memory
        strcpy(m_text, menuContent); 
        // scans m_text to count the number of newline characters (\n)
        for (const char* option = m_text; *option != '\0'; option++) {
            if (*option == '\n') {
                m_numOptions++;
            }
        }
    }

    // deallocates the dynamically allocated memory
    Menu::~Menu() {
        delete[] m_text;
    }

    // presenting the Menu content to the user
    void Menu::display() const {
        int i = 0;
        // make a copy of m_text for tokenization
        char* copy = new char[strlen(m_text) + 1];
        strcpy(copy, m_text);
        char* token = strtok(copy, "\n"); 
        // give indentation for all the contents
        while (token != nullptr) {
            for (i = 0; i < m_numTabs; i++) {
                cout << "   ";
            }
            cout << token << endl;
            token = strtok(nullptr, "\n");
        }
        // give indentation for the exit line
        for (i = 0; i < m_numTabs; i++) {
            cout << "   ";
        }
        cout << "0- Exit\n";
        for (i = 0; i < m_numTabs; i++) {
            cout << "   ";
        }
        cout << "> ";
        // free the copy var
        delete[] copy;
    }

    // insertion operator first calls the display function and then receives the user's selection as an integer value
    int& Menu::operator>>(int& Selection) {
        size_t i = 0;    
        string input;
        bool validInput = false;
        bool validInt = true;
        bool space = true;

        // display all the menu content
        display();
    
        while (!validInput) {
            getline(cin, input);
            // checks if input is an integer and does not have space
            validInt = true;
            for (i = 0; i < input.length() && validInt; i++) {
                if (i == 0 && input[i] == '-') {
                    continue;
                }
                if (!isdigit(input[i])) {
                    validInt = false;
                }
                if (isspace(input[i])) {
                    space = false;
                }
            }

            if (validInt) {
                // Convert string to integer if input is valid
                Selection = stoi(input);

                if (Selection >= 0 && Selection <= m_numOptions) {
                    validInput = true;
                }
                // error if integer is out of range
                else {
                    cout << "Invalid value enterd, retry[0 <= value <= " << m_numOptions << "]: ";
                }
            }
            // error if whitespace is found
            else if (space == false) {
                cout << "Only enter an integer, try again: ";
                space = true;
            }
            // error if input is a string
            else {
                cout << "Bad integer value, try again: ";
            }
        }
        return Selection;
    }

}