#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class OrderItem {
private:
    string name;
    double price;
    int quantity;
    static vector<OrderItem> items; // Static member to hold order items

public:
    //Default constructor.
    OrderItem()
    {
        name = "NULL";
        price = 0;
        quantity = 0;
    }

    //Parameterized Constructor
    OrderItem(const string& n, double p, int q) : name(n), price(p), quantity(q) {}

    // Function to calculate item subtotal
    double getSubtotal() const {
        return price * quantity;
    }

    // Function to display order item details
    void display() const {
        cout << "Item: " << name << ", Quantity: " << quantity << ", Subtotal: $" << getSubtotal() << endl;
    }

    // Static function to add an item to the order
    static void addItem(const string& name, double price, int quantity) {
        items.emplace_back(name, price, quantity);
    }

    // Static function to calculate total order amount
    static double getTotal() {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.getSubtotal();
        }
        return total;
    }

    // Static function to display order details
    static void displayOrder() {
        cout << "Order Details:" << endl;
        for (const auto& item : items) {
            item.display();
        }
        cout << "Total: $" << getTotal() << std::endl;
    }
};

// Initialize the static member
vector<OrderItem> OrderItem::items;