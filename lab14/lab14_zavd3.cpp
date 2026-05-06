#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Student {
public:
    string name, group;
    double gpa;

    Student() : name(""), group(""), gpa(0.0) {
    }
};

void printStudent(const Student &s) {
    cout << s.name << " | " << s.group << " | " << s.gpa << "\n";
}


int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n1.Add new Student.\n2.Deleting through SNF.\n3.Sort by mark.\n"
                "4.Find by a group\n5.Students higher than N\n6.List of all\n0.Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Student s;
            cout << "SNF: ";
            getline(cin, s.name);
            cout << "Group: ";
            getline(cin, s.group);
            cout << "GPA: ";
            cin >> s.gpa;
            cin.ignore();
            students.push_back(s);
            cout << "Added.\n";
        } else if (choice == 2) {
            string name;
            cout << "SNF: ";
            getline(cin, name);
            auto it = remove_if(students.begin(), students.end(),
                                [&](const Student &s) {
                                    return s.name == name;
                                });
            if (it != students.end()) {
                students.erase(it, students.end());
                cout << "Deleted.\n";
            } else cout << "Not Found.\n";
        } else if (choice == 3) {
            sort(students.begin(), students.end(),
                 [](const Student &a, const Student &b) {
                     return a.gpa > b.gpa;
                 });
            cout << "Sorted.\n";
        } else if (choice == 4) {
            string group;
            cout << "Group: ";
            getline(cin, group);
            bool found = false;
            for (auto &s: students)
                if (s.group == group) {
                    printStudent(s);
                    found = true;
                }
            if (!found) cout << "Students not found.\n";
        } else if (choice == 5) {
            double threshold;
            cout << "Min mark: ";
            cin >> threshold;
            cin.ignore();
            bool found = false;
            for (auto &s: students)
                if (s.gpa > threshold) {
                    printStudent(s);
                    found = true;
                }
            if (!found) cout << "Students not found.\n";
        } else if (choice == 6) {
            if (students.empty()) cout << "No students found.\n";
            for (auto &s: students) printStudent(s);
        }
    } while (choice != 0);
    return 0;
}
