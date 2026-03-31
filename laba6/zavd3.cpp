#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

struct QueueNode {
    int v;
    QueueNode *next;
} *first, *last, *newFirst, *newLast;

int main() {
    srand(time(0));
    first = 0;
    last = 0;
    newFirst = 0;
    newLast = 0;
    QueueNode *q;

    for (int i = 0; i < 5; i++) {
        QueueNode *c = new QueueNode;
        c->v = rand() % 20 + 1;
        c->next = 0;
        if (first == 0) {
            first = c;
            last = c;
        } else {
            last->next = c;
            last = c;
        }
    }

    cout << "Original queue: ";
    q = first;
    while (q != 0) {
        cout << q->v << " ";
        q = q->next;
    }
    cout << '\n';

    double product = 1.0;
    int count = 0;

    while (first != 0) {
        q = first;
        first = first->next;
        q->next = 0;
        if (newFirst == 0) {
            newFirst = q;
            newLast = q;
        } else {
            newLast->next = q;
            newLast = q;
        }

        product *= q->v;
        count++;

        if (q->v % 2 == 0) {
            QueueNode *c100 = new QueueNode;
            c100->v = 100;
            c100->next = 0;
            newLast->next = c100;
            newLast = c100;

            product *= 100;
            count++;
        }
    }

    cout << "New queue: ";
    q = newFirst;
    while (q != 0) {
        cout << q->v << " ";
        q = q->next;
    }
    cout << '\n';

    if (count > 0) {
        cout << "Geometric mean of new queue: " << pow(product, 1.0 / count) << '\n';
    }

    while (newFirst != 0) {
        q = newFirst;
        newFirst = newFirst->next;
        delete q;
    }

    return 0;
}
