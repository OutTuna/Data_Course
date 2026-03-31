#include <iostream>
#include <string>
using namespace std;

struct Team {
    string name;
    string city;
    int points;
    Team *next;
} *first, *last, *cityFirst, *cityLast, *pointsFirst, *pointsLast, *tempFirst, *tempLast;

int main() {
    int n;
    cout << "Enter number of teams: ";
    cin >> n;
    first = 0;
    last = 0;
    cityFirst = 0;
    cityLast = 0;
    pointsFirst = 0;
    pointsLast = 0;
    tempFirst = 0;
    tempLast = 0;
    Team *q;

    for (int i = 0; i < n; i++) {
        Team *c = new Team;
        cout << "Enter team name, city and points: ";
        cin >> c->name >> c->city >> c->points;
        c->next = 0;
        if (first == 0) {
            first = c;
            last = c;
        } else {
            last->next = c;
            last = c;
        }
    }

    cout << "\nOriginal queue:\n";
    q = first;
    while (q != 0) {
        cout << q->name << " from " << q->city << " (" << q->points << " points)\n";
        q = q->next;
    }
    cout << '\n';

    int targetPoints;
    cout << "Enter target points limit: ";
    cin >> targetPoints;

    string cities[100];
    int cityCount = 0;

    Team *leader = first;
    Team *outsider = first;

    while (first != 0) {
        q = first;
        first = first->next;
        q->next = 0;

        if (q->points > leader->points) {
            leader = q;
        }
        if (q->points < outsider->points) {
            outsider = q;
        }

        int found = 0;
        for (int i = 0; i < cityCount; i++) {
            if (cities[i] == q->city) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            cities[cityCount] = q->city;
            cityCount++;

            Team *cityNode = new Team;
            cityNode->name = q->name;
            cityNode->city = q->city;
            cityNode->points = q->points;
            cityNode->next = 0;
            if (cityFirst == 0) {
                cityFirst = cityNode;
                cityLast = cityNode;
            } else {
                cityLast->next = cityNode;
                cityLast = cityNode;
            }
        }

        if (q->points > targetPoints) {
            Team *pointsNode = new Team;
            pointsNode->name = q->name;
            pointsNode->city = q->city;
            pointsNode->points = q->points;
            pointsNode->next = 0;
            if (pointsFirst == 0) {
                pointsFirst = pointsNode;
                pointsLast = pointsNode;
            } else {
                pointsLast->next = pointsNode;
                pointsLast = pointsNode;
            }
        }

        if (tempFirst == 0) {
            tempFirst = q;
            tempLast = q;
        } else {
            tempLast->next = q;
            tempLast = q;
        }
    }

    first = tempFirst;
    last = tempLast;

    cout << "\nLeader: " << leader->name << " (" << leader->points << ")\n";
    cout << "Outsider: " << outsider->name << " (" << outsider->points << ")\n";

    cout << "\nUnique cities queue:\n";
    q = cityFirst;
    while (q != 0) {
        cout << q->name << " from " << q->city << '\n';
        q = q->next;
    }

    cout << "\nTeams with more than " << targetPoints << " points:\n";
    q = pointsFirst;
    while (q != 0) {
        cout << q->name << " (" << q->points << ")\n";
        q = q->next;
    }

    cout << "\nRestored original queue:\n";
    q = first;
    while (q != 0) {
        cout << q->name << " from " << q->city << " (" << q->points << " points)\n";
        q = q->next;
    }

    while (first != 0) {
        q = first;
        first = first->next;
        delete q;
    }
    while (cityFirst != 0) {
        q = cityFirst;
        cityFirst = cityFirst->next;
        delete q;
    }
    while (pointsFirst != 0) {
        q = pointsFirst;
        pointsFirst = pointsFirst->next;
        delete q;
    }

    return 0;
}
