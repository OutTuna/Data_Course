#include <iostream>
#include <string>
#include <climits>
using namespace std;

int cost[3][3];

void printPlan(int plan[3][3]) {
    cout << "| Sklad | M1 | M2 | M3 |\n";
    cout << "|-------|----|----|----|\n";
    int totalCost = 0;
    for (int i = 0; i < 3; i++) {
        cout << "| C" << (i + 1) << "  ";
        for (int j = 0; j < 3; j++) {
            cout << "| " << plan[i][j];
            for (int s = to_string(plan[i][j]).size(); s < 5; s++) cout << " ";
            totalCost += plan[i][j] * cost[i][j];
        }
        cout << "|\n";
    }
    cout << "Total cost: " << totalCost << " units\n";
}

void northCorner(int supply[3], int demand[3]) {
    int s[3] = {supply[0], supply[1], supply[2]};
    int d[3] = {demand[0], demand[1], demand[2]};
    int plan[3][3] = {};

    int i = 0, j = 0;
    while (i < 3 && j < 3) {
        int amount = min(s[i], d[j]);
        plan[i][j] = amount;
        s[i] -= amount;
        d[j] -= amount;
        if (s[i] == 0) i++;
        else j++;
    }

    cout << "North Corner:\n";
    printPlan(plan);
    cout << "\n";
}

void minCostMethod(int supply[3], int demand[3]) {
    int s[3] = {supply[0], supply[1], supply[2]};
    int d[3] = {demand[0], demand[1], demand[2]};
    int plan[3][3] = {};
    bool rowDone[3] = {false, false, false};
    bool colDone[3] = {false, false, false};

    for (int step = 0; step < 9; step++) {
        int minC = INT_MAX;
        int ri = -1, rj = -1;
        for (int i = 0; i < 3; i++) {
            if (rowDone[i]) continue;
            for (int j = 0; j < 3; j++) {
                if (colDone[j]) continue;
                if (cost[i][j] < minC) {
                    minC = cost[i][j];
                    ri = i;
                    rj = j;
                }
            }
        }
        if (ri == -1) break;
        int amount = min(s[ri], d[rj]);
        plan[ri][rj] = amount;
        s[ri] -= amount;
        d[rj] -= amount;
        if (s[ri] == 0) rowDone[ri] = true;
        if (d[rj] == 0) colDone[rj] = true;
    }

    cout << "Min Cost:\n";
    printPlan(plan);
    cout << "\n";
}

void inputMatrix() {
    cout << "Enter cost matrix (3x3):\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cout << "  cost[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> cost[i][j];
        }
}

void inputSupplyDemand(int supply[3], int demand[3]) {
    cout << "Enter supply for each warehouse (C1, C2, C3):\n";
    for (int i = 0; i < 3; i++) {
        cout << "  C" << (i + 1) << ": ";
        cin >> supply[i];
    }
    cout << "Enter demand for each market (M1, M2, M3):\n";
    for (int j = 0; j < 3; j++) {
        cout << "  M" << (j + 1) << ": ";
        cin >> demand[j];
    }
}

int main() {
    int choice;
    int supply[3], demand[3];
    
    cout << "1 - Use default values\n";
    cout << "2 - Enter custom values\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 2) {
        inputMatrix();
        inputSupplyDemand(supply, demand);
    } else {
        int defCost[3][3] = {{8, 7, 2}, {1, 4, 3}, {5, 1, 6}};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cost[i][j] = defCost[i][j];

        int defSupply[] = {1500, 1900, 1600};
        int defDemand[] = {1800, 1200, 2000};
        for (int i = 0; i < 3; i++) supply[i] = defSupply[i];
        for (int j = 0; j < 3; j++) demand[j] = defDemand[j];
    }

    int totalSupply = supply[0] + supply[1] + supply[2];
    int totalDemand = demand[0] + demand[1] + demand[2];
    if (totalSupply != totalDemand) {
        cout << "\nWarning: supply (" << totalSupply
                << ") != demand (" << totalDemand << "). Problem is unbalanced!\n\n";
    }

    cout << "\n--- Cost matrix ---\n";
    cout << "       M1   M2   M3\n";
    for (int i = 0; i < 3; i++) {
        cout << "  C" << (i + 1) << " |";
        for (int j = 0; j < 3; j++)
            cout << "  " << cost[i][j] << "  ";
        cout << "\n";
    }
    cout << "\n";

    northCorner(supply, demand);
    minCostMethod(supply, demand);

    return 0;
}
