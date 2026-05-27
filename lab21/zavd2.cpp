#include <iostream>
#include <string>
#include <climits>
using namespace std;


int cost[3][3] = {
    {8, 7, 2},
    {1, 4, 3},
    {5, 1, 6}
};

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

void northCorner() {
    int supply[] = {1500, 1900, 1600};
    int demand[] = {1800, 1200, 2000};
    int plan[3][3] = {};

    int i = 0, j = 0;
    while (i < 3 && j < 3) {
        int amount = min(supply[i], demand[j]);
        plan[i][j] = amount;
        supply[i] -= amount;
        demand[j] -= amount;
        if (supply[i] == 0) i++;
        else j++;
    }

    cout << "North Corner \n";
    printPlan(plan);
    cout << "\n";
}

void minCost() {
    int supply[] = {1500, 1900, 1600};
    int demand[] = {1800, 1200, 2000};
    int plan[3][3] = {};
    bool rowDone[3] = {false, false, false};
    bool colDone[3] = {false, false, false};

    for (int step = 0; step < 9; step++) {
        int minCost = INT_MAX;
        int ri = -1, rj = -1;
        for (int i = 0; i < 3; i++) {
            if (rowDone[i]) continue;
            for (int j = 0; j < 3; j++) {
                if (colDone[j]) continue;
                if (cost[i][j] < minCost) {
                    minCost = cost[i][j];
                    ri = i;
                    rj = j;
                }
            }
        }
        if (ri == -1) break;
        int amount = min(supply[ri], demand[rj]);
        plan[ri][rj] = amount;
        supply[ri] -= amount;
        demand[rj] -= amount;
        if (supply[ri] == 0) rowDone[ri] = true;
        if (demand[rj] == 0) colDone[rj] = true;
    }
    cout << "Min Cost \n";
    printPlan(plan);
    cout << "\n";
}

int main() {
    northCorner();
    minCost();
    return 0;
}
