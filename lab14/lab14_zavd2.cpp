#include <iostream>
#include <map>
#include <string>
using namespace std;

void printAll(map<string, int> &warehouse) {
    if (warehouse.empty()) {
        cout << "Warehouse is empty \n";
        return;
    }
    for (auto &[name,qty]: warehouse) {
        cout << name << ": " << qty << "\n";
    }
}

int main() {
    map<string, int> warehouse;
    int choice;
    do {
        cout << "\n1.Add items\n2.Change count\n3.Delete goods\n"
                "4.Find goods\n5.List of all goods\n0.Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name;
            int qty;
            cout << "Name: ";
            getline(cin, name);
            cout << "Count: ";
            cin >> qty;
            cin.ignore();
            warehouse[name] += qty;
            cout << "Added.\n";
        } else if (choice == 2) {
            string name;
            int qty;
            cout << "Name: ";
            getline(cin, name);
            if (warehouse.count(name)) {
                cout << "New Count: ";
                cin >> qty;
                cin.ignore();
                warehouse[name] = qty;
                cout << "Updated.\n";
            } else cout << "Goods is not finded\n";
        } else if (choice == 3) {
            string name;
            cout << "Name: ";
            getline(cin, name);
            if (warehouse.erase(name)) cout << "Deleted.\n";
            else cout << "Goods not found.\n";
        } else if (choice == 4) {
            string name;
            cout << "Name: ";
            getline(cin, name);
            auto it = warehouse.find(name);
            if (it != warehouse.end())
                cout << it->first << ": " << it->second << "\n";
            else cout << "Goods not found.\n";
        } else if (choice == 5) {
            printAll(warehouse);
        }
    } while (choice != 0);

    return 0;
}
