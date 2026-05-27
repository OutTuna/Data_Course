#include <iostream>
#include <string>
#include <fstream>

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

string readFile(string filename) {
    ifstream file(filename);
    string content = "";
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close();
    } else {
        cout << "Error opening file.\n";
    }
    return content;
}

string substitutionCipher(string text, string key, bool encrypt) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            bool isLower = islower(text[i]);
            char c = tolower(text[i]);
            if (encrypt) {
                char newChar = key[c - 'a'];
                result += isLower ? newChar : toupper(newChar);
            } else {
                int pos = key.find(c);
                if (pos != string::npos) {
                    char newChar = 'a' + pos;
                    result += isLower ? newChar : toupper(newChar);
                } else {
                    result += text[i];
                }
            }
        } else {
            result += text[i];
        }
    }
    return result;
}

int main() {
    bool isRunning = true;

    while (isRunning) {
        cout << "\n=== Menu ===\n";
        cout << "1. Encrypt\n2. Decrypt\n0. Exit\nChoice: ";
        int actionChoice = getValidChoice();
        cin.ignore();

        if (actionChoice == 0) {
            cout << "Exiting program...\n";
            isRunning = false;
        } else {
            cout << "Select input source:\n1. Console\n2. File\nChoice: ";
            int sourceChoice = getValidChoice();
            cin.ignore();

            string text = "";
            if (sourceChoice == 1) {
                cout << "Enter text: ";
                getline(cin, text);
            } else {
                cout << "Enter filename: ";
                string filename;
                getline(cin, filename);
                text = readFile(filename);
            }

            if (text.empty()) continue;

            cout << "Enter 26-letter key (lowercase): ";
            string key;
            getline(cin, key);

            if (key.length() != 26) {
                cout << "Key must be exactly 26 letters. Returning to menu.\n";
                continue;
            }

            switch (actionChoice) {
                case 1:
                    cout << "Result:\n" << substitutionCipher(text, key, true) << endl;
                    break;
                case 2:
                    cout << "Result:\n" << substitutionCipher(text, key, false) << endl;
                    break;
                default:
                    cout << "Incorrect choice.\n";
                    break;
            }
        }
    }
    return 0;
}