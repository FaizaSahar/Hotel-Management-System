#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Hotel
{
private:
    char name[50];
    char location[50];
    char contactDetails[20];
    int numberOfFloors;
    int roomsPerFloor;
    char** roomTypes; // Array to store room types

public:
    // Constructor
    Hotel(const char* n, const char* loc, const char* contact, int floors, int rooms) {
        strcpy_s(name, sizeof(name), n);
        strcpy_s(location, sizeof(location), loc);
        strcpy_s(contactDetails, sizeof(contactDetails), contact);
        numberOfFloors = floors;
        roomsPerFloor = rooms;
        roomTypes = new char* [roomsPerFloor];
        for (int i = 0; i < roomsPerFloor; ++i) {
            roomTypes[i] = new char[50];
        }
    }

    // Destructor
    ~Hotel() {
        for (int i = 0; i < roomsPerFloor; ++i) {
            delete[] roomTypes[i];
        }
        delete[] roomTypes; // Free dynamically allocated memory
    }

    // Function to add room types
    void addRoomType(int floor, const char* type) {
        if (floor <= numberOfFloors && floor >= 1) {
            // Assuming roomTypes is an array of character arrays (strings)
            const size_t MAX_TYPE_SIZE = 50;
            strcpy_s(roomTypes[floor - 1], MAX_TYPE_SIZE, type); // Store room type at index corresponding to floor number
        }
        else {
            cout << "Invalid floor number. Please enter a valid floor number.\n";
        }
    }

    // Function to update hotel information
    void updateHotelInfo(const char* n, const char* loc, const char* contact, int floors, int rooms) {
        strcpy_s(name, n);
        strcpy_s(location, sizeof(location), loc);
        strcpy_s(contactDetails, contact);
        numberOfFloors = floors;
        roomsPerFloor = rooms;
        for (int i = 0; i < roomsPerFloor; ++i) {
            delete[] roomTypes[i];
        }
        delete[] roomTypes; // Free previously allocated memory
        roomTypes = new char* [roomsPerFloor]; // Allocate memory for new room types array
        for (int i = 0; i < roomsPerFloor; ++i) {
            roomTypes[i] = new char[50];
        }
    }

    // Function to display hotel information
    void displayHotelInfo() {
        cout << "Hotel Name: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Contact Details: " << contactDetails << endl;
        cout << "Number of Floors: " << numberOfFloors << endl;
        cout << "Rooms Per Floor: " << roomsPerFloor << endl;
        cout << "Room Types:\n";
        for (int i = 0; i < numberOfFloors; ++i) {
            cout << "Floor " << i << ": " << roomTypes[i] << endl;
        }
    }
};