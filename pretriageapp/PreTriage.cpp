/*
* Kenny Kwok
* kkwok21@nyseneca.ca
* 130049232
* 08/04/2024
Citation and Sources...
Final Project Milestone 5
Module: PreTriage.cpp
Filename: PreTriage.cpp
Version 1.0
Author   Kenny Kwok
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
#include "PreTriage.h"
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Menu.h"
#include "TriagePatient.h"
#include "TestPatient.h"
#include <cstring>


using namespace std;
namespace seneca {

    // constructor
    PreTriage::PreTriage(const char* dataFilename) {
        m_nLineup = 0;
        strcpy(m_dataFilename, dataFilename); // for load and save purposes
        m_avgWaitC = Time(15);
        m_avgWaitT = Time(5);
        load(); // loads all the data from the data file
    }

    // destructor
    PreTriage::~PreTriage() {
        int i = 0;
        save(); // saves the data
        // iterates through the patient lineup and deletes the elements one by one.
        for (i = 0; i < m_nLineup; i++) {
            delete m_lineup[i]; 
            m_lineup[i] = nullptr;
        }
    }

    // returns the total estimated wait time for that type of Patient
    Time PreTriage::getWaitTime(const Patient& p) const {
        int i = 0;
        int nPatients = 0;
        int estWaitTime = 0;
        // find the number of Patients in the lineup that match the type of the received Patient Reference
        for (i = 0; i < m_nLineup; i++) {
            if (m_lineup[i]->type() == p.type()) {
                nPatients++;
            }
        }
        // returns the product of estimated wait time to the number of patients found
        for (i = 0; i < nPatients; i++) {
            if (p.type() == 'C') { // contagion test
                estWaitTime += m_avgWaitC;
            }
            else if (p.type() == 'T') // triage
            {
                estWaitTime += m_avgWaitT;
            }
        }
        return estWaitTime;
    }

    // adjusts the average wait time based on the admittance time
    void PreTriage::setAverageWaitTime(const Patient& p) {
        Time CT, PTT;
        int pTN = 0;
        CT.reset();
        PTT = p.time(); // time of the ticket
        pTN = p.number(); // number of the ticket
        // formula: AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN
        if (p.type() == 'C') { // contagion test
            m_avgWaitC = ((CT - PTT) + (m_avgWaitC * (pTN - 1))) / pTN;
        }
        else if (p.type() == 'T') { // triage
            m_avgWaitT = ((CT - PTT) + (m_avgWaitT * (pTN - 1))) / pTN;
        }
    }

    // finds the index of the first patient in line that matches a specified type
    int PreTriage::indexOfFirstInLine(char type) const {
        int i = 0;
        // loop to find the match
        for (i = 0; i < m_nLineup; i++) {
            if (m_lineup[i]->type() == type) { // returns the found index if match is found
                return i;
            }
        }
        return -1;
    }

    // Loads the average wait times and the patient records
    void PreTriage::load() {
        int i = 0;
        cout << "Loading data..." << endl;
        ifstream file(m_dataFilename);
        // checks the file data
        if (!file.is_open()) {
            cout << "No data or bad data file!" << endl << endl;
            return;
        }
        
        file >> m_avgWaitC;
        file.ignore(2000, ',');
        file >> m_avgWaitT;
        file.ignore(2000, '\n');

        Patient* patient = nullptr; // local patient pointer
        for (i = 0; i < maxPatient; i++) { 
           // read the first character and ignore the comma
            char firstChar = ' ';
            file >> firstChar;
            file.ignore(2000, ',');

            if (file.eof()) {
                break;
            }
            if (firstChar == 'C') { // contagion
                patient = new TestPatient; // instantiate a Contagion Test Patient
            }
            else if (firstChar == 'T') { // triage
                patient = new TriagePatient; // instantiate a Triage Patient
            }
            if (patient) { // if instantiation successful
                file >> *patient; // read the patient information from the file
                m_lineup[m_nLineup++] = patient; // add the local pointer value to the patient lineup array
            }
        }

        if (!file.eof()) { // if there are still records left in the file
            cout << "Warning: number of records exceeded " << maxPatient << endl;
        }
        if (m_nLineup <= 0) { // if no records were read
            cout << "No data or bad data file!" << endl << endl;
        }
        else { 
            cout << m_nLineup << " Records imported..." << endl << endl;
        }
        file.close();
    }

    // insert wait times into data file
    void PreTriage::save() {
        int i = 0;
        int cSaved = 0, tSaved = 0;
        cout << "Saving lineup..." << endl;
        ofstream file(m_dataFilename); // opens the data file for output.
        if (!file) {
            cout << "Error: cannot write file!" << endl;
            return;
        }
        
        file << m_avgWaitC << "," << m_avgWaitT << endl; //inserts the average Contagion Test and Triage wait times
        // iterates through the lineup array of Patient pointers
        for (i = 0; i < m_nLineup; i++) {
            file << *m_lineup[i] << endl; // inserts them into the data file
            if (m_lineup[i]->type() == 'C') {
                cSaved++;
            }
            else if (m_lineup[i]->type() == 'T') {
                tSaved++;
            }
        }
        // inserts the number of records saved for each type of patient
        cout << cSaved << " Contagion Tests and " << tSaved << " Triage records were saved!" << endl;
        file.close();
    }

    // registers a new patient
    void PreTriage::reg() {
        int choice = 0;
        if (m_nLineup >= maxPatient) {
            cout << "Line up full!" << endl;
            return;
        }
        // display sub-menu for patient type selection
        Menu reg("Select Type of Registration:\n1- Contagion Test\n2- Triage", 1);
        reg >> choice;


        switch (choice) {
        case 0:
            // Terminate the function
            return;
        case 1: 
            // Instantiate a Contagion Test Patient
            m_lineup[m_nLineup] = new TestPatient();
            break;
        case 2: 
            // Instantiate a Triage Patient
            m_lineup[m_nLineup] = new TriagePatient();
            break;
        default:
            cout << "Invalid!" << endl;
            return;
        }

        m_lineup[m_nLineup]->setArrivalTime(); // set the patient's arrival time
        // output details
        cout << "Please enter patient information: " << endl;
        cin >> *m_lineup[m_nLineup];
        cout << endl;
        cout << "******************************************" << endl;
        cout << *m_lineup[m_nLineup];
        cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_nLineup]) << endl;
        cout << "******************************************" << endl << endl;
        m_nLineup++; // increase the lineup size
    }

    // calls the next patient in line to be admitted
    void PreTriage::admit() {
        int idx = 0;
        int choice = 0;
        // display the sub-menu 
        Menu adm("Select Type of Admittance:\n1- Contagion Test\n2- Triage", 1);
        adm >> choice;
        char type = ' ';
        Time time;

        switch (choice) {
        case 0: 
            return; // terminate if 0
        case 1: 
            type = 'C';
            break;
        case 2: 
            type = 'T';
            break;
        default:
            cout << "Invalid!" << endl;
            return;
        }

        idx = indexOfFirstInLine(type); // find the index of the next patient in the line for the type
        if (idx == -1) { // if no patient is found
            cout << "Lineup is empty!" << endl;
            return;
        }

        // output details
        cout << endl << "******************************************" << endl;
        cout << "Call time: [" << time.reset() << "]" << endl;
        cout << "Calling at for " << *m_lineup[idx];
        cout << "******************************************" << endl << endl;

        setAverageWaitTime(*m_lineup[idx]); // set the average wait time for the patient
        removeDynamicElement(m_lineup, idx, m_nLineup); // remove the patient from the lineup 

    }

    // prints a report on patients currently in the lineup
    void PreTriage::lineup() {
        int choice = 0, idx = 1, i = 0;
        // display a sub-menu
        Menu lineup("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);
        lineup >> choice;
        // header
        cout << "Row - Patient name                                          OHIP     Tk #  Time" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;

        switch (choice) {
        case 0:
            return;
        case 1:
            for (i = 0; i < m_nLineup; i++) {
                if (m_lineup[i]->type() == 'C') { // contagion 
                    clog << idx << "   - " << *m_lineup[i] << endl; // insert only the type of patents
                    idx++;
                }
            }
            break;
        case 2:
            for (i = 0; i < m_nLineup; i++) {
                if (m_lineup[i]->type() == 'T') { // triage
                    clog << idx << "   - " << *m_lineup[i] << endl; // insert only the type of patents
                    idx++;
                }
            }
            break;
        default:
            cout << "Invalid!" << endl;
            break;
        }

        cout << "-------------------------------------------------------------------------------" << endl;

    }
    // runs the PreTriage main application
    void PreTriage::run() {
        int option = 0;
        // display the menu
        Menu main("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup", 0);

        do {
            main >> option; // gets the selection

            switch (option) {
            case 0:
                return; // quit
            case 1:
                reg(); // register method
                break;
            case 2:
                admit(); // admit method
                break;
            case 3:
                lineup(); // lineup method
                break;
            default:
                cout << "Invalid!" << endl;
                break;
            }
        } while (option != 0);
    }
   
}