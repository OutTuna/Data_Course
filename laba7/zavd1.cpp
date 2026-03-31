#include <iostream>
#include <string>
using namespace std;

struct Weather {
    string date;
    float temp;
    Weather *prev;
    Weather *next;
} *first1, *last1, *first2, *last2;

int main() {
    int n1, n2;
    first1 = 0;
    last1 = 0;
    first2 = 0;
    last2 = 0;
    Weather *q;

    cout << "Enter number of days for the first month: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        Weather *c = new Weather;
        cout << "Enter date and temperature: ";
        cin >> c->date >> c->temp;
        c->next = 0;
        c->prev = 0;
        if (first1 == 0) {
            first1 = c;
            last1 = c;
        } else {
            last1->next = c;
            c->prev = last1;
            last1 = c;
        }
    }

    cout << "Enter number of days for the second month: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        Weather *c = new Weather;
        cout << "Enter date and temperature: ";
        cin >> c->date >> c->temp;
        c->next = 0;
        c->prev = 0;
        if (first2 == 0) {
            first2 = c;
            last2 = c;
        } else {
            last2->next = c;
            c->prev = last2;
            last2 = c;
        }
    }

    if (first1 != 0 && first2 != 0) {
        last1->next = first2;
        first2->prev = last1;
        last1 = last2;
    } else if (first1 == 0 && first2 != 0) {
        first1 = first2;
        last1 = last2;
    }

    cout << "\nMerged list of temperatures:\n";
    q = first1;
    float maxTemp = -9999.0;
    float minTemp = 9999.0;

    while (q != 0) {
        cout << q->date << " : " << q->temp << '\n';
        if (q->temp > maxTemp) maxTemp = q->temp;
        if (q->temp < minTemp) minTemp = q->temp;
        q = q->next;
    }

    cout << "\nMax temperature: " << maxTemp << '\n';
    cout << "Min temperature: " << minTemp << '\n';

    while (first1 != 0) {
        q = first1;
        first1 = first1->next;
        delete q;
    }

    return 0;
}
