#include <iostream>
#include <list>
#include <string>
#include <iomanip>

using namespace std;

struct Car {
    string name;
    int year;
    double mileage;
};

void printCar(const Car& c) {
    cout << left << setw(20) << c.name
         << setw(8) << c.year
         << c.mileage << " km\n";
}

void printList(const list<Car>& lst) {
    if (lst.empty()) {
        cout << "List is empty.\n";
        return;
    }
    cout << left << setw(20) << "Name" << setw(8) << "Year" << "Mileage\n";
    cout << string(40, '-') << "\n";
    for (const auto& c : lst) printCar(c);
}

Car inputCar() {
    Car c;
    cin.ignore();
    cout << "Car name: ";
    getline(cin, c.name);
    cout << "Year: ";
    cin >> c.year;
    cout << "Mileage (km): ";
    cin >> c.mileage;
    return c;
}

void insertFirst(list<Car>& lst) {
    lst.push_front(inputCar());
    cout << "Inserted at front.\n";
}

void insertBeginning(list<Car>& lst) {
    lst.push_front(inputCar());
    cout << "Inserted at beginning.\n";
}

void insertEnd(list<Car>& lst) {
    lst.push_back(inputCar());
    cout << "Inserted at end.\n";
}

void insertAfter(list<Car>& lst) {
    string target;
    cin.ignore();
    cout << "Insert after car named: ";
    getline(cin, target);
    Car newCar = inputCar();
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        if (it->name == target) {
            lst.insert(next(it), newCar);
            cout << "Inserted after '" << target << "'.\n";
            return;
        }
    }
    cout << "Car '" << target << "' not found.\n";
}

void insertBefore(list<Car>& lst) {
    string target;
    cin.ignore();
    cout << "Insert before car named: ";
    getline(cin, target);
    Car newCar = inputCar();
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        if (it->name == target) {
            lst.insert(it, newCar);
            cout << "Inserted before '" << target << "'.\n";
            return;
        }
    }
    cout << "Car '" << target << "' not found.\n";
}

void searchCar(const list<Car>& lst) {
    string name;
    cin.ignore();
    cout << "Car name to search: ";
    getline(cin, name);
    for (const auto& c : lst) {
        if (c.name == name) {
            cout << "Car with name '" << name << "' is in the list.\n";
            return;
        }
    }
    cout << "Car with name '" << name << "' is NOT in the list.\n";
}

void deleteByYear(list<Car>& lst) {
    int year;
    cout << "Delete cars with year less than: ";
    cin >> year;
    int count = 0;
    auto it = lst.begin();
    while (it != lst.end()) {
        if (it->year < year) {
            it = lst.erase(it);
            count++;
        } else ++it;
    }
    cout << "Deleted " << count << " car(s).\n";
}

int main() {
    list<Car> lst;
    int choice;
    do {
        cout << "\n-------- MENU FOR WORKING WITH LIST --------\n"
             << "1. Enter first element into list\n"
             << "2. Insert element at beginning of list\n"
             << "3. Insert element at end of list\n"
             << "4. Insert element after given element\n"
             << "5. Insert element before given element\n"
             << "6. Search for required node\n"
             << "7. Delete node with given value\n"
             << "8. View list\n"
             << "9. Exit\n"
             << "--------------------------------------------\n"
             << "Enter operation number: ";
        cin >> choice;
        switch (choice) {
            case 1: insertFirst(lst); break;
            case 2: insertBeginning(lst); break;
            case 3: insertEnd(lst); break;
            case 4: insertAfter(lst); break;
            case 5: insertBefore(lst); break;
            case 6: searchCar(lst); break;
            case 7: deleteByYear(lst); break;
            case 8: printList(lst); break;
            case 9: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 9);
    return 0;
}
