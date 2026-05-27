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

string caesarCipher(string text, int shift, bool encrypt) {
    if (!encrypt) shift = -shift;
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            int newChar = (text[i] - base + shift) % 26;
            if (newChar < 0) newChar += 26;
            result += (char)(newChar + base);
        } else {
            result += text[i];
        }
    }
    return result;
}

string caesarFrequencyMethod(string text, string keyword) {
    for (int shift = 0; shift < 26; shift++) {
        string attempt = caesarCipher(text, shift, false);
        if (attempt.find(keyword) != string::npos) {
            return attempt;
        }
    }
    return "Keyword not found in any shift combination.";
}

int main() {
    bool isRunning = true;

    while (isRunning) {
        cout << "\n=== Menu ===\n";
        cout << "1. Encrypt\n2. Decrypt with known shift\n3. Decrypt with keyword\n0. Exit\nChoice: ";
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
                cout << "Enter filename (e.g., input.txt): ";
                string filename;
                getline(cin, filename);
                text = readFile(filename);
            }

            if (text.empty()) {
                cout << "Text is empty, returning to menu.\n";
                continue;
            }

            switch (actionChoice) {
                case 1: {
                    cout << "Enter shift: ";
                    int shift = getValidChoice();
                    cout << "Result:\n" << caesarCipher(text, shift, true) << endl;
                    break;
                }
                case 2: {
                    cout << "Enter shift: ";
                    int shift = getValidChoice();
                    cout << "Result:\n" << caesarCipher(text, shift, false) << endl;
                    break;
                }
                case 3: {
                    cout << "Enter keyword: ";
                    string keyword;
                    getline(cin, keyword);
                    cout << "Result:\n" << caesarFrequencyMethod(text, keyword) << endl;
                    break;
                }
                default:
                    cout << "Incorrect choice.\n";
                    break;
            }
        }
    }
    return 0;
}