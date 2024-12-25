#include "doctors.h"
using namespace std;

// Default constructor: Initializes a Doctor object with default values
Doctor::Doctor() {}

// Parameterized constructor: Initializes a Doctor object with specific values
Doctor::Doctor(string fName, string lName, long id, string spec,int years, double salary, double bonus) {
    firstName = fName;          // Initialize first name
    lastName = lName;           // Initialize last name
    doctorID = id;              // Assign doctor ID
    specialty = spec;           // Assign specialty
    yearsExperience = years;    // Set years of experience
    baseSalary = salary;        // Set base salary
    performanceBonus = bonus;   // Set performance bonus
}

// Prints the doctor’s details
void Doctor::Print_Doctor_Info() {
    cout << "Doctor ID: " << doctorID
              << "\nName: " << firstName << " " << lastName
              << "\nSpecialty: " << specialty
              << "\nYears of Experience: " << yearsExperience
              << "\nSalary: $" << Calculate_Salary() << "\n";
}

// Calculates the total salary based on base salary and performance bonus
double Doctor::Calculate_Salary() {
    return baseSalary + (baseSalary * performanceBonus);
}

// Setters: Update specific attributes
void Doctor::setFirstName(string name) {
    firstName = name;
}
void Doctor::setLastName(string name) {
    lastName = name;
}
void Doctor::setSpecialty(string spec) {
    specialty = spec;
}
void Doctor::setDoctorID(long id) {
    doctorID = id;
}
void Doctor::setYearsExperience(int years) {
    yearsExperience = years;
}
void Doctor::setBaseSalary(double salary) {
    baseSalary = salary;
}
void Doctor::setPerformanceBonus(double bonus) {
    performanceBonus = bonus;
}

// Getters: Retrieve specific attributes
string Doctor::getSpecialty() { return specialty; }
long Doctor::getDoctorID() { return doctorID; }
