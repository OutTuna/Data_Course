#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
    string surname;
    int group{}, grades[4]{};
    double avg{};
};

vector<Student> calcAvg(vector<Student> arr) {
    for (auto &s: arr) {
        int sum = 0;
        for (int i = 0; i < 4; i++)
            sum += s.grades[i];
        s.avg = sum / 4.0;
    }
    return arr;
}

vector<Student> bubbleSortByAvg(vector<Student> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].avg > arr[j + 1].avg)
                swap(arr[j], arr[j + 1]);
    return arr;
}

vector<Student> insertSortByGroup(vector<Student> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].group < key.group) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

//string printArray(const vector<Student> &arr), need's test, idk why not work
void printArray(const vector<Student> &arr) {
    cout << left << setw(15) << "Surname" << setw(8) << "Group"
            << setw(20) << "Grade" << setw(8) << "Avg" << "\n";
    cout << string(55, '-') << "\n";
    for (const auto &s: arr) {
        cout << setw(15) << s.surname << setw(8) << s.group << "[";
        for (int i = 0; i < 4; i++) {
            cout << s.grades[i];
            if (i < 3) cout << ", ";
        }
        cout << "]" << setw(9) << " " << fixed << setprecision(2) << s.avg << "\n";
    }
}

vector<int> binSearchByAvg(const vector<Student> &arr, double target) {
    vector<int> result;
    int lo = 0, hi = (int) arr.size() - 1, mid = -1;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (arr[mid].avg == target) break;
        else if (arr[mid].avg < target) lo = mid + 1;
        else hi = mid - 1;
    }

    if (lo > hi) return result;

    result.push_back(mid);
    int left = mid - 1;
    while (left >= 0 && arr[left].avg == target)
        result.push_back(left--);
    int right = mid + 1;
    while (right < (int) arr.size() && arr[right].avg == target)
        result.push_back(right++);

    return result;
}

int main() {
    int n;
    cout << "Enter number of Students: ";
    cin >> n;
    cin.ignore();

    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << " Surname: ";
        getline(cin, students[i].surname);
        cout << " Group: ";
        cin >> students[i].group;
        cout << " Grades (4 values): ";
        for (int j = 0; j < 4; j++) {
            cin >> students[i].grades[j];
            cin.ignore();
        }
    }

    const auto withAvg = calcAvg(students);
    const auto sortedByAvg = bubbleSortByAvg(withAvg);
    const auto sortedByGrp = insertSortByGroup(withAvg);

    cout << "\nSorted by avg:\n";
    printArray(sortedByAvg);

    cout << "\nSorted by group:\n";
    printArray(sortedByGrp);

    double target;
    cout << "\nEnter average grade to search: ";
    cin >> target;

    const auto found = binSearchByAvg(sortedByAvg, target);

    if (found.empty()) {
        cout << "None with avg " << target << "\n";
    } else {
        cout << "Found students with avg " << target << ":\n";
        for (int idx: found)
            cout << " " << sortedByAvg[idx].surname
                    << " | Group: " << sortedByAvg[idx].group
                    << " | Avg: " << sortedByAvg[idx].avg << "\n";
    }

    return 0;
}
