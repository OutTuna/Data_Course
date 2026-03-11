#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
// n/4
bool checkMultiplicity(int n) {
    if (n % 4 == 0) {
        return true;
    } else {
        return false;
    }
}
//filling Array -1.5 to 4.5
void generateArray(double A[], int n) {
    for (int i = 0; i < n; i = i + 1) {
        int random_val = rand() % 601;
        random_val = random_val - 150;
        A[i] = random_val / 100.0;
    }
}
//output Array
void printArray(double A[], int n) {
    for (int i = 0; i < n; i = i + 1) {
        cout << A[i] << "\t";
    }
    cout << "\n";
}
//Matrix n/4
double** createMatrix(double A[], int n) {
    int rows = n / 4;
    double** B = new double*[rows];
    int index = 0;

    for (int i = 0; i < rows; i = i + 1) {
        B[i] = new double[4];
        for (int j = 0; j < 4; j = j + 1) {
            B[i][j] = A[index];
            index = index + 1;
        }
    }
    return B;
}
//bublesort which ascending
void bubbleSortAscending(double arr[], int n) {
    for (int i = 0; i < n - 1; i = i + 1) {
        for (int j = 0; j < n - i - 1; j = j + 1) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
//bublesort which descending
void bubbleSortDescending(double arr[], int n) {
    for (int i = 0; i < n - 1; i = i + 1) {
        for (int j = 0; j < n - i - 1; j = j + 1) {
            if (arr[j] < arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// find Max
double findMax(double arr[], int n) {
    double max_val = arr[0];
    for (int i = 1; i < n; i = i + 1) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}
//main logic
void processLab1(int n, ofstream& outFile, int testNum) {
    if (checkMultiplicity(n) == false) {
        return;
    }
//timer start
    clock_t start_time = clock();

    double* A = new double[n];
    generateArray(A, n);

    double** B = createMatrix(A, n);
    int rows = n / 4;

    for (int i = 0; i < rows; i = i + 1) {
        if (i % 2 == 0) {
            bubbleSortAscending(B[i], 4);
        } else {
            bubbleSortDescending(B[i], 4);
        }
    }

    double colMax[4];
    for (int j = 0; j < 4; j = j + 1) {
        double* tempCol = new double[rows];
        for (int i = 0; i < rows; i = i + 1) {
            tempCol[i] = B[i][j];
        }
        colMax[j] = findMax(tempCol, rows);
        delete[] tempCol;
    }
//timer stop + getting time
    clock_t end_time = clock();
    double exec_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    size_t space = (sizeof(double) * n) + (sizeof(double*) * rows) + (sizeof(double) * n);

//output
    outFile << testNum << "|\t" << n << "\t" << exec_time << "\t" << space << "\n";

    for (int i = 0; i < rows; i = i + 1) {
        delete[] B[i];
    }
    delete[] B;
    delete[] A;
}

int main() {
    srand(time(0));

    ofstream outFile("output.txt");
    outFile << "The following table:\n";
    outFile << "N\tn\tTime, sec.\tSpace, byte\n";
// n - is size of table
    processLab1(20, outFile, 1);
    processLab1(100, outFile, 2);
    processLab1(1000, outFile, 3);

    outFile.close();
    cout << "Results saved in output.txt\n";
    return 0;
}