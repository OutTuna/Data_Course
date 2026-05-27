#include <iostream>
#include <list>

using namespace std;

int countUnique(list<int> lst) {
    lst.sort();
    lst.unique();
    return (int) lst.size();
}

int main() {
    list<int> lst1;
    cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        lst1.push_back(x);
    }

    cout << "List 1: ";
    for (auto it = lst1.begin(); it != lst1.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    srand((unsigned) time(nullptr));
    list<int> lst2;
    for (int i = 0; i < 10; i++)
        lst2.push_back(rand() % 100 + 1);
    lst2.sort();

    cout << "List 2 (random ascending): ";
    for (auto it = lst2.begin(); it != lst2.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    lst1.sort(greater<int>());
    lst2.sort(greater<int>());
    lst1.merge(lst2, greater<int>());

    cout << "Merged (descending): ";
    for (auto it = lst1.begin(); it != lst1.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    cout << "Unique elements count: " << countUnique(lst1) << "\n";

    return 0;
}
