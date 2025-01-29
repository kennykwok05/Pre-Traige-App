#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include "Utils.h"
#include "Menu.h"


using namespace std;
// Implements a menu system for a pre-triage healthcare application
namespace seneca {
    // initialize a Menu object
    Menu::Menu(const char* menuContent, int numberOfTabs) {
        // set to empty state
        m_text = nullptr;
        m_numOptions = 0;
        // Ensure the number of tabs is non-negative
        if (numberOfTabs < 0) {
            m_numTabs = 0;
        }
        else {
            m_numTabs = numberOfTabs;
        }
        // allocate memory for the menu content
        m_text = new char[strlen(menuContent) + 1]; // Allocate memory
        strcpy(m_text, menuContent); 
        // count the number of menu options based on newline characters
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

    // displays the menu with proper indentation
    void Menu::display() const {
        int i = 0;
        // make a copy of m_text for tokenization
        char* copy = new char[strlen(m_text) + 1];
        strcpy(copy, m_text);
        // Tokenize menu content and print each line
        char* token = strtok(copy, "\n"); 
        while (token != nullptr) {
            for (i = 0; i < m_numTabs; i++) {
                cout << "   ";
            }
            cout << token << endl;
            token = strtok(nullptr, "\n");
        }
        // print exit option with proper indentation
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

    // insertion operator Displays the menu and gets a valid user selection
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
                // ensure selection is within the valid range
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