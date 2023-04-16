#pragma once

#include <string>
#include <ctime>
#include <map>
#include "Item.h"
using namespace std;
class Transaction {
public:
    int transaction_id;
    string customer_name;
    map<Item, int> items;
    time_t transaction_date;
    string transaction_type;
    double total_amount;

    Transaction(int id, std::string name, std::map<Item, int> item_list, std::string type);

    double calculate_total_amount();
};

