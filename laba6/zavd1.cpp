#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct StackNode {
    float v;
    StackNode *next;
} *first, *newFirst;

int main() {
    srand(time(0));
    first = 0;
    newFirst = 0;
    StackNode *q;

    for (int i = 0; i < 10; i++) {
        StackNode *c = new StackNode;
        c->v = -6.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (11.0 - (-6.0))));
        c->next = first;
        first = c;
    }

    cout << "Generated stack: ";
    q = first;
    while (q != 0) {
        cout << q->v << " ";
        q = q->next;
    }
    cout << '\n';

    float limit;
    cout << "Enter limit value for deletion: ";
    cin >> limit;

    while (first != 0) {
        q = first;
        first = first->next;
        if (q->v >= limit) {
            q->next = newFirst;
            newFirst = q;
        } else {
            delete q;
        }
    }

    cout << "New stack: ";
    float sum = 0;
    int count = 0;
    q = newFirst;
    while (q != 0) {
        cout << q->v << " ";
        sum += q->v;
        count++;
        q = q->next;
    }
    cout << '\n';

    if (count > 0) {
        cout << "Average of new stack: " << sum / count << '\n';
    }

    while (newFirst != 0) {
        q = newFirst;
        newFirst = newFirst->next;
        delete q;
    }

    return 0;
}
