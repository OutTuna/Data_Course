#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Book {
    string title;
    string author;
    string genre;
    double price;
    int popularity;
    string arrivalDate;
    bool sold;
};

void addBook(vector<Book> &store) {
    Book b;
    cout << "Title: ";
    cin.ignore();
    getline(cin, b.title);
    cout << "Author: ";
    getline(cin, b.author);
    cout << "Genre: ";
    getline(cin, b.genre);
    cout << "Price: ";
    cin >> b.price;
    cout << "Popularity (1-100): ";
    cin >> b.popularity;
    cout << "Arrival date (YYYY-MM-DD): ";
    cin >> b.arrivalDate;
    b.sold = false;
    store.push_back(b);
    cout << "Book added.\n";
}

void removeSold(vector<Book> &store) {
    int before = store.size();
    store.erase(remove_if(store.begin(), store.end(),
                               [](const Book &b) { return b.sold; }), store.end());
    cout << "Removed " << (before - (int) store.size()) << " sold book(s).\n";
}

void markSold(vector<Book> &store) {
    string title;
    cin.ignore();
    cout << "Enter title to mark as sold: ";
    getline(cin, title);
    for (auto &b: store) {
        if (b.title == title) {
            b.sold = true;
            cout << "Marked as sold.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void sortBooks(vector<Book> &store) {
    cout << "Sort by: 1-Price  2-Popularity  3-Arrival date\nChoice: ";
    int c;
    cin >> c;
    if (c == 1)
        sort(store.begin(), store.end(), [](const Book &a, const Book &b) { return a.price < b.price; });
    else if (c == 2)
        sort(store.begin(), store.end(), [](const Book &a, const Book &b) { return a.popularity > b.popularity; });
    else if (c == 3)
        sort(store.begin(), store.end(),
                  [](const Book &a, const Book &b) { return a.arrivalDate < b.arrivalDate; });
    cout << "Sorted.\n";
}

void filterBooks(const vector<Book> &store) {
    cout << "Filter by: 1-Genre  2-Price range\nChoice: ";
    int c;
    cin >> c;
    if (c == 1) {
        string genre;
        cin.ignore();
        cout << "Genre: ";
        getline(cin, genre);
        for (const auto &b: store)
            if (b.genre == genre)
                cout << left << setw(30) << b.title << " $" << b.price << "\n";
    } else if (c == 2) {
        double lo, hi;
        cout << "Min price: ";
        cin >> lo;
        cout << "Max price: ";
        cin >> hi;
        for (const auto &b: store)
            if (b.price >= lo && b.price <= hi)
                cout << left << setw(30) << b.title << " $" << b.price << "\n";
    }
}

void searchBook(const vector<Book> &store) {
    string title;
    cin.ignore();
    cout << "Enter title: ";
    getline(cin, title);
    for (const auto &b: store)
        if (b.title.find(title) != string::npos)
            cout << b.title << " | " << b.author << " | " << b.genre
                    << " | $" << b.price << " | Pop:" << b.popularity
                    << " | " << b.arrivalDate << " | " << (b.sold ? "SOLD" : "available") << "\n";
}

void printAll(const vector<Book> &store) {
    cout << left << setw(30) << "Title" << setw(20) << "Author"
            << setw(15) << "Genre" << setw(8) << "Price"
            << setw(6) << "Pop" << setw(12) << "Arrival" << "Sold\n";
    cout << string(95, '-') << "\n";
    for (const auto &b: store)
        cout << setw(30) << b.title << setw(20) << b.author
                << setw(15) << b.genre << setw(8) << b.price
                << setw(6) << b.popularity << setw(12) << b.arrivalDate
                << (b.sold ? "yes" : "no") << "\n";
}

int main() {
    vector<Book> store;
    int choice;
    do {
        cout << "\n===== BOOKSTORE MENU =====\n"
                << "1. Add book\n2. Mark book as sold\n3. Remove sold books\n"
                << "4. Sort books\n5. Filter books\n6. Search book\n7. Print all\n0. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addBook(store);
                break;
            case 2: markSold(store);
                break;
            case 3: removeSold(store);
                break;
            case 4: sortBooks(store);
                break;
            case 5: filterBooks(store);
                break;
            case 6: searchBook(store);
                break;
            case 7: printAll(store);
                break;
            case 0: cout << "Goodbye.\n";
                break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
