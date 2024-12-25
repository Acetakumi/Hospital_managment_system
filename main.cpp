#include "hospital.h"
#include <iostream>
#include <iomanip>   // For formatting output (setw)
#include <limits>    // For input validation
#include <string>    // For handling string input
#include <exception> // For exception handling

using namespace std;

// Function to display the main menu header
void displayMenuHeader() {
    cout << "\n===========================================\n";
    cout << "          HOSPITAL MANAGEMENT SYSTEM       \n";
    cout << "===========================================\n";
}

// Function to display a section header for specific operations
void displaySectionHeader(string title) {
    cout << "\n-------------------------------------------\n";
    cout << "            " << title << "\n";
    cout << "-------------------------------------------\n";
}

int main() {
    Hospital* hospital = nullptr; // Pointer to the Hospital object for exception safety

    try {
        // Initialize Hospital object and load data from files
        hospital = new Hospital();
    } catch (const exception& e) {
        cerr << "Error: Failed to initialize Hospital system. " << e.what() << "\n";
        return 1; // Exit the program if initialization fails
    }

    int choice;          // Menu option selected by the user
    long id_input;       // Input for patient or doctor ID
    string specialty;    // Input for specialty name

    // Menu loop
    do {
        try {
            // Display the main menu
            displayMenuHeader();
            cout << setw(5) << "1." << " Find the oldest patient\n";
            cout << setw(5) << "2." << " Report the number of critical patients\n";
            cout << setw(5) << "3." << " Show patient data by ID\n";
            cout << setw(5) << "4." << " Show doctor data by ID\n";
            cout << setw(5) << "5." << " Show the assigned doctor for a patient\n";
            cout << setw(5) << "6." << " Show assigned patients for a doctor\n";
            cout << setw(5) << "7." << " Exit\n";
            cout << "-------------------------------------------\n";
            cout << "Enter your choice [1-7]: ";
            cin >> choice;

            // Input validation for menu choice
            if (cin.fail()) {
                cin.clear(); // Clear the input stream error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                throw invalid_argument("Invalid option! Please enter a number between 1 and 7.");
            }

            // Handle user choice
            switch (choice) {
                case 1:
                    displaySectionHeader("FINDING THE OLDEST PATIENT");
                    hospital->Find_Oldest_Patient();
                    break;

                case 2:
                    displaySectionHeader("NUMBER OF CRITICAL PATIENTS");
                    cout << "Total Critical Patients: " << hospital->Count_Critical_Patients() << "\n";
                    break;

                case 3:
                    displaySectionHeader("SHOW PATIENT DATA BY ID");
                    cout << "Enter Patient ID: ";
                    cin >> id_input;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid ID format! Please enter a numeric ID.");
                    }

                    hospital->Show_Patient_by_ID(id_input);
                    break;

                case 4:
                    displaySectionHeader("SHOW DOCTOR DATA BY ID");
                    cout << "Enter Doctor ID: ";
                    cin >> id_input;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid ID format! Please enter a numeric ID.");
                    }

                    hospital->Show_Doctor_by_ID(id_input);
                    break;

                case 5:
                    displaySectionHeader("SHOW ASSIGNED DOCTOR FOR PATIENT");
                    cout << "Enter Patient ID: ";
                    cin >> id_input;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid ID format! Please enter a numeric ID.");
                    }

                    hospital->Show_assigned_doctor(id_input);
                    break;

                case 6:
                    displaySectionHeader("SHOW ASSIGNED PATIENTS FOR DOCTOR");
                    cout << "Enter Doctor ID: ";
                    cin >> id_input;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid ID format! Please enter a numeric ID.");
                    }

                    hospital->Show_Assigned_Patients(id_input);
                    break;

                case 7:
                    displaySectionHeader("EXITING THE PROGRAM");
                    cout << "Thank you for using the Hospital Management System. Goodbye!\n";
                    break;

                default:
                    throw out_of_range("Invalid option! Please choose a number between 1 and 7.");
            }
        } catch ( invalid_argument& e) {
            cerr << "\nError: " << e.what() << "\n";
        } catch ( out_of_range& e) {
            cerr << "\nError: " << e.what() << "\n";
        } catch ( exception& e) {
            cerr << "\nAn unexpected error occurred: " << e.what() << "\n";
        }

    } while (choice != 7);

    // Clean up dynamically allocated memory
    delete hospital;
    return 0;
}
