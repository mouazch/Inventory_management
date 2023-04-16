#include "Item.h"

using namespace std;

Item::Item(int id, string name, double p) : item_id(id), item_name(name), price(p) {}

bool Item::operator<(const Item& other) const {
    return item_id < other.item_id;
}

int Item::get_id() const {
    return item_id;
}

string Item::get_name() const {
    return item_name;
}
