#include <iostream>
#include <string>
using namespace std;

int main() {
    string names[] = {
        "Sanitarka", "Medsestra", "Likar", "Zav.aptekoy", "Zav.viddilennyam", "Holovnyy likar", "Zav.hosp.",
        "Zav.likarneyu"
    };
    int A[] = {1, 6, 8, 9, 2, 12, 13, 3};
    int B[] = {1, 5, 5, 5, 1, 5, 5, 1};
    int count[] = {7, 10, 10, 1, 3, 1, 1, 1};
    int n = 8;
    int target = 380000;

    int bestBase = 0;
    int bestTotal = 0;

    for (int base = 1; base <= target; base++) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += count[i] * base * A[i] / B[i];
        }
        if (total <= target) {
            bestBase = base;
            bestTotal = total;
        } else {
            break;
        }
    }

    cout << "Base salary (sanitarka): " << bestBase << " UAH\n";
    cout << "Position        | Coef | Salary | Count | Total \n";
    cout << "-------------------------------------------------";
    for (int i = 0; i < n; i++) {
        int salary = bestBase * A[i] / B[i];
        int total = salary * count[i];
        cout << names[i];
        for (int s = names[i].size(); s < 21; s++) cout << " ";
        cout << "| " << A[i] << "/" << B[i];
        for (int s = to_string(A[i]).size() + to_string(B[i]).size() + 1; s < 6; s++) cout << " ";
        cout << "| " << salary;
        for (int s = to_string(salary).size(); s < 8; s++) cout << " ";
        cout << "| " << count[i];
        for (int s = to_string(count[i]).size(); s < 6; s++) cout << " ";
        cout << "| " << total << endl;
    }

    cout << "Total fund: " << bestTotal << " UAH (target: " << target << ")\n";


    return 0;
}
