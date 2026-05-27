#include <iostream>
#include <string>

using namespace std;

struct CityNode {
    string name;
    double distance;
    CityNode *next;
};

// adds city node to list
void addCity(CityNode *&head, string name, double distance) {
    CityNode *newNode = new CityNode{name, distance, head};
    head = newNode;
}

// finds top two furthest cities
void printTwoFurthestCities(CityNode *head) {
    if (!head || !head->next) {
        cout << "Doesn't enough cities in a list" << endl;
        return;
    }

    CityNode *furthest1 = nullptr, *furthest2 = nullptr;
    double max1 = -1, max2 = -1;

    // traverse to find max distances

    for (CityNode *temp = head; temp != nullptr; temp = temp->next) {
        if (temp->distance > max1) {
            max2 = max1;
            furthest2 = furthest1;
            max1 = temp->distance;
            furthest1 = temp;
        } else if (temp->distance > max2) {
            max2 = temp->distance;
            furthest2 = temp;
        }
    }

    cout << "the most furthest cities:\n";
    cout << "1. " << furthest1->name << " (" << furthest1->distance << " km)\n";
    cout << "2. " << furthest2->name << " (" << furthest2->distance << " km)\n";
}

// frees allocated memory for list
void freeCitiesList(CityNode *&head) {
    while (head) {
        CityNode *temp = head;
        head = head->next;
        delete temp;
    }
}

// main program logic
int main() {
    CityNode *cities = nullptr;
    int n;

    cout << "Enter amount of cities: ";
    cin >> n;

    // loop to read all cities

    for (int i = 0; i < n; ++i) {
        string name;
        double distance;
        cout << "Name of city " << i + 1 << ": ";
        cin >> name;
        cout << "Distance to Kyiv (km): ";
        cin >> distance;
        addCity(cities, name, distance);
    }

    printTwoFurthestCities(cities);

    freeCitiesList(cities);
    return 0;
}
