#include "hospital.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <direct.h>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem; //

bool file_exists(string  filename) {
    fstream file(filename, ios::in); // Open file in input mode
    if (file) {
        file.close();
        return true; // File exists
    }
    return false; // File does not exist
}

void Hospital::extract_doctor_info() {
    // Reading doctors from file
    ifstream dfile(R"(C:\Users\aceta\CLionProjects\doctors\doctors.txt)");
    if (dfile.is_open()) {
        int num_of_doctors;  // Number of doctors in the file
        dfile >> num_of_doctors;
        dfile.ignore(); // Ignore the newline character after the number

        for (int i = 0; i < num_of_doctors; i++) {
            string fname, lname, specialty, doctor_id_str, years_str, base_salary_str, bonus_str;
            string line;
            getline(dfile, line);
            istringstream iss(line);

            getline(iss, fname, ',');
            getline(iss, lname, ',');
            getline(iss, doctor_id_str, ',');
            getline(iss, specialty, ',');
            getline(iss, years_str, ',');
            getline(iss, base_salary_str, ',');
            getline(iss, bonus_str, ',');

            Doctor d(fname, lname, stol(doctor_id_str), specialty, stoi(years_str),
                     stod(base_salary_str), stod(bonus_str));
            doctors->push_back(d);
        }
        dfile.close();
    }
}

void Hospital::extract_patient_info() {
    string patients_file;
    // Reading patients from file
    ifstream pfile(R"(C:\Users\aceta\CLionProjects\doctors\patient.txt)");
    if (pfile.is_open()) {
        int num_of_patients;  // Number of patients in the file
        pfile >> num_of_patients;
        pfile.ignore(); // Ignore the newline character after the number

        for (int i = 0; i < num_of_patients; i++) {
            string fname, lname, dob, blood_type, diagnosis, admission_date, discharge_date;
            string patient_id_str, assigned_doctor_str;
            string line;
            getline(pfile, line);
            istringstream iss(line);

            getline(iss, fname, ',');
            getline(iss, lname, ',');
            getline(iss, patient_id_str, ',');
            getline(iss, assigned_doctor_str, ',');
            getline(iss, dob, ',');
            getline(iss, blood_type, ',');
            getline(iss, diagnosis, ',');
            getline(iss, admission_date, ',');
            getline(iss, discharge_date, ',');

            Patient p(fname, lname, stol(patient_id_str), stol(assigned_doctor_str),
                      dob, blood_type, diagnosis, admission_date, discharge_date);
            patients->push_back(p);
        }
        pfile.close();
    } else {
        cerr << "Error: Could not open patients file at " << patients_file << endl;
    }
}

// Constructor: Initializes hospital data by reading from files
Hospital::Hospital() {
    string doctors_file;
    string patients_file;

    patients = new vector<Patient>();  // Allocate memory for patient list
    doctors = new vector<Doctor>();    // Allocate memory for doctor list

    // Buffer to store the current working directory
    const size_t size = 1024;
    char buffer[size];
    string current_path;

    // Get current working directory
    if (_getcwd(buffer, size) != NULL) {
        current_path = buffer;  // Convert buffer to std::string
        cout << "Current working directory: " << current_path << endl;
    } else {
        cout << "Error: Could not get current working directory." << endl;
        return;
    }

    // Check if files exist in current directory
    if (file_exists(current_path + "\\doctors.txt")) {
        doctors_file = current_path + "\\doctors.txt";
        patients_file = current_path + "\\patient.txt";
    } else {
        // Go to parent directory and look for files
        fs::path parent_path = fs::path(current_path).parent_path();
        cout << "Checking parent directory: " << parent_path << endl;

        if (file_exists(parent_path.string() + "\\doctors.txt")) {
            doctors_file = parent_path.string() + "\\doctors.txt";
            patients_file = parent_path.string() + "\\patient.txt";
        } else {
            cerr << "Error: Files not found in current or parent directories." << endl;
            return;
        }
    }

    extract_doctor_info();
    extract_patient_info();
}

// Destructor: Frees allocated memory for patients and doctors
Hospital::~Hospital() {
    delete patients;
    delete doctors;
}

// Finds and prints the oldest patient based on date of birth
void Hospital::Find_Oldest_Patient() {
    Patient oldest = (*patients)[0];  // Assume the first patient is the oldest
    for (int i = 1; i < patients->size(); i++) {
        if ((*patients)[i].getDOB() < oldest.getDOB()) {
            oldest = (*patients)[i];
        }
    }
    cout << "Oldest Patient:\n";
    oldest.Print_Patient_Info();
}

// Counts and returns the total number of critical patients
int Hospital::Count_Critical_Patients() {
    int count = 0;
    for (int i = 0; i < patients->size(); i++) {
        if ((*patients)[i].Patient_Status() == "Critical") {
            count++;
        }
    }
    return count;
}

// Displays all doctors with the specified specialty
void Hospital::Doctors_By_Specialty(string specialty) {
    bool found = false;
    for (int i = 0; i < doctors->size(); i++) {
        if ((*doctors)[i].getSpecialty() == specialty) {
            (*doctors)[i].Print_Doctor_Info();
            found = true;
        }
    }
    if (!found) {
        cout << "No doctor has the mentioned specialty.\n";
    }
}

// Displays patient information by their ID
void Hospital::Show_Patient_by_ID(long patient_id) {
    for (int i = 0; i < patients->size(); i++) {
        if ((*patients)[i].getPatientID() == patient_id) {
            (*patients)[i].Print_Patient_Info();
            return;
        }
    }
    cout << "No patient has the provided ID.\n";
}

// Displays doctor information by their ID
void Hospital::Show_Doctor_by_ID(long doctor_id) {
    for (int i = 0; i < doctors->size(); i++) {
        if ((*doctors)[i].getDoctorID() == doctor_id) {
            (*doctors)[i].Print_Doctor_Info();
            return;
        }
    }
    cout << "No doctor has the provided ID.\n";
}

// Shows the doctor assigned to a specific patient
void Hospital::Show_assigned_doctor(long patient_id) {
    for (int i = 0; i < patients->size(); i++) {
        if ((*patients)[i].getPatientID() == patient_id) {
            long doctor_id = (*patients)[i].getAssignedDoctor();
            if (doctor_id == -1) {
                cout << "This patient has no assigned doctor.\n";
                return;
            }
            for (int j = 0; j < doctors->size(); j++) {
                if ((*doctors)[j].getDoctorID() == doctor_id) {
                    (*doctors)[j].Print_Doctor_Info();
                    return;
                }
            }
            cout << "Assigned doctor not found.\n";
            return;
        }
    }
    cout << "No patient has the provided ID.\n";
}

// Displays all patients assigned to a specific doctor
void Hospital::Show_Assigned_Patients(long doctor_id) {
    bool found = false;
    for (int i = 0; i < patients->size(); i++) {
        if ((*patients)[i].getAssignedDoctor() == doctor_id) {
            (*patients)[i].Print_Patient_Info();
            found = true;
        }
    }
    if (!found) {
        cout << "No patients are assigned to this doctor.\n";
    }
}
