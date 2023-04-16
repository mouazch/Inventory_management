#pragma once

#include <ctime>
#include <map>
#include "Item.h"
using namespace std;
class Inventory {
public:
    map<Item, int> items;
    time_t last_updated;

    Inventory();

    void add_item(Item item, int count);

    void remove_item(Item item);

    void update_item_count(Item item, int count);

    int get_item_count(Item item);

    void display_items();

    Item find_item_by_id(int id);

};

