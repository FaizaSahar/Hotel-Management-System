#pragma once
#include <iostream>
#include <string>
using namespace std;

class Payment {
private:
    int paymentID;
    double amount;
    string paymentMethod;
    bool isPaid;

public:
    // Constructor
    Payment(int id, double amt, string method) : paymentID(id), amount(amt), paymentMethod(method), isPaid(false) {}

    // Function to process payment
    void processPayment() {
        isPaid = true;
        cout << "Payment processed successfully." << endl;
    }

    // Function to record payment transaction
    void recordTransaction() {
        cout << "Payment ID: " << paymentID << endl;
        cout << "Amount: $" << amount << endl;
        cout << "Payment Method: " << paymentMethod << endl;
        cout << "Payment Status: " << (isPaid ? "Paid" : "Pending") << endl;
    }

    // Function to update payment status
    void updatePaymentStatus(bool status) {
        isPaid = status;
        cout << "Payment status updated." << endl;
    }
};