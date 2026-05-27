#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <cstdlib>

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

const string morseDict[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

string textToMorse(string text) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            result += morseDict[tolower(text[i]) - 'a'] + " ";
        } else if (text[i] == ' ') {
            result += "   ";
        }
    }
    return result;
}

void playSound(string morse) {
    cout << "Playing sound...\n";
    for (int i = 0; i < morse.length(); i++) {
        if (morse[i] == '.') {
            system("afplay /System/Library/Sounds/Tink.aiff");
        } else if (morse[i] == '-') {
            system("afplay /System/Library/Sounds/Glass.aiff");
        } else if (morse[i] == ' ') {
            usleep(300000);
        }
    }
}

void writeToFile(string filename, string text) {
    ofstream file(filename);
    if (file.is_open()) {
        file << text;
        file.close();
        cout << "Result saved to " << filename << endl;
    }
}

int main() {
    bool isRunning = true;

    while (isRunning) {
        cout << "\n=== Menu ===\n";
        cout << "1. Translate text to Morse Code\n0. Exit\nChoice: ";
        int mainChoice = getValidChoice();
        cin.ignore();

        if (mainChoice == 0) {
            cout << "Exiting program...\n";
            isRunning = false;
        } else if (mainChoice == 1) {
            cout << "Enter text to convert to Morse Code: ";
            string text;
            getline(cin, text);

            string morseResult = textToMorse(text);
            cout << "Morse Code:\n" << morseResult << endl;

            cout << "\nOptions:\n1. Save to file\n2. Play sound\n3. Do both\n4. Skip\nChoice: ";
            int choice = getValidChoice();
            cin.ignore();

            switch (choice) {
                case 1: {
                    cout << "Enter output filename: ";
                    string filename;
                    getline(cin, filename);
                    writeToFile(filename, morseResult);
                    break;
                }
                case 2:
                    playSound(morseResult);
                    break;
                case 3: {
                    cout << "Enter output filename: ";
                    string filename;
                    getline(cin, filename);
                    writeToFile(filename, morseResult);
                    playSound(morseResult);
                    break;
                }
                case 4:
                    cout << "Returning to main menu...\n";
                    break;
                default:
                    cout << "Incorrect choice.\n";
                    break;
            }
        }
    }
    return 0;
}