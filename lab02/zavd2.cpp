#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

void removeElements(int arr[], int n, int x) {
    int newSize = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    for (int i = newSize; i < n; i++) {
        arr[i] = 0;
    }
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    int B[100];
    for (int i = 0; i < n; i++) {
        bool unique;
        do {
            unique = true;
            B[i] = rand() % 50 + 1;
            for (int j = 0; j < i; j++) {
                if (B[i] == B[j]) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);
    }
    
    cout << "Unique array:\n";
    printArray(B, n);
    
    int x;
    cout << "Enter X: ";
    cin >> x;
    
    removeElements(B, n, x);
    cout << "Array after processing:\n";
    printArray(B, n);
    
    int spaceComplexity = sizeof(B) + sizeof(n) + sizeof(x);
    cout << "Space complexity: " << spaceComplexity << " bytes\n";

    return 0;
}