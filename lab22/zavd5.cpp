#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Ticket {
    int priority;
    string category;
    string text;

    bool operator<(const Ticket& other) const {
        return priority < other.priority;
    }
};

int getPriorityValue(const string& p) {
    if (p == "high")   return 3;
    if (p == "medium") return 2;
    if (p == "low")    return 1;
    return 0;
}

int main() {
    priority_queue<Ticket> pq;

    int n;
    cout << "Number of tickets: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string cat, text;
        cout << "Priority (high/medium/low): ";
        getline(cin, cat);
        cout << "Text: ";
        getline(cin, text);
        pq.push({getPriorityValue(cat), cat, text});
    }

    cout << "\nProcessing tickets:\n";
    while (!pq.empty()) {
        Ticket t = pq.top();
        pq.pop();
        cout << "[" << t.category << "] " << t.text << "\n";
    }

    return 0;
}
