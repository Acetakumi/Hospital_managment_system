#ifndef DOCTORS_H
#define DOCTORS_H

#include <string>
#include <iostream>
using namespace std;

// Class representing a Doctor in the hospital system
class Doctor {
private:
    // Private attributes for doctor details
    string firstName, lastName, specialty;  // Doctor's name and specialty
    long doctorID;                               // Unique ID for the doctor
    int yearsExperience;                         // Years of experience
    double baseSalary, performanceBonus;         // Salary details

public:
    // Default constructor
    Doctor();

    // Parameterized constructor to initialize doctor details
    Doctor(string fName, string lName, long id, string spec, int years, double salary, double bonus);

    // Method to print all doctor information
    void Print_Doctor_Info();

    // Method to calculate the total salary including performance bonus
    double Calculate_Salary();

    // Setters to modify private attributes
    void setFirstName(string name);
    void setLastName(string name);
    void setSpecialty(string spec);
    void setDoctorID(long id);
    void setYearsExperience(int years);
    void setBaseSalary(double salary);
    void setPerformanceBonus(double bonus);

    // Getters to access private attributes
    string getSpecialty();
    long getDoctorID();
};

#endif // DOCTORS_H
