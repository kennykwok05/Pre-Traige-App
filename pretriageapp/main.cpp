#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "Utils.h"
using namespace std;
using namespace seneca;

// runs the PreTriage application using test data and displays the updated file.

// Copies the contents of the source file to the destination file
void copyFile(const char* des, const char* src) {
    ifstream infile(src);
    ofstream outfile(des);
    // Ensure the output file is open before proceeding
    if (outfile) { 
        char ch;
        while (infile.get(ch)) {
            outfile.put(ch); // Write to the destination file
        }
    }
}
// Displays the content of a given file
void displayFile(const char* fname) {
    ifstream fin(fname);
    char ch;
    cout << endl << "******  Content of file: \"" << fname << "\":" << endl;
    while (fin.get(ch)) cout << ch; // Print file contents to the console
    cout << "***************************************************" << endl << endl;
}
// Runs the PreTriage application with a predefined data file
void theApp() {
    PreTriage P("smalldata.csv");
    P.run();
}
int main() {
    // Copy backup file to the working file to ensure fresh test data
    copyFile("smalldata.csv", "smalldata.csv.bak");
    seneca::debug = true;
    U.setDebugTime(8, 41); // Set a fixed debug time for testing consistency
    theApp(); // Run the application
    displayFile("smalldata.csv"); // Show the updated data file after execution
    return 0;
}

