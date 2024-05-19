#pragma once
#include<iostream>
#include <string>
using namespace std;

class Guest
{
private:
    string name;
    string contactDetails;
    string preferences;
    bool hasReservation;
    bool isCheckedIn;

public:
    // Constructor
    Guest(string n, string contact) : name(n), contactDetails(contact), hasReservation(false), isCheckedIn(false) {}

    // Function to make a reservation for the guest
    void makeReservation() {
        if (!hasReservation) {
            hasReservation = true;
            cout << "Reservation made for guest " << name << ".\n";
        }
        else {
            cout << "Guest " << name << " already has a reservation.\n";
        }
    }

    // Function to check-in the guest
    void checkIn() {
        if (hasReservation && !isCheckedIn) {
            isCheckedIn = true;
            cout << "Guest " << name << " has checked in.\n";
        }
        else {
            cout << "Guest " << name << " cannot check in without a reservation or already checked in.\n";
        }
    }

    // Function to check-out the guest
    void checkOut() {
        if (isCheckedIn) {
            isCheckedIn = false;
            hasReservation = false; // Assuming check-out cancels reservation
            cout << "Guest " << name << " has checked out.\n";
        }
        else {
            cout << "Guest " << name << " cannot check out without checking in first.\n";
        }
    }

    // Function to update guest information
    void updateInformation(string newContact, string newPreferences) {
        contactDetails = newContact;
        preferences = newPreferences;
        cout << "Guest information updated for " << name << ".\n";
    }

    // Function to display guest information
    void displayInformation() {
        cout << "Guest Name: " << name << endl;
        cout << "Contact Details: " << contactDetails << endl;
        cout << "Preferences: " << preferences << endl;
        cout << "Reservation Status: " << (hasReservation ? "Yes" : "No") << endl;
        cout << "Check-In Status: " << (isCheckedIn ? "Yes" : "No") << endl;
    }
};