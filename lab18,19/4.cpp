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
            content += line;
        }
        file.close();
    }
    return content;
}

string encryptPolybius(string text) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = toupper(text[i]);
        if (isalpha(c)) {
            if (c == 'J') c = 'I';
            int offset = c - 'A';
            if (c > 'J') offset--;

            int row = (offset / 5) + 1;
            int col = (offset % 5) + 1;
            result += to_string(row) + to_string(col) + " ";
        } else if (text[i] == ' ') {
            result += "  ";
        }
    }
    return result;
}

string decryptPolybius(string text) {
    string result = "";
    for (int i = 0; i < text.length(); ) {
        if (text[i] == ' ' && i + 1 < text.length() && text[i+1] == ' ') {
            result += " ";
            i += 2;
            continue;
        }

        if (i + 1 < text.length() && isdigit(text[i]) && isdigit(text[i+1])) {
            int row = text[i] - '0';
            int col = text[i+1] - '0';
            int offset = (row - 1) * 5 + (col - 1);
            char c = 'A' + offset;
            if (c >= 'J') c++;
            result += c;
            i += 2;
        } else {
            i++;
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

            switch (actionChoice) {
                case 1:
                    cout << "\nEncrypted Text: " << encryptPolybius(text) << endl;
                    break;
                case 2:
                    cout << "Decrypted Text: " << decryptPolybius(text) << endl;
                    break;
                default:
                    cout << "Incorrect choice.\n";
                    break;
            }
        }
    }
    return 0;
}