#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Item Structure / Class
class Item {
public:
    int id;
    string name;
    int quantity;
    double price;

    Item(int id, string name, int quantity, double price) {
        this->id = id;
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }
};

// Inventory Manager Class
class Inventory {
private:
    vector<Item> items;

public:

    // Add Item
    void addItem() {
        int id, quantity;
        string name;
        double price;

        cout << "\nEnter Item ID: ";
        cin >> id;
        cout << "Enter Item Name: ";
        cin >> name;
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ₹";
        cin >> price;

        items.push_back(Item(id, name, quantity, price));
        cout << "\nItem Added Successfully ✅\n";
    }

    // Display All Items
    void displayItems() {
        if (items.empty()) {
            cout << "\nNo items in inventory ❌\n";
            return;
        }

        cout << "\n---------- Inventory List ----------\n";
        for (auto &item : items) {
            cout << "ID: " << item.id
                 << " | Name: " << item.name
                 << " | Qty: " << item.quantity
                 << " | Price: ₹" << item.price << "\n";
        }
        cout << "-------------------------------------\n";
    }

    // Search Item by ID
    void searchItem() {
        int id;
        cout << "\nEnter Item ID to Search: ";
        cin >> id;

        for (auto &item : items) {
            if (item.id == id) {
                cout << "\nItem Found ✅\n";
                cout << "ID: " << item.id << "\nName: " << item.name
                     << "\nQuantity: " << item.quantity
                     << "\nPrice: ₹" << item.price << "\n";
                return;
            }
        }
        cout << "\nItem Not Found ❌\n";
    }

    // Update Item
    void updateItem() {
        int id;
        cout << "\nEnter Item ID to Update: ";
        cin >> id;

        for (auto &item : items) {
            if (item.id == id) {
                cout << "\nEnter New Name: ";
                cin >> item.name;
                cout << "Enter New Quantity: ";
                cin >> item.quantity;
                cout << "Enter New Price: ₹";
                cin >> item.price;
                cout << "\nItem Updated Successfully ✅\n";
                return;
            }
        }
        cout << "\nItem Not Found ❌\n";
    }

    // Delete Item
    void deleteItem() {
        int id;
        cout << "\nEnter Item ID to Delete: ";
        cin >> id;

        for (int i = 0; i < items.size(); i++) {
            if (items[i].id == id) {
                items.erase(items.begin() + i);
                cout << "\nItem Deleted Successfully ✅\n";
                return;
            }
        }
        cout << "\nItem Not Found ❌\n";
    }

    // Menu
    void menu() {
        int choice;

        do {
            cout << "\n========== INVENTORY MENU ==========\n";
            cout << "1. Add Item\n";
            cout << "2. Display All Items\n";
            cout << "3. Search Item\n";
            cout << "4. Update Item\n";
            cout << "5. Delete Item\n";
            cout << "6. Exit\n";
            cout << "====================================\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addItem();
                break;

            case 2:
                displayItems();
                break;

            case 3:
                searchItem();
                break;

            case 4:
                updateItem();
                break;

            case 5:
                deleteItem();
                break;

            case 6:
                cout << "\nExiting Inventory System... ✅\n";
                break;

            default:
                cout << "\nInvalid Choice ❌\n";
            }

        } while (choice != 6);
    }
};

int main() {
    Inventory inv;

    cout << "====================================\n";
    cout << "      INVENTORY MANAGEMENT SYSTEM    \n";
    cout << "====================================\n";

    inv.menu();

    return 0;
}