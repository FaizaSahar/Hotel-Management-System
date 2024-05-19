#pragma once
#include <iostream>
#include <string>
using namespace std;

class Billing {
private:
    int billID;
    double roomCharges;
    double additionalCharges;
    double totalCharges;

public:
    // Constructor
    Billing(int id, double room, double additional) : billID(id), roomCharges(room), additionalCharges(additional), totalCharges(0.0) {}

    // Function to calculate total charges
    void calculateTotalCharges(double taxRate) {
        double taxAmount = (roomCharges + additionalCharges) * taxRate / 100.0;
        totalCharges = roomCharges + additionalCharges + taxAmount;
    }

    // Function to generate invoice
    void generateInvoice() {
        cout << "Invoice" << endl;
        cout << "Bill ID: " << billID << endl;
        cout << "Room Charges: $" << roomCharges << endl;
        cout << "Additional Charges: $" << additionalCharges << endl;
        cout << "Total Charges: $" << totalCharges << endl;
    }

    // Function to generate receipt
    void generateReceipt() {
        cout << "Receipt" << endl;
        cout << "Bill ID: " << billID << endl;
        cout << "Total Amount Paid: $" << totalCharges << endl;
    }
};