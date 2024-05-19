#pragma once
#include <iostream>
#include <string>
using namespace std;

class Staff {
private:
    string name;
    string contactDetails;
    string role;
    string shift;
    int workAssignments;
    int totalHoursWorked;

public:
    // Constructor
    Staff(string n, string contact, string r, string s) : name(n), contactDetails(contact), role(r), shift(s), workAssignments(0), totalHoursWorked(0) {}

    // Function to assign a shift to staff
    void assignShift(std::string s) {
        shift = s;
        cout << "Shift assigned to staff " << name << ": " << shift << endl;
    }

    // Function to assign work to staff
    void assignWork(int hours) {
        workAssignments++;
        totalHoursWorked += hours;
        cout << "Work assigned to staff " << name << ". Total hours worked: " << totalHoursWorked << endl;
    }

    // Function to update staff information
    void updateInformation(string newContact, string newRole) {
        contactDetails = newContact;
        role = newRole;
        cout << "Staff information updated for " << name << ".\n";
    }

    // Function to display staff information
    void displayInformation() {
        cout << "Staff Name: " << name << endl;
        cout << "Contact Details: " << contactDetails << endl;
        cout << "Role: " << role << endl;
        cout << "Shift: " << shift << endl;
        cout << "Total Work Assignments: " << workAssignments << endl;
        cout << "Total Hours Worked: " << totalHoursWorked << endl;
    }
};