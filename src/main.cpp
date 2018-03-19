#include <iostream>
#include "Database.h"

using namespace std;
using namespace SCTMIC012;

// Prints user instructions
void printOptions()
{
    cout << "\nDatabase Interface, Done by: Michael Scott\n" << endl;

    cout << "OPTIONS:\n" << endl;

    cout << "0. Add Student." << endl;
    cout << "1. Read Existing Database." << endl;
    cout << "2. Save Textfile as Database." << endl;
    cout << "3. Save Database as Textfile." << endl;
    cout << "4. Display Student Data for a Given Student." << endl;
    cout << "5. Grade Student." << endl;

    cout << "c. Clear Terminal Window" << endl;
    cout << "q. Quit.\n" << endl;

    cout << "Enter a number (or q to quit) and press return...\n" << endl;
}

// Gives user a chance to read output
void wait()
{
    cout << "Press enter return twice to continue...";
    string enter = " ";
    cin.ignore();
    getline(cin,enter);
}

int main()
{
    printOptions();

    char option;
    Database d1;

    // Allows users to select options 0 to 5, until they push q.
    for(;;)
    {
        cin >> option;

        switch(option)
        {
            // Add student
            case '0':
            {
                //Used to flush stream, avoids previous options causing database errors
                cin.ignore();

                string studentNumber;
                string name;
                string surname;
                string classRecord;

                cout << "Enter student number: ";
                getline(cin,studentNumber);
                cout <<"Enter name: ";
                getline(cin,name);
                cout << "Enter surname: ";
                getline(cin,surname);
                cout << "Enter class record: ";
                getline(cin,classRecord);

                d1.addStudent(studentNumber,name,surname,classRecord);

                wait();
                break;
            }
            // Display database
            case '1':
            {
                d1.readDatabase();

                wait();
                break;
            }
            // Read in textfile into memory
            case '2':
            {
                string filename;
                cout << "Enter a filename from which the database will extract values (NB do not forget the .txt extension): ";
                cin >> filename;

                cout << d1.saveTextfileToDatabase(filename) << endl;

                wait();
                break;
            }
            // Output memory to textfile
            case '3':
            {
                string filename;
                cout << "Enter a filename to save the database to (NB do not forget the .txt extension): ";
                cin >> filename;

                cout << d1.saveDatabaseToTextfile(filename) << endl;

                wait();
                break;
            }
            // Display student information
            case '4':
            {
                string studentNumber;

                cout << "Enter student number: ";
                cin >> studentNumber;

                cout << d1.displayStudent(studentNumber) << endl;

                wait();
                break;
            }
            // Grade student
            case '5':
            {
                string studentNumber;

                cout << "Enter student number: ";
                cin >> studentNumber;

                cout << d1.gradeStudent(studentNumber) << endl;

                wait();
                break;
            }
            case 'c':
            {
                break;
            }
            // Quit
            case 'q':
            {
                return 0;
            }
            // Command not recognised
            default:
            {
                wait();
                cout << "Command not recognised." << endl;
            }
        }
        printOptions();
    }
}