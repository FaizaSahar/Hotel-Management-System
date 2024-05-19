#pragma once
#include <iostream>
#include <string>
using namespace std;

class Reservation {
private:
    int reservationID;
    string guestName;
    string checkInDate;
    string checkOutDate;
    string roomType;
    double totalCost;
    bool isConfirmed;

public:
    // Constructor
    Reservation(int id, string name, string checkIn, string checkOut, string type, double cost)
        : reservationID(id), guestName(name), checkInDate(checkIn), checkOutDate(checkOut), roomType(type), totalCost(cost), isConfirmed(false) {}

    // Function to handle reservation process
    void bookRoom() {
        if (!isConfirmed) {
            isConfirmed = true;
            cout << "Reservation confirmed for guest " << guestName << ".\n";
        }
        else {
            cout << "Reservation for guest " << guestName << " is already confirmed.\n";
        }
    }

    // Function to calculate reservation cost
    void calculateCost() {
        cout << "Total cost for reservation: $" << totalCost << endl;
    }

    // Function to generate reservation confirmation
    void generateConfirmation() {
        if (isConfirmed) {
            cout << "Reservation Confirmation:" << endl;
            cout << "Reservation ID: " << reservationID << endl;
            cout << "Guest Name: " << guestName << endl;
            cout << "Check-In Date: " << checkInDate << endl;
            cout << "Check-Out Date: " << checkOutDate << endl;
            cout << "Room Type: " << roomType << endl;
            cout << "Total Cost: $" << totalCost << endl;
        }
        else {
            cout << "Reservation for guest " << guestName << " is not confirmed yet.\n";
        }
    }
};