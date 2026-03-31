#include <iostream>
using namespace std;

struct StackNode {
    int grade;
    StackNode *next;
} *first;

int main() {
    int n;
    first = 0;
    StackNode *q;

    cout << "Enter number of grades: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        StackNode *c = new StackNode;
        cout << "Enter grade: ";
        cin >> c->grade;
        c->next = first;
        first = c;
    }

    cout << "\nGrades in stack:\n";
    float sum = 0;
    int count = 0;
    q = first;

    while (q != 0) {
        cout << q->grade << " ";
        sum += q->grade;
        count++;
        q = q->next;
    }
    cout << '\n';

    if (count > 0) {
        cout << "Average grade: " << sum / count << '\n';
    }

    cout << "\nDeleting stack elements...\n";
    while (first != 0) {
        q = first;
        first = first->next;
        delete q;
    }
    cout << "Stack is empty.\n";

    return 0;
}
