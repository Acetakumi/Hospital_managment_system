#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "patient.h"  // Include Patient class
#include "doctors.h"  // Include Doctor class
#include <vector>     // For std::vector to store collections of patients and doctors
#include <string>     // For using std::string

// Class representing the Hospital, managing patients and doctors
class Hospital {
private:
     vector<Patient> *patients;  // Pointer to a vector storing Patient objects
    vector<Doctor> *doctors;    // Pointer to a vector storing Doctor objects

public:
    void extract_doctor_info();

     void extract_patient_info();

     // Constructor: Initializes the hospital by reading patient and doctor data from files
    Hospital();

    // Destructor: Frees dynamically allocated memory for patient and doctor vectors
    ~Hospital();

    // Finds and displays the oldest patient in the system
    void Find_Oldest_Patient();

    // Counts and returns the number of critical patients
    int Count_Critical_Patients();

    // Displays all doctors with the specified specialty
    void Doctors_By_Specialty(std::string specialty);

    // Displays patient data by their ID
    void Show_Patient_by_ID(long patient_id);

    // Displays doctor data by their ID
    void Show_Doctor_by_ID(long doctor_id);

    // Displays the doctor assigned to a given patient ID
    void Show_assigned_doctor(long patient_id);

    // Displays all patients assigned to a specific doctor ID
    void Show_Assigned_Patients(long doctor_id);
};

#endif // HOSPITAL_H
