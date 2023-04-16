#pragma once

#include <string>
#include <vector>
#include "Transaction.h"
using namespace std;
class Customer {
public:
    int customer_id;
    string name;
    vector<Transaction> visit_history;

    Customer(int id, std::string n);

    void add_visit(Transaction transaction);

    double get_total_spent();

    int get_visits_count() const;
};
