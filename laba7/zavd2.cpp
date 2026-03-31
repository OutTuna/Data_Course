#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string surname;
    string department;
    float salary;
    Employee *prev;
    Employee *next;
} *first, *last, *highFirst, *highLast, *lowFirst, *lowLast;

int main() {
    int n;
    first = 0;
    last = 0;
    highFirst = 0;
    highLast = 0;
    lowFirst = 0;
    lowLast = 0;
    Employee *q;

    cout << "Enter number of employees: ";
    cin >> n;

    float totalSalary = 0;

    for (int i = 0; i < n; i++) {
        Employee *c = new Employee;
        cout << "Enter surname, department and salary: ";
        cin >> c->surname >> c->department >> c->salary;
        c->next = 0;
        c->prev = 0;
        totalSalary += c->salary;

        if (first == 0) {
            first = c;
            last = c;
        } else {
            last->next = c;
            c->prev = last;
            last = c;
        }
    }

    float avgSalary = 0;
    if (n > 0) avgSalary = totalSalary / n;
    cout << "\nAverage salary: " << avgSalary << "\n\n";

    while (first != 0) {
        q = first;
        first = first->next;
        q->next = 0;
        q->prev = 0;

        if (q->salary > avgSalary) {
            if (highFirst == 0) {
                highFirst = q;
                highLast = q;
            } else {
                highLast->next = q;
                q->prev = highLast;
                highLast = q;
            }
        } else {
            if (lowFirst == 0) {
                lowFirst = q;
                lowLast = q;
            } else {
                lowLast->next = q;
                q->prev = lowLast;
                lowLast = q;
            }
        }
    }

    cout << "High salary list (forward):\n";
    q = highFirst;
    while (q != 0) {
        cout << q->surname << " (" << q->salary << ")\n";
        q = q->next;
    }

    cout << "\nHigh salary list (backward):\n";
    q = highLast;
    while (q != 0) {
        cout << q->surname << " (" << q->salary << ")\n";
        q = q->prev;
    }

    cout << "\nLow/Average salary list (forward):\n";
    q = lowFirst;
    while (q != 0) {
        cout << q->surname << " (" << q->salary << ")\n";
        q = q->next;
    }

    cout << "\nLow/Average salary list (backward):\n";
    q = lowLast;
    while (q != 0) {
        cout << q->surname << " (" << q->salary << ")\n";
        q = q->prev;
    }

    Employee *newEmp = new Employee;
    cout << "\nEnter new employee for high salary list (surname, department, salary): ";
    cin >> newEmp->surname >> newEmp->department >> newEmp->salary;
    newEmp->next = 0;
    newEmp->prev = 0;

    if (highFirst == 0) {
        highFirst = newEmp;
        highLast = newEmp;
    } else {
        highLast->next = newEmp;
        newEmp->prev = highLast;
        highLast = newEmp;
    }

    cout << "\nUpdated High salary list (forward):\n";
    q = highFirst;
    while (q != 0) {
        cout << q->surname << " (" << q->salary << ")\n";
        q = q->next;
    }

    while (highFirst != 0) {
        q = highFirst;
        highFirst = highFirst->next;
        delete q;
    }
    while (lowFirst != 0) {
        q = lowFirst;
        lowFirst = lowFirst->next;
        delete q;
    }

    return 0;
}
