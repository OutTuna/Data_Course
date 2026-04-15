#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

enum class Status { PENDING, IN_PROGRESS, COMPLETED, CANCELLED };

string statusToStr(Status s) {
    switch (s) {
        case Status::PENDING: return "Pending";
        case Status::IN_PROGRESS: return "In Progress";
        case Status::COMPLETED: return "Completed";
        case Status::CANCELLED: return "Cancelled";
    }
    return "Unknown";
}

Status strToStatus(int c) {
    switch (c) {
        case 1: return Status::PENDING;
        case 2: return Status::IN_PROGRESS;
        case 3: return Status::COMPLETED;
        case 4: return Status::CANCELLED;
        default: return Status::PENDING;
    }
}

struct Order {
    int number;
    string client;
    string address;
    double cost;
    int priority;
    string time;
    Status status;
};

void printOrder(const Order& o) {
    cout << left
         << setw(6) << o.number
         << setw(16) << o.client
         << setw(22) << o.address
         << setw(10) << o.cost
         << setw(5) << o.priority
         << setw(12) << o.time
         << statusToStr(o.status) << "\n";
}

void printHeader() {
    cout << left
         << setw(6) << "No" << setw(16) << "Client"
         << setw(22) << "Address" << setw(10) << "Cost"
         << setw(5) << "Pri" << setw(12) << "Time" << "Status\n";
    cout << string(75, '-') << "\n";
}

Order inputOrder() {
    Order o;
    cout << "Order number: ";
    cin >> o.number;
    cin.ignore();
    cout << "Client surname: ";
    getline(cin, o.client);
    cout << "Delivery address: ";
    getline(cin, o.address);
    cout << "Cost: ";
    cin >> o.cost;
    cout << "Priority (1=high, 5=low): ";
    cin >> o.priority;
    cout << "Time (HH:MM): ";
    cin >> o.time;
    cout << "Status (1-Pending, 2-InProgress, 3-Completed, 4-Cancelled): ";
    int s;
    cin >> s;
    o.status = strToStatus(s);
    return o;
}

void addOrder(deque<Order>& dq) {
    Order o = inputOrder();
    if (o.priority == 1)
        dq.push_front(o);
    else
        dq.push_back(o);
    cout << "Order added.\n";
}

void removeFinished(deque<Order>& dq) {
    int count = 0;
    auto it = dq.begin();
    while (it != dq.end()) {
        if (it->status == Status::COMPLETED || it->status == Status::CANCELLED) {
            it = dq.erase(it);
            count++;
        } else ++it;
    }
    cout << "Removed " << count << " order(s).\n";
}

void searchOrder(const deque<Order>& dq) {
    cout << "Search by: 1-Number  2-Client  3-Status\nChoice: ";
    int c;
    cin >> c;
    printHeader();
    if (c == 1) {
        int num;
        cout << "Order number: ";
        cin >> num;
        for (const auto& o : dq) if (o.number == num) printOrder(o);
    } else if (c == 2) {
        string name;
        cin.ignore();
        cout << "Client surname: ";
        getline(cin, name);
        for (const auto& o : dq) if (o.client == name) printOrder(o);
    } else if (c == 3) {
        cout << "Status (1-Pending, 2-InProgress, 3-Completed, 4-Cancelled): ";
        int s;
        cin >> s;
        Status st = strToStatus(s);
        for (const auto& o : dq) if (o.status == st) printOrder(o);
    }
}

void editOrder(deque<Order>& dq) {
    int num;
    cout << "Order number to edit: ";
    cin >> num;
    for (auto& o : dq) {
        if (o.number == num) {
            cout << "New status (1-Pending, 2-InProgress, 3-Completed, 4-Cancelled): ";
            int s;
            cin >> s;
            o.status = strToStatus(s);
            cout << "New cost (0 to keep " << o.cost << "): ";
            double nc;
            cin >> nc;
            if (nc > 0) o.cost = nc;
            cout << "Order updated.\n";
            return;
        }
    }
    cout << "Order not found.\n";
}

void sortByCost(deque<Order>& dq) {
    sort(dq.begin(), dq.end(), [](const Order& a, const Order& b) { return a.cost < b.cost; });
    cout << "Sorted by cost.\n";
}

void filterOrders(const deque<Order>& dq) {
    cout << "Filter by: 1-Cost range  2-Status  3-Time range  4-Priority\nChoice: ";
    int c;
    cin >> c;
    printHeader();
    if (c == 1) {
        double lo, hi;
        cout << "Min cost: ";
        cin >> lo;
        cout << "Max cost: ";
        cin >> hi;
        for (const auto& o : dq) if (o.cost >= lo && o.cost <= hi) printOrder(o);
    } else if (c == 2) {
        cout << "Status (1-Pending, 2-InProgress, 3-Completed, 4-Cancelled): ";
        int s;
        cin >> s;
        Status st = strToStatus(s);
        for (const auto& o : dq) if (o.status == st) printOrder(o);
    } else if (c == 3) {
        string t1, t2;
        cout << "From (HH:MM): ";
        cin >> t1;
        cout << "To   (HH:MM): ";
        cin >> t2;
        for (const auto& o : dq) if (o.time >= t1 && o.time <= t2) printOrder(o);
    } else if (c == 4) {
        int p;
        cout << "Priority: ";
        cin >> p;
        for (const auto& o : dq) if (o.priority == p) printOrder(o);
    }
}

void printAll(const deque<Order>& dq) {
    if (dq.empty()) {
        cout << "Queue is empty.\n";
        return;
    }
    printHeader();
    for (const auto& o : dq) printOrder(o);
}

int main() {
    deque<Order> dq;
    int choice;
    do {
        cout << "\n===== DELIVERY SERVICE MENU =====\n"
             << "1. Add order\n"
             << "2. Remove completed/cancelled orders\n"
             << "3. Search orders\n"
             << "4. Edit order\n"
             << "5. Sort by cost\n"
             << "6. Filter orders\n"
             << "7. View all orders\n"
             << "0. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addOrder(dq); break;
            case 2: removeFinished(dq); break;
            case 3: searchOrder(dq); break;
            case 4: editOrder(dq); break;
            case 5: sortByCost(dq); break;
            case 6: filterOrders(dq); break;
            case 7: printAll(dq); break;
            case 0: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
