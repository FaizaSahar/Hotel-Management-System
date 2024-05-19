#include <iostream>
#include "Hotel.h"
#include "Room.h"
#include "Guest.h"
#include "Reservation.h"
#include "Staff.h"
#include "Inventory.h"
#include "FoodItem.h"
#include "OrderItem.h"
#include "Payment.h"
#include "Billing.h"

int main() {
    int choice;
    do {
        cout << "---------------------------------------------------\n";
        cout << " HOTEL MANAGEMENT SYSTEM MENU " << endl;
        cout << "---------------------------------------------------\n";
        cout << "1. Hotel Information" << endl;
        cout << "2. Room Management" << endl;
        cout << "3. Guest Management" << endl;
        cout << "4. Reservation Management" << endl;
        cout << "5. Staff Management" << endl;
        cout << "6. Inventory Management" << endl;
        cout << "7. Food Item Management" << endl;
        cout << "8. Order Management" << endl;
        cout << "9. Payment Management" << endl;
        cout << "10. Billing Management" << endl;
        cout << "0. Exit" << endl;
        cout << "---------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "---------------------------------------------------\n";

        switch (choice) {
        case 1: {
            // Hotel Information
            Hotel myHotel("Grand Hotel", "New York City", "123-456-7890", 5, 10);
            myHotel.addRoomType(1, "Single");
            myHotel.addRoomType(2, "Double");
            myHotel.addRoomType(3, "Suite");
            myHotel.addRoomType(4, "Executive Suite");
            myHotel.addRoomType(5, "Penthouse");
            myHotel.displayHotelInfo();
            cout << "---------------------------------------------------\n";
            break;
        }
        case 2: {
            // Room Management
            Room room1(101, "Single", 50.0);
            Room room2(102, "Double", 70.0);
            room1.reserveRoom();
            room1.reserveRoom(); // Try to reserve room 1 again (should fail)
            room1.checkIn();
            room1.checkOut();
            double charges = room2.calculateRoomCharges(3);
            cout << "Total charges for Room 2 for 3 nights: $" << charges << endl;
            cout << "---------------------------------------------------\n";
            break;
        }
        case 3: {
            // Guest Management
            Guest guest1("Alice", "alice@example.com");
            Guest guest2("Bob", "bob@example.com");
            guest1.makeReservation();
            guest1.makeReservation(); // Try to make reservation for guest 1 again (should fail)
            guest1.checkIn();
            guest1.checkIn(); // Try to check-in guest 1 again (should fail)
            guest1.checkOut();
            guest2.updateInformation("newbob@example.com", "Non-smoking room");
            guest2.displayInformation();
            cout << "---------------------------------------------------\n";
            break;
        }
        case 4: {
            // Reservation Management
            Reservation reservation1(1001, "Alice", "2024-05-01", "2024-05-05", "Single", 500.0);
            reservation1.bookRoom();
            reservation1.calculateCost();
            reservation1.generateConfirmation();
            cout << "---------------------------------------------------\n";
            break;
        }
        case 5: {
            // Staff Management
            Staff staff1("John", "john@example.com", "Receptionist", "Morning");
            Staff staff2("Alice", "alice@example.com", "Housekeeper", "Evening");
            staff1.assignShift("Afternoon");
            staff1.assignWork(8);
            staff2.updateInformation("newalice@example.com", "Manager");
            staff2.displayInformation();
            cout << "---------------------------------------------------\n";
            break;
        }
        case 6: {
            // Inventory Management
            Inventory inventory;
            Supplier supplier = { "ABC Supplier", "123-456-789" };
            inventory.addItem("Pencils", 50, 20, supplier);
            inventory.addItem("Notebooks", 30, 15, supplier);
            inventory.displayInventory();
            inventory.updateQuantity("Pencils", 60);
            inventory.reorderItems();
            cout << "---------------------------------------------------\n";
            break;
        }
        case 7: {
            // Food Item Management
            FoodItem sandwich("Sandwich", 5.99, true);
            cout << "Food Item: " << sandwich.getName() << endl;
            cout << "Price: $" << sandwich.getPrice() << endl;
            cout << "Availability: " << (sandwich.isAvailable() ? "Available" : "Not Available") << endl;
            sandwich.setAvailability(false);
            cout << "Updated Availability: " << (sandwich.isAvailable() ? "Available" : "Not Available") << endl;
            cout << "---------------------------------------------------\n";
            break;
        }
        case 8: {
            // Order Management
            OrderItem order;
            order.addItem("Sandwich", 5.99, 2);
            order.addItem("Coffee", 2.49, 1);
            order.display();
            cout << "---------------------------------------------------\n";
            break;
        }
        case 9: {
            // Payment Management
            Payment payment1(1001, 500.0, "Credit Card");
            payment1.processPayment();
            payment1.recordTransaction();
            payment1.updatePaymentStatus(false);
            cout << "---------------------------------------------------\n";
            break;
        }
        case 10: {
            // Billing Management
            Billing bill1(1001, 200.0, 50.0);
            bill1.calculateTotalCharges(10.0);
            bill1.generateInvoice();
            bill1.generateReceipt();
            cout << "---------------------------------------------------\n";
            break;
        }
        case 0:
            cout << "Exiting..." << endl;
            cout << "---------------------------------------------------\n";
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            cout << "---------------------------------------------------\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
