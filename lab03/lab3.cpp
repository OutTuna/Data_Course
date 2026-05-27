#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Worker {
    string fullName;
    string position;
    int salary{}, startYear{};
};

// стаж роботи
int experience(int startYear) {
    int currentYear = 2026;
    return currentYear - startYear;
}

int netSalary(double rawSalary) {
    return rawSalary * (1.0 - 0.33);
}

void task1() {
    int n;
    cout << "Enter number of workers" << endl;
    cin >> n;

    vector<Worker> workers(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter worker " << i + 1 << " name" << endl;
        cout << "Surname and Initials: ";
        cin.ignore();
        getline(cin, workers[i].fullName);
        cout << "Position: ";
        getline(cin, workers[i].position);
        cout << "Start Year: ";
        cin >> workers[i].startYear;
        cout << "Salary: ";
        cin >> workers[i].salary;
    }

    cout << "\nInfo about workers\n";
    for (int i = 0; i < n; i++) {
        cout << workers[i].fullName << endl;
        cout << "experience (years) : " << experience(workers[i].startYear) << endl;
        cout << "Salary (after 33%)" << netSalary(workers[i].salary) << endl;
    }
}

int main() {
    task1();
    return 0;
}
