#include <iostream>
#include <iomanip>
#include <sstream>
#include "Item.h"
#include "Transaction.h"
#include "Customer.h"
#include "Inventory.h"

using namespace std;

void show_menu() {
    cout << "\nChoose an option:" << endl;
    cout << "1. Add item to inventory" << endl;
    cout << "2. Remove item from inventory" << endl;
    cout << "3. Update item count in inventory" << endl;
    cout << "4. Display items in inventory" << endl;
    cout << "5. Add customer visit" << endl;
    cout << "6. Get total amount spent by customer" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

void clear_input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    // Create an inventory
    Inventory inventory;

    // Create a map to store customers
    map<int, Customer*> customers;

    int choice;
    stringstream output;
    while (true) {
        show_menu();
        cin >> choice;
        clear_input(); // Clear the input stream here

        if (choice < 1 || choice > 7) {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }

        output.str(""); // Clear the output stringstream
        output << setfill('-') << setw(40) << "-" << setfill(' ') << "\n";
        
            switch (choice) {
            case 1: {
                int item_id;
                string item_name;
                double price;
                int count;

                cout << "Enter item ID: ";
                cin >> item_id;
                cout << "Enter item name: ";
                cin >> item_name;
                cout << "Enter item price: ";
                cin >> price;
                cout << "Enter item count: ";
                cin >> count;

                Item item(item_id, item_name, price);
                inventory.add_item(item, count);
                output << "Added " << count << " of " << item_name << " (ID: " << item_id << ") to inventory.\n";
                break;
            }
            case 2: {
                int item_id;
                cout << "Enter item ID to remove: ";
                cin >> item_id;

                Item item = inventory.find_item_by_id(item_id);
                if (item.get_id() != -1) {
                    inventory.remove_item(item);
                    output << "Removed " << item.get_name() << " (ID: " << item_id << ") from inventory.\n";
                }
                else {
                    cout << "Item not found." << endl;
                }
                break;
            }
            case 3: {
                int item_id, count;
                cout << "Enter item ID to update: ";
                cin >> item_id;
                cout << "Enter new item count: ";
                cin >> count;

                Item item = inventory.find_item_by_id(item_id);
                if (item.get_id() != -1) {
                    inventory.update_item_count(item, count);
                    output << "Updated " << item.get_name() << " (ID: " << item_id << ") count to " << count << ".\n";
                }
                else {
                    cout << "Item not found." << endl;
                }
                break;
            }
            case 4: {
                inventory.display_items();
                break;
            }
            case 5: {
            int customer_id;
            cout << "Enter customer ID: ";
            cin >> customer_id;

            string customer_name;
            cout << "Enter customer name: ";
            cin >> customer_name;

            Customer* customer = nullptr;
            if (customers.find(customer_id) != customers.end()) {
                customer = customers[customer_id];
            }
            else {
                customer = new Customer(customer_id, customer_name);
                customers[customer_id] = customer;
            }

            // Add a transaction to the customer's visit history
            map<Item, int> items_bought;
            int item_id, item_count;
            char add_more_items = 'y';
            while (tolower(add_more_items) == 'y') {
                cout << "Enter item ID: ";
                cin >> item_id;
                Item item = inventory.find_item_by_id(item_id);
                if (item.get_id() == -1) {
                    cout << "Item not found." << endl;
                    continue;
                }

                cout << "Enter item count: ";
                cin >> item_count;
                items_bought[item] = item_count;

                cout << "Add more items? (y/n): ";
                cin >> add_more_items;
            }

            Transaction transaction(customer->get_visits_count() + 1, customer_name, items_bought, "purchase");
            customer->add_visit(transaction);

            output << "Added visit for customer " << customer_name << " (ID: " << customer_id << ")\n";
            break;
        }
              // Case 6: Get total amount spent by customer
        case 6: {
            int customer_id;
            cout << "Enter customer ID: ";
            cin >> customer_id;

            if (customers.find(customer_id) == customers.end()) {
                cout << "Customer not found." << endl;
                break;
            }

            Customer* customer = customers[customer_id];
            output << "Total amount spent by " << customer->name << ": $" << fixed << setprecision(2) << customer->get_total_spent() << "\n";
            break;
        }
        case 7:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }

        if (choice != 7) {
            cout << output.str();
            output.str(""); // Clear the output stringstream
        }
    } while (choice != 7);

    // Clean up allocated memory
    for (auto& kv : customers) {
        delete kv.second;
    }

    return 0;
}