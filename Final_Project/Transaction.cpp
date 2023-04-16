#include "Transaction.h"

using namespace std;

Transaction::Transaction(int id, string name, map<Item, int> item_list, string type)
    : transaction_id(id), customer_name(name), items(item_list), transaction_type(type) {
    transaction_date = time(0);
    total_amount = calculate_total_amount();
}

double Transaction::calculate_total_amount() {
    double amount = 0;
    for (auto& item : items) {
        amount += item.first.price * item.second;
    }
    return amount;
}
