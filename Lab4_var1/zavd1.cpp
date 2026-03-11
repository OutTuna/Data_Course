#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct Student {
    string NAME, GROUP;
    int SES[5];
};

double getAVG(const Student& s) {
    double sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += s.SES[i];
    }
    return sum / 5.0;
}

void printAllStudents(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". "<< arr[i].NAME << " | Group "<< arr[i].GROUP << "| Grades: ";
        for (int j = 0; j < 5; j++) {
            cout << arr[i].SES[j] << " ";
            cout << "| avg grade: " << getAVG(arr[i]) << "\n";
        }
    }
}

void printGoodStudents(Student arr[], int n) {
    bool found = false;
    cout << "Students with grade > 4.0\n";
    for (int i = 0; i < n; i++) {
        if (getAVG(arr[i]) > 4.0) {
            cout << "Surname: " << arr[i].NAME << ", Group:" << arr[i].GROUP << "\n";
            found = true;
        }
    }if (!found) {
        cout << "Didn't found any students with grade > 4.0\n";
    }
}

void printVowelStudents(Student arr[], int n) {
    cout << "Student's which surnames on vowels \n";
    string vowels = "AEIOUY";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (!arr[i].NAME.empty()) {
            if (vowels.find(arr[i].NAME)!= string::npos) {
                cout << "Surname: " << arr[i].NAME << ", Group: " << arr[i].GROUP<< "AVG : "<< getAVG(arr[i]) << "\n";
                found = true;
            }
        }
    }
    if (!found) {
        cout << "Didn't found any students.\n";
    }
}

void sortStudents(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (getAVG(arr[i]) > getAVG(arr[j+1])) {
                Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void deleteAfterMin(Student*& arr, int& n) {
    if (n<=1) {
        cout << "\n Not enought elements for delete";
        return;
    }
    int minAVG = getAVG(arr[0]), minIndex = 0;

    for (int i = 1; i < n; i++) {
        int currentAVG = getAVG(arr[i]);
        if (currentAVG < minAVG) {
            minAVG = currentAVG;
            minIndex = i;
        }
    }
    cout << "\n Min AVG. " << arr[minIndex].NAME << " (" << minAVG << ")\n";

    if (minIndex < n - 1) {
        int deleteIndex = minIndex + 1;
        cout << "Delete this student" << arr[deleteIndex].NAME << "\n";
        for (int i = deleteIndex; i < n; i++) {
            arr[i] = arr[i+1];
        }
        n--;
    }else {
        cout << "\n Non elements for delete, this is the smallest";
    }
}


int main () {
    int n;
    cout << "Enter (n) Students :";
    cin >> n;

    if (n <= 0) {
        cout << "Students must be bigger than 0";
    return 0;
    }

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter students data" << i+1 << "\n";
        cout << "Surname: ";
        cin.ignore();
        getline(cin,students[i].NAME);

        cout << "Group: ";
        cin >> students[i].GROUP;

        cout << "Enter Grades(5) through space: ";
        for (int j = 0; j < 5; j++) {
            cin >> students[i].SES[j];
        }
    }
        printGoodStudents(students, n);
        printVowelStudents(students, n);

        cout << "\n before sort \n";
        printVowelStudents(students, n);

        sortStudents(students, n);

        cout << "\n after sort \n";
        printAllStudents(students, n);
        deleteAfterMin(students, n);

        cout << "\n final after deleting \n";
        printAllStudents(students, n);

        delete[] students;


    return 0;
}