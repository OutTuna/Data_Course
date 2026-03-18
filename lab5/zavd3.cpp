#include <iostream>
#include <string>

using namespace std;

struct CarNode {
    string model;
    int year;
    double price;
    CarNode *next;
};

void addCar(CarNode *&head, string model, int year, double price) {
    CarNode *newNode = new CarNode{model, year, price, head};
    head = newNode;
}

void printFilteredCars(CarNode *head, int currentYear) {
    cout << "Cars older than 10 year and cheaper than 5000$:\n";
    bool found = false;
    for (CarNode *temp = head; temp != nullptr; temp = temp->next) {
        if ((currentYear - temp->year > 10) && (temp->price < 5000)) {
            cout << "- " << temp->model << " (" << temp->year << "), price: " << temp->price << " $\n";
            found = true;
        }
    }
    if (!found) {
        cout << "no cars found.\n";
    }
}

void freeCarsList(CarNode *&head) {
    while (head) {
        CarNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    CarNode *cars = nullptr;
    int currentYear = 2026;
    int n;

    cout << "Enter amount of cars: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string model;
        int year;
        double price;
        cout << "Model auto " << i + 1 << ": ";
        cin >> model;
        cout << "Year of production: ";
        cin >> year;
        cout << "Price ($): ";
        cin >> price;
        addCar(cars, model, year, price);
    }

    printFilteredCars(cars, currentYear);

    freeCarsList(cars);
    return 0;
}
