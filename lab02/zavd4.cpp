#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int m;
    cout << "Enter matrix size: ";
    cin >> m;

    int mat4[20][20];
    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            mat4[i][j] = rand() % 90 + 10;
            cout << mat4[i][j] << "\t";
        }
        cout << "\n";
    }

    int newMat[20][20];
    for (int i = 0; i < m; i++) {
        int col = 0;
        for (int j = 0; j < m; j++) {
            if (i != j) {
                newMat[i][col] = mat4[i][j];
                col++;
            }
        }
    }

    cout << "\nMatrix without main diagonal:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - 1; j++) {
            cout << newMat[i][j] << "\t";
        }
        cout << "\n";
    }

    int maxRowVal = newMat[0][0];
    int rowToDel = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (newMat[i][j] > maxRowVal) {
                maxRowVal = newMat[i][j];
                rowToDel = i;
            }
        }
    }
    cout << "\nMaximum element: " << maxRowVal << "\n";

    cout << "\nFinal matrix:\n";
    for (int i = 0; i < m; i++) {
        if (i == rowToDel) continue;
        for (int j = 0; j < m - 1; j++) {
            cout << newMat[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
