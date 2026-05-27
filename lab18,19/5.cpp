#include <iostream>
#include <string>

using namespace std;

int getValidChoice() {
    int choice;
    while (!(cin >> choice)) {
        cin.clear();
        while (cin.get() != '\n') continue;
        cout << "Invalid input. Please enter a valid number: ";
    }
    return choice;
}

void generateMatrix(string key, char matrix[5][5]) {
    bool used[26] = {false};
    used['j' - 'a'] = true;
    int row = 0, col = 0;

    for (int i = 0; i < key.length(); i++) {
        char c = tolower(key[i]);
        if (isalpha(c) && !used[c - 'a']) {
            matrix[row][col++] = c;
            used[c - 'a'] = true;
            if (col == 5) { col = 0; row++; }
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (!used[c - 'a']) {
            matrix[row][col++] = c;
            if (col == 5) { col = 0; row++; }
        }
    }

    cout << "\n--- Playfair Matrix ---\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "-----------------------\n";
}

int main() {
    bool isRunning = true;

    while (isRunning) {
        cout << "\n=== Menu ===\n";
        cout << "1. Generate Matrix & Test Action\n0. Exit\nChoice: ";
        int choice = getValidChoice();
        cin.ignore();

        if (choice == 0) {
            cout << "Exiting program...\n";
            isRunning = false;
        } else if (choice == 1) {
            cout << "Enter keyword to generate matrix: ";
            string key;
            getline(cin, key);

            char matrix[5][5];
            generateMatrix(key, matrix);

            cout << "Select action to proceed with (Matrix created):\n1. Encrypt\n2. Decrypt\nChoice: ";
            int actionChoice = getValidChoice();

            switch (actionChoice) {
                case 1:
                    cout << "Encryption matrix is ready for use.\n";
                    break;
                case 2:
                    cout << "Decryption matrix is ready for use.\n";
                    break;
                default:
                    cout << "Incorrect choice.\n";
                    break;
            }
        }
    }
    return 0;
}