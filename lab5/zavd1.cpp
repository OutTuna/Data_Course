#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

// adding on start
void pushFront(Node *&head, int value) {
    Node *newNode = new Node{value, head};
    head = newNode;
}

// adding on end
void pushBack(Node *&head, int value) {
    Node *newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// enter in middle
void insertAfter(Node *prevNode, int value) {
    if (!prevNode) return;
    Node *newNode = new Node{value, prevNode->next};
    prevNode->next = newNode;
}

// avg
double getAverage(Node *head) {
    if (!head) return 0;
    int sum = 0, count = 0;
    for (Node *temp = head; temp != nullptr; temp = temp->next) {
        sum += temp->data;
        count++;
    }
    return static_cast<double>(sum) / count;
}

// deleting first parne (evens)
void deleteFirstEven(Node *&head) {
    if (!head) return;
    // if first element is a even
    if (head->data % 2 == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    // checking if next element is a even
    Node *current = head;
    while (current->next && current->next->data % 2 != 0) {
        current = current->next;
    }

    if (current->next) {
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

// user-enter
void printList(Node *head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// clearing space
void freeList(Node *&head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node *list = nullptr;
    int val1, val2, val3, val4;

    cout << "enter 4 numbers:\n";
    cin >> val1 >> val2 >> val3 >> val4;

    pushFront(list, val1);
    pushBack(list, val2);
    insertAfter(list, val3);
    pushFront(list, val4);

    cout << "List: ";
    printList(list);

    cout << "avg: " << getAverage(list) << endl;

    deleteFirstEven(list);

    cout << "list after deleting first even: ";
    printList(list);

    freeList(list);
    return 0;
}
