#include <iostream>
#include <string>
using namespace std;

struct Course {
    string name;
    int hours;
    int attendees;
    Course *prev;
    Course *next;
} *first, *last, *popFirst, *popLast, *regFirst, *regLast;

int main() {
    int n;
    first = 0;
    last = 0;
    popFirst = 0;
    popLast = 0;
    regFirst = 0;
    regLast = 0;
    Course *q;

    cout << "Enter number of courses: ";
    cin >> n;

    float totalAttendees = 0;

    for (int i = 0; i < n; i++) {
        Course *c = new Course;
        cout << "Enter course name, hours and number of attendees: ";
        cin >> c->name >> c->hours >> c->attendees;
        c->next = 0;
        c->prev = 0;
        totalAttendees += c->attendees;

        if (first == 0) {
            first = c;
            last = c;
        } else {
            last->next = c;
            c->prev = last;
            last = c;
        }
    }

    float avgAttendees = 0;
    if (n > 0) avgAttendees = totalAttendees / n;
    cout << "\nAverage attendees: " << avgAttendees << "\n\n";

    while (first != 0) {
        q = first;
        first = first->next;
        q->next = 0;
        q->prev = 0;

        if (q->attendees > avgAttendees) {
            if (popFirst == 0) {
                popFirst = q;
                popLast = q;
            } else {
                popLast->next = q;
                q->prev = popLast;
                popLast = q;
            }
        } else {
            if (regFirst == 0) {
                regFirst = q;
                regLast = q;
            } else {
                regLast->next = q;
                q->prev = regLast;
                regLast = q;
            }
        }
    }

    cout << "Popular courses (forward):\n";
    q = popFirst;
    while (q != 0) {
        cout << q->name << " (" << q->attendees << ")\n";
        q = q->next;
    }

    cout << "\nPopular courses (backward):\n";
    q = popLast;
    while (q != 0) {
        cout << q->name << " (" << q->attendees << ")\n";
        q = q->prev;
    }

    cout << "\nRegular courses (forward):\n";
    q = regFirst;
    while (q != 0) {
        cout << q->name << " (" << q->attendees << ")\n";
        q = q->next;
    }

    cout << "\nRegular courses (backward):\n";
    q = regLast;
    while (q != 0) {
        cout << q->name << " (" << q->attendees << ")\n";
        q = q->prev;
    }

    while (popFirst != 0) {
        q = popFirst;
        popFirst = popFirst->next;
        delete q;
    }
    while (regFirst != 0) {
        q = regFirst;
        regFirst = regFirst->next;
        delete q;
    }

    return 0;
}
