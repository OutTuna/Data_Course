#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
    Book *prev;
    Book *next;
};

// create an node, to create a book
Book *createBook(const string &title, const string &author, int year) {
    Book *node = new Book;
    node->title = title;
    node->author = author;
    node->year = year;
    node->prev = nullptr;
    node->next = nullptr;
    return node;
}

// adding book to end of list
void pushBack(Book *&head, Book *&tail, const string &title, const string &author, int year) {
    Book *node = createBook(title, author, year);
    if (!tail) {
        head = tail = node;
    } else {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
}

// list from start to end
void printForward(Book *head) {
    Book *cur = head;
    while (cur) {
        cout << cur->title << " | " << cur->author << " | " << cur->year << "\n";
        cur = cur->next;
    }
}

// from last to start
void printBackward(Book *tail) {
    Book *cur = tail;
    while (cur) {
        cout << cur->title << " | " << cur->author << " | " << cur->year << "\n";
        cur = cur->prev;
    }
}

// connect to last
void mergeLists(Book *&head1, Book *&tail1, Book *&head2, Book *&tail2) {
    if (!head2) return;
    if (!tail1) {
        head1 = head2;
        tail1 = tail2;
    } else {
        tail1->next = head2;
        head2->prev = tail1;
        tail1 = tail2;
    }
    head2 = tail2 = nullptr;
}

// free all in list
void freeList(Book *&head) {
    while (head) {
        Book *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Book *head1 = nullptr;
    Book *tail1 = nullptr;
    Book *head2 = nullptr;
    Book *tail2 = nullptr;

    int n, m;
    cout << "n: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string t, a;
        int y;
        cout << "Title: ";
        getline(cin, t);
        cout << "Author: ";
        getline(cin, a);
        cout << "Year: ";
        cin >> y;
        cin.ignore();
        pushBack(head1, tail1, t, a, y);
    }

    cout << "m: ";
    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++) {
        string t, a;
        int y;
        cout << "Title: ";
        getline(cin, t);
        cout << "Author: ";
        getline(cin, a);
        cout << "Year: ";
        cin >> y;
        cin.ignore();
        pushBack(head2, tail2, t, a, y);
    }

    cout << "\nList 1 forward:\n";
    printForward(head1);
    cout << "List 1 backward:\n";
    printBackward(tail1);
    cout << "\nList 2 forward:\n";
    printForward(head2);
    cout << "List 2 backward:\n";
    printBackward(tail2);

    mergeLists(head1, tail1, head2, tail2);
    cout << "\nMerged list:\n";
    printForward(head1);

    freeList(head1);
    return 0;
}
