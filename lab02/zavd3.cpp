#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printMatrix(int mat[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    srand(time(0));
    int mat3[5][5];
    int maxV = -1, maxI = 0, maxJ = 0;
    
    cout << "Original Matrix 5x5:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mat3[i][j] = rand() % 90 + 10;
            cout << mat3[i][j] << "\t";
            if (mat3[i][j] > maxV) {
                maxV = mat3[i][j];
                maxI = i;
                maxJ = j;
            }
        }
        cout << "\n";
    }
    cout << "\n";
    
    clock_t start = clock();

    if (maxI != 0) {
        for (int j = 0; j < 5; j++) {
            int temp = mat3[0][j];
            mat3[0][j] = mat3[maxI][j];
            mat3[maxI][j] = temp;
        }
        cout << "Iteration 1 (Rows swapped):\n";
        printMatrix(mat3);
    }
    
    if (maxJ != 0) {
        for (int i = 0; i < 5; i++) {
            int temp = mat3[i][0];
            mat3[i][0] = mat3[i][maxJ];
            mat3[i][maxJ] = temp;
        }
        cout << "Iteration 2 (Cols swapped):\n";
        printMatrix(mat3);
    }

    clock_t end = clock();
    cout << "Time complexity: " << (double)(end - start) / CLOCKS_PER_SEC << " sec\n";

    return 0;
}