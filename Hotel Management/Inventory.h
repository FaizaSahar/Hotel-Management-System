#include <iostream>
#include <string>
using namespace std;

// Structure to represent supplier information
struct Supplier {
    string name;
    string contact;
};

// Structure to represent inventory items
struct InventoryItem {
    string name;
    int quantity = 0;
    int reorderPoint = 0;
    Supplier supplier;
};

class Inventory {
private:
    static const int MAX_ITEMS = 100; // Maximum number of inventory items
    InventoryItem items[MAX_ITEMS];   // Array to store inventory items
    int itemCount;                    // Current number of inventory items

public:
    // Constructor
    Inventory() : itemCount(0) {}

    // Function to add an inventory item
    void addItem(string name, int quantity, int reorderPoint, Supplier supplier) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount].name = name;
            items[itemCount].quantity = quantity;
            items[itemCount].reorderPoint = reorderPoint;
            items[itemCount].supplier = supplier;
            itemCount++;
            cout << "Item added to inventory: " << name << endl;
        }
        else {
            cout << "Inventory is full. Cannot add more items." << endl;
        }
    }

    // Function to display all inventory items
    void displayInventory() {
        cout << "Inventory Items:" << endl;
        for (int i = 0; i < itemCount; ++i) {
            cout << "Name: " << items[i].name << ", Quantity: " << items[i].quantity << ", Reorder Point: " << items[i].reorderPoint << endl;
            cout << "Supplier: " << items[i].supplier.name << ", Contact: " << items[i].supplier.contact << endl;
        }
    }

    // Function to update inventory item quantity
    void updateQuantity(string itemName, int newQuantity) {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].name == itemName) {
                items[i].quantity = newQuantity;
                cout << "Quantity updated for item " << itemName << endl;
                return;
            }
        }
        cout << "Item not found in inventory." << endl;
    }

    // Function to reorder items when quantity falls below reorder point
    void reorderItems() {
        cout << "Reordering items..." << endl;
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].quantity < items[i].reorderPoint) {
                cout << "Reordering item: " << items[i].name << endl;
                // Add your logic to reorder the item here
            }
        }
    }
};