#include "patient.h"
using namespace std;


// Parameterized constructor: Initializes a Patient object with specific values
Patient::Patient(string fName, string lName, long id, long doctorID,string birth, string blood, string diag,string admission, string discharge) {
    firstName = fName;          // Initialize first name
    lastName = lName;           // Initialize last name
    patientID = id;             // Assign patient ID
    assignedDoctor = doctorID;  // Assign doctor ID
    dateOfBirth = birth;                // Set date of birth
    bloodType = blood;          // Set blood type
    diagnosis = diag;           // Set diagnosis
    admissionDate = admission;  // Set admission date
    dischargeDate = discharge;  // Set discharge date
}

// Prints the patient’s information in a formatted manner
void Patient::Print_Patient_Info() {
    cout << "Patient ID: " << patientID
              << "\nName: " << firstName << " " << lastName
              << "\nDate of Birth: " << dateOfBirth
              << "\nBlood Type: " << bloodType
              << "\nDiagnosis: " << diagnosis
              << "\nAdmission Date: " << admissionDate
              << "\nDischarge Date: " << dischargeDate << "\n";
}

// Determines the patient’s status based on the diagnosis string
string Patient::Patient_Status() {
    if (diagnosis.find("Critical") != string::npos)
        return "Critical"; // If "Critical" is found
    if (diagnosis.find("Moderate") != string::npos)
        return "Moderate"; // If "Moderate" is found
    return "Stable"; // Default to "Stable" status
}

// Getter for assigned doctor ID
long Patient::getAssignedDoctor() {

    return assignedDoctor;
}

// Getter for patient ID
long Patient::getPatientID() {
    return patientID;
}

// Getter for date of birth
string Patient::getDOB() {
    return dateOfBirth;
}

// Getter for diagnosis
string Patient::getDiagnosis() {
    return diagnosis;
}

// Setter to update the diagnosis field
void Patient::setDiagnosis(string diag) {
diagnosis = diag; }
