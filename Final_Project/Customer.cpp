#include "Customer.h"

using namespace std;

Customer::Customer(int id, string n) : customer_id(id), name(n) {}

void Customer::add_visit(Transaction transaction) {
    visit_history.push_back(transaction);
}

double Customer::get_total_spent() {
    double total_spent = 0;
    for (auto& transaction : visit_history) {
        total_spent += transaction.total_amount;
    }
    return total_spent;
}
int Customer::get_visits_count() const {
    return visit_history.size();
}
