#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

void sortAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortEvenOdd(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool swapNeeded = false;
            if (arr[j] % 2 != 0 && arr[j + 1] % 2 == 0) {
                swapNeeded = true;
            } else if (arr[j] % 2 == 0 && arr[j + 1] % 2 == 0) {
                if (arr[j] > arr[j + 1]) swapNeeded = true;
            } else if (arr[j] % 2 != 0 && arr[j + 1] % 2 != 0) {
                if (arr[j] < arr[j + 1]) swapNeeded = true;
            }

            if (swapNeeded) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int A[100], copy1[100], copy2[100];
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 20 + 1;
        copy1[i] = A[i];
        copy2[i] = A[i];
    }

    cout << "Original array:\n";
    printArray(A, n);

    clock_t start1 = clock();
    sortAsc(copy1, n);
    clock_t end1 = clock();

    clock_t start2 = clock();
    sortDesc(copy2, n);
    clock_t end2 = clock();

    sortEvenOdd(A, n);
    cout << "Sorted array (even asc, odd desc):\n";
    printArray(A, n);

    cout << "Ascending sort time: " << (double) (end1 - start1) / CLOCKS_PER_SEC << " sec\n";
    cout << "Descending sort time: " << (double) (end2 - start2) / CLOCKS_PER_SEC << " sec\n";

    return 0;
}
