#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

// adds element to the beginning
void pushFront(Node *&head, int value) {
    Node *newNode = new Node{value, head};
    head = newNode;
}

// adds element to the end
void pushBack(Node *&head, int value) {
    Node *newNode = new Node{value, nullptr};
    // check if list is empty
    if (!head) {
        head = newNode;
        return;
    }
    Node *temp = head;
    // traverse to the last node
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// inserts after specified node
void insertAfter(Node *prevNode, int value) {
    if (!prevNode) return;
    Node *newNode = new Node{value, prevNode->next};
    prevNode->next = newNode;
}

// calculates list average
double getAverage(Node *head) {
    if (!head) return 0;
    int sum = 0, count = 0;
    for (Node *temp = head; temp != nullptr; temp = temp->next) {
        sum += temp->data;
        count++;
    }
    return static_cast<double>(sum) / count;
}

// removes first even number
void deleteFirstEven(Node *&head) {
    if (!head) return;
    // if first element is an even
    // check if the first element is even
    if (head->data % 2 == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    // checking if next element is an even
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

// prints list elements to screen
void printList(Node const *head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// frees allocated memory for list
void freeList(Node *&head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// main program logic
int main() {
    Node *list = nullptr;
    int val1, val2, val3, val4;

    cout << "enter 4 numbers:\n";
    cin >> val1 >> val2 >> val3 >> val4;

    // populate the list

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
