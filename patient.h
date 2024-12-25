#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>
using namespace std;

// Class representing a Patient in the hospital system
class Patient {
private:
    // Private attributes for patient details
    string firstName, lastName;          // Patient's first and last name
    string dateOfBirth;                          // Date of birth (YYYYMMDD)
    string bloodType;                    // Blood type of the patient
    string diagnosis;                    // Patient's diagnosis or condition
    string admissionDate, dischargeDate; // Admission and discharge dates
    long patientID;                           // Unique patient ID
    long assignedDoctor;                      // Assigned doctor ID

public:
    // Default constructor
    Patient();

    // Parameterized constructor to initialize patient details
    Patient(string fName, string lName, long id, long doctorID,
            string birth, string blood, string diag,
            string admission, string discharge);

    // Prints all patient information
    void Print_Patient_Info();

    // Determines and returns the patient's status based on diagnosis
    string Patient_Status();

    // Setters and getters
    void setDiagnosis(string diag); // Set patient's diagnosis
    long getAssignedDoctor();            // Get assigned doctor ID
    long getPatientID();                 // Get patient ID
    string getDOB();                // Get date of birth
    string getDiagnosis();          // Get diagnosis
};

#endif // PATIENT_H
