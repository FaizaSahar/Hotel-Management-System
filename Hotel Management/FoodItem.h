#pragma once
#include <iostream>
#include <string>
using namespace std;

class FoodItem {
private:
    string name;
    double price;
    bool available;

public:
    // Constructor
    FoodItem(const string& n, double p, bool a) : name(n), price(p), available(a) {}

    // Function to get food item name
    string getName() const {
        return name;
    }

    // Function to get food item price
    double getPrice() const {
        return price;
    }

    // Function to check if food item is available
    bool isAvailable() const {
        return available;
    }

    // Function to update food item availability
    void setAvailability(bool a) {
        available = a;
    }
};