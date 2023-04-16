#include <iostream>
#include <iomanip>
#include "Inventory.h"

using namespace std;


Inventory::Inventory() { last_updated = time(0); }

void Inventory::add_item(Item item, int count) {
    items[item] = count;
    last_updated = time(0);
}

void Inventory::remove_item(Item item) {
    items.erase(item);
    last_updated = time(0);
}

void Inventory::update_item_count(Item item, int count) {
    items[item] = count;
    last_updated = time(0);
}

int Inventory::get_item_count(Item item) {
    return items[item];
}

void Inventory::display_items() {
    cout << "Items in inventory:\n";
    for (auto& item : items) {
        cout << item.first.item_name << ": " << item.second << endl;
    }

    struct tm timeinfo;
    localtime_s(&timeinfo, &last_updated);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);

    cout << "Last updated: " << buffer << endl;
}
    Item Inventory::find_item_by_id(int id) {
    for (const auto& item_pair : items) {
        if (item_pair.first.get_id() == id) {
            return item_pair.first;
        }
    }
    return Item(-1, "Not Found", 0);
}
