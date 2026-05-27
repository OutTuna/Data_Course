#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>

using namespace std;

struct Student {
    string NAME;
    string GROUP;
    int SES[5]{};
};

double getAVG(const Student &s) {
    double sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += s.SES[i];
    }
    return sum / 5.0;
}

void printAllStudents(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << arr[i].NAME << " | Group " << arr[i].GROUP << " | Grades: ";
        for (int j = 0; j < 5; j++) {
            cout << arr[i].SES[j] << " ";
        }
        cout << "| avg grade: " << getAVG(arr[i]) << "\n";
    }
}

void printGoodStudents(Student arr[], int n) {
    bool found = false;
    cout << "=== Students with grade > 4.0 ===\n";
    for (int i = 0; i < n; i++) {
        if (getAVG(arr[i]) > 4.0) {
            cout << "Surname: " << arr[i].NAME << ", Group: " << arr[i].GROUP << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Didn't find any students with grade > 4.0\n";
    }
    cout << "\n";
}

//remake
void printVowelStudents(Student arr[], int n) {
    cout << "=== Students whose surnames start with vowels ===\n";
    string vowels = "AEIOUY";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (!arr[i].NAME.empty() && vowels.find(toupper(arr[i].NAME[0])) != string::npos) {
            cout << "Surname: " << arr[i].NAME << ", Group: " << arr[i].GROUP << " | AVG : " << getAVG(arr[i]) << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Didn't find any students.\n";
    }
    cout << "\n";
}

void sortStudents(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (getAVG(arr[j]) > getAVG(arr[j + 1])) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void deleteAfterMin(Student *&arr, int &n) {
    if (n <= 1) {
        cout << "Not enough elements to delete\n";
        return;
    }

    double minAVG = getAVG(arr[0]);
    int minIndex = 0;

    for (int i = 1; i < n; i++) {
        double currentAVG = getAVG(arr[i]);
        if (currentAVG < minAVG) {
            minAVG = currentAVG;
            minIndex = i;
        }
    }
    cout << "\nMin AVG: " << arr[minIndex].NAME << " (" << minAVG << ")\n";

    if (minIndex < n - 1) {
        int deleteIndex = minIndex + 1;
        cout << "Deleting this student: " << arr[deleteIndex].NAME << "\n\n";

        for (int i = deleteIndex; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    } else {
        cout << "No elements to delete, the element with minimum AVG is the last one.\n\n";
    }
}

void clearConsole() {
    system("clear");
}

int main() {
    int n;
    cout << "Enter (n) Students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Students count must be greater than 0";
        return 0;
    }

    Student *students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter students data " << i + 1 << " ---\n";
        cout << "Surname: ";
        getline(cin >> ws, students[i].NAME);

        cout << "Group: ";
        cin >> students[i].GROUP;

        cout << "Enter Grades(5) separated by space: ";
        for (int j = 0; j < 5; j++) {
            cin >> students[i].SES[j];
        }
    }

    clearConsole();

    printGoodStudents(students, n);
    printVowelStudents(students, n);

    cout << "=== All Students (Before Sort) ===\n";
    printAllStudents(students, n);

    sortStudents(students, n);

    cout << "\n=== All Students (After Sort by AVG) ===\n";
    printAllStudents(students, n);

    deleteAfterMin(students, n);

    cout << "=== Final list (After Deleting) ===\n";
    printAllStudents(students, n);

    delete[] students;

    return 0;
}
