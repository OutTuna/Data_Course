#include <iostream>
#include <string>

using namespace std;

enum Faculty { IT, ECONOMICS, LAW, MANAGEMENT };

struct Student {
    string surname;
    int course, averageGrade;
    Faculty faculty;
};

string getFacultyName(Faculty f) {
    switch (f) {
        case IT: return "IT";
        case ECONOMICS: return "Economics";
        case LAW: return "Lawyer";
        case MANAGEMENT: return "Management";
        default: return "unknown";
    }
}

int main() {
    int size = 5;
    Student students[size];
    double totalGrade = 0;

    cout << "Entering student to faculty\n";
    for (int i = 0; i < size; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Surname: ";
        cin >> students[i].surname;
        cout << "Course: ";
        cin >> students[i].course;
        cout << "Avg grade: ";
        cin >> students[i].averageGrade;

        int facChoice;
        cout << "Faculty Code (0-3): ";
        cin >> facChoice;
        students[i].faculty = static_cast<Faculty>(facChoice);

        totalGrade += students[i].averageGrade;
    }

    Faculty searchFaculty = IT;
    cout << "\n--- Student of " << getFacultyName(searchFaculty) << " ---" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (students[i].faculty == searchFaculty) {
            cout << students[i].surname << ", " << students[i].course << " course, grade: " << students[i].averageGrade << endl;
            found = true;
        }
    }
    if (!found) cout << "Student not found." << endl;

    cout << "\nAVG all group: " << totalGrade / size << endl;

    return 0;
}