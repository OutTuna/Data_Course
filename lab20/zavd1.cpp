#include <iostream>

using namespace std;


int getValidChoice() {
    int choice;
    while (!(cin >> choice)) {
        cin.clear();
        while (cin.get() != '\n')
            cout << "Invalid input. Please enter a valid number: ";
    }
    return choice;
}

void solveExpedition() {
    int bestSugar = 0, bestMilk = 0, bestFlour = 0, bestMeat = 0;
    int maxCalories = 0;

    for (int sugar = 1; sugar <= 35; sugar++) {
        for (int milk = 8 * sugar; milk <= 35; milk++) {
            for (int flour = milk; flour <= 35; flour++) {
                for (int meat = 2 * flour; meat <= 35; meat++) {
                    int totalMass = sugar + milk + flour + meat;
                    double totalVolume = sugar * 1.0 + milk * 2.0 + flour * 1.5 + meat * 1.0;

                    if (totalMass <= 35 && totalVolume <= 45.0) {
                        int currentCalories = sugar * 4000 + milk * 5000 + flour * 5000 + meat * 1500;
                        if (currentCalories > maxCalories) {
                            maxCalories = currentCalories;
                            bestSugar = sugar;
                            bestMilk = milk;
                            bestFlour = flour;
                            bestMeat = meat;
                        }
                    }
                }
            }
        }
    }

    if (maxCalories > 0) {
        cout << "Sugar: " << bestSugar << " kg\n";
        cout << "Milk:  " << bestMilk << " kg\n";
        cout << "Flour: " << bestFlour << " kg\n";
        cout << "Meat:  " << bestMeat << " kg\n";
        cout << "Total Calories: " << maxCalories << " kcal\n";
        cout << "Total Mass:     " << (bestSugar + bestMilk + bestFlour + bestMeat) << " kg\n";
        cout << "Total Volume:   " << (bestSugar * 1.0 + bestMilk * 2.0 + bestFlour * 1.5 + bestMeat * 1.0) <<
                " dm^3\n";
    } else {
        cout << "Cannot find a valid configuration that fits the constraints.\n";
    }
}

int main() {
    bool isRunning = true;

    while (isRunning) {
        cout << "\nMenu\n";
        cout << "1. Calculate Optimal Provisions\n";
        cout << "0. Exit\n";
        cout << "Choice: ";

        int choice = getValidChoice();
        cin.ignore();

        switch (choice) {
            case 1:
                solveExpedition();
                break;
            case 0:
                cout << "Exiting program...\n";
                isRunning = false;
                break;
            default:
                cout << "Incorrect choice.\n";
                break;
        }
    }
    return 0;
}
