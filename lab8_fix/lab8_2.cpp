#include <iostream>
#include <string>
using namespace std;

struct Route {
    int number;
    string destination;
    int passengers;
    Route *next;
};

struct Queue {
    Route *front;
    Route *rear;
};

// initialize empty queue
void initQueue(Queue &q) {
    q.front = q.rear = nullptr;
}

// add route to the end of queue
void enqueue(Queue &q, int number, const string &dest, int passengers) {
    Route *node = new Route;
    node->number = number;
    node->destination = dest;
    node->passengers = passengers;
    node->next = nullptr;
    if (!q.rear) {
        q.front = q.rear = node;
    } else {
        q.rear->next = node;
        q.rear = node;
    }
}

// remove first route from queue
void dequeue(Queue &q) {
    if (!q.front) return;
    Route *tmp = q.front;
    q.front = q.front->next;
    if (!q.front) q.rear = nullptr;
    delete tmp;
}

// attach second queue to the end of first
void mergeQueues(Queue &q1, Queue &q2) {
    if (!q2.front) return;
    if (!q1.rear) {
        q1 = q2;
    } else {
        q1.rear->next = q2.front;
        q1.rear = q2.rear;
    }
    q2.front = q2.rear = nullptr;
}

// print routes with passengers above threshold
void printRoutesAbove(Queue &q, int threshold) {
    Route *cur = q.front;
    while (cur) {
        if (cur->passengers > threshold)
            cout << cur->number << " | " << cur->destination << " | " << cur->passengers << "\n";
        cur = cur->next;
    }
}

// free all queue memory
void freeQueue(Queue &q) {
    while (q.front) dequeue(q);
}

int main() {
    Queue q1, q2;
    initQueue(q1);
    initQueue(q2);

    enqueue(q1, 101, "Kyiv", 45);
    enqueue(q1, 202, "Lviv", 12);
    enqueue(q2, 303, "Odesa", 60);
    enqueue(q2, 404, "Kharkiv", 30);

    mergeQueues(q1, q2);

    int threshold;
    cout << "Passenger threshold: ";
    cin >> threshold;
    cout << "Routes above " << threshold << ":\n";
    printRoutesAbove(q1, threshold);

    cout << "\nDequeuing first two routes...\n";
    dequeue(q1);
    dequeue(q1);

    freeQueue(q1);
    return 0;
}
