#include <iostream>
#include <string>
using namespace std;

class Room {
private:
    int roomNumber;
    string roomType;
    bool isAvailable;
    double roomRate;

public:
    // Constructor
    Room(int number, std::string type, double rate) : roomNumber(number), roomType(type), roomRate(rate), isAvailable(true) {}

    // Function to reserve the room
    void reserveRoom() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Room " << roomNumber << " has been reserved.\n";
        }
        else {
            cout << "Room " << roomNumber << " is not available for reservation.\n";
        }
    }

    // Function to check-in to the room
    void checkIn() {
        if (!isAvailable) {
            cout << "Checked into Room " << roomNumber << ".\n";
        }
        else {
            cout << "Room " << roomNumber << " is not reserved. Please reserve it first.\n";
        }
    }

    // Function to check-out of the room
    void checkOut() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Checked out of Room " << roomNumber << ".\n";
        }
        else {
            cout << "Room " << roomNumber << " is already available.\n";
        }
    }

    // Function to check room availability
    bool checkAvailability() {
        return isAvailable;
    }

    // Function to calculate room charges
    double calculateRoomCharges(int numberOfNights) {
        return roomRate * numberOfNights;
    }
};