#pragma once

#include <string>
using namespace std;
class Item {
public:
    int item_id;
    string item_name;
    double price;

    Item(int id, std::string name, double p);

    bool operator<(const Item& other) const;

    int get_id() const;

    std::string get_name() const;

};
