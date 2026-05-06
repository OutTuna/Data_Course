#include <iostream>
#include <string>

using namespace std;

struct Student {
    string lastName;
    double exam1, exam2, exam3, average;
};

struct Product {
    string name;
    double protein, fat, carb, calories;
};

void calculateAverages(Student arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i].average = (arr[i].exam1 + arr[i].exam2 + arr[i].exam3) / 3.0;
}

void findMaxAverages(Student arr[], int n) {
    double maxAvg = arr[0].average;
    for (int i = 1; i < n; i++)
        if (arr[i].average > maxAvg)
            maxAvg = arr[i].average;

    int count = 0;
    cout << "Max average indices: ";
    for (int i = 0; i < n; i++)
        if (arr[i].average == maxAvg) {
            cout << i << " ";
            count++;
        }
    cout << "\nCount: " << count << "\n";
}

void sortStudents(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].average > arr[j + 1].average)
                swap(arr[j], arr[j + 1]);
}

void binarySearchStudents(Student arr[], int n, double target) {
    int lo = 0, hi = n - 1;
    bool found = false;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid].average == target) {
            found = true;
            int i = mid;
            while (i >= 0 && arr[i].average == target) {
                cout << arr[i].lastName << " ";
                i--;
            }
            i = mid + 1;
            while (i < n && arr[i].average == target) {
                cout << arr[i].lastName << " ";
                i++;
            }
            cout << "\n";
            break;
        }
        if (arr[mid].average < target) lo = mid + 1;
        else hi = mid - 1;
    }
    if (!found) cout << "Not found\n";
}

void calculateCalories(Product arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i].calories = 4 * arr[i].protein + 9 * arr[i].fat + 4 * arr[i].carb;
}

void findMaxCalories(Product arr[], int n) {
    double maxCal = arr[0].calories;
    for (int i = 1; i < n; i++)
        if (arr[i].calories > maxCal)
            maxCal = arr[i].calories;

    int count = 0;
    cout << "Max calories indices: ";
    for (int i = 0; i < n; i++)
        if (arr[i].calories == maxCal) {
            cout << i << " ";
            count++;
        }
    cout << "\nCount: " << count << "\n";
}

void findCaloriesInRange(Product arr[], int n, double A, double B) {
    bool found = false;
    for (int i = 0; i < n; i++)
        if (arr[i].calories >= A && arr[i].calories <= B) {
            cout << arr[i].name << " ";
            found = true;
        }
    cout << "\n";
    if (!found) cout << "Not found\n";
}

void printStudents(Student arr[], int n) {
    cout << "Name\t\tExam1\tExam2\tExam3\tAvg\n";
    cout << string(50, '-') << "\n";
    for (int i = 0; i < n; i++)
        cout << arr[i].lastName << "\t\t"
                << arr[i].exam1 << "\t"
                << arr[i].exam2 << "\t"
                << arr[i].exam3 << "\t"
                << arr[i].average << "\n";
}

void printProducts(Product arr[], int n) {
    cout << "Name\t\tProtein\tFat\tCarb\tCalories\n";
    cout << string(55, '-') << "\n";
    for (int i = 0; i < n; i++)
        cout << arr[i].name << "\t\t"
                << arr[i].protein << "\t"
                << arr[i].fat << "\t"
                << arr[i].carb << "\t"
                << arr[i].calories << "\n";
}

int main() {
    int n1;
    cout << "Enter number of students: ";
    cin >> n1;

    Student *students = new Student[n1];
    for (int i = 0; i < n1; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << " Last name: ";
        cin >> students[i].lastName;
        cout << " Exam 1: ";
        cin >> students[i].exam1;
        cout << " Exam 2: ";
        cin >> students[i].exam2;
        cout << " Exam 3: ";
        cin >> students[i].exam3;
        students[i].average = 0;
    }

    calculateAverages(students, n1);
    cout << "\n";
    findMaxAverages(students, n1);

    sortStudents(students, n1);
    cout << "\nSorted students:\n";
    printStudents(students, n1);

    double targetAvg;
    cout << "\nEnter average to search: ";
    cin >> targetAvg;
    cout << "Found: ";
    binarySearchStudents(students, n1, targetAvg);
    delete[] students;

    int n2;
    cout << "\nEnter number of products: ";
    cin >> n2;

    Product *products = new Product[n2];
    for (int i = 0; i < n2; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        cout << " Name: ";
        cin >> products[i].name;
        cout << " Protein: ";
        cin >> products[i].protein;
        cout << " Fat: ";
        cin >> products[i].fat;
        cout << " Carb: ";
        cin >> products[i].carb;
        products[i].calories = 0;
    }

    calculateCalories(products, n2);
    cout << "\n";
    findMaxCalories(products, n2);
    cout << "\nProducts:\n";
    printProducts(products, n2);

    double A, B;
    cout << "\nEnter calorie range (A B): ";
    cin >> A >> B;
    cout << "In range [" << A << "; " << B << "]: ";
    findCaloriesInRange(products, n2, A, B);
    delete[] products;

    return 0;
}
