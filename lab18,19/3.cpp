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

void printVigenereTable() {
    cout << "\n--- Vigenere Table ---\n";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            cout << (char)('A' + (i + j) % 26) << " ";
        }
        cout << "\n";
    }
    cout << "----------------------\n\n";
}

string vigenereCipher(string text, string key, bool encrypt) {
    string result = "";
    int j = 0;
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char keyBase = islower(key[j % key.length()]) ? 'a' : 'A';
            int shift = key[j % key.length()] - keyBase;

            if (!encrypt) shift = 26 - shift;

            result += (char)((c - base + shift) % 26 + base);
            j++;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    bool isRunning = true;

    while (isRunning) {
        cout << "\n=== Menu ===\n";
        cout << "1. Print Table\n2. Encrypt\n3. Decrypt\n0. Exit\nChoice: ";
        int choice = getValidChoice();
        cin.ignore();

        if (choice == 0) {
            cout << "Exiting program...\n";
            isRunning = false;
        } else if (choice == 1) {
            printVigenereTable();
        } else {
            cout << "Enter text: ";
            string text;
            getline(cin, text);

            cout << "Enter keyword: ";
            string key;
            getline(cin, key);

            switch (choice) {
                case 2:
                    cout << "Result: " << vigenereCipher(text, key, true) << endl;
                    break;
                case 3:
                    cout << "Result: " << vigenereCipher(text, key, false) << endl;
                    break;
                default:
                    cout << "Incorrect choice.\n";
                    break;
            }
        }
    }
    return 0;
}