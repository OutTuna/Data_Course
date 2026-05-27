#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool isVowel(char c) {
    c = (char)tolower((unsigned char)c);
    string vowels = "aeiou";
    return vowels.find(c) != string::npos;
}

int main() {
    ifstream file("names.txt");
    if (!file) {
        cerr << "Cannot open names.txt\n";
        return 1;
    }

    vector<string> names;
    string name;
    while (file >> name) names.push_back(name);
    file.close();

    string query;
    cout << "Enter name to search: ";
    cin >> query;
    int cnt = (int)count(names.begin(), names.end(), query);
    cout << "Occurrences of \"" << query << "\": " << cnt << "\n";

    for_each(names.begin(), names.end(), [](string& s) {
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c) { return (char)toupper(c); });
    });
    cout << "Uppercase: ";
    for (auto& s : names) cout << s << " ";
    cout << "\n";

    for_each(names.begin(), names.end(), [](string& s) {
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c) { return (char)tolower(c); });
    });
    cout << "Lowercase: ";
    for (auto& s : names) cout << s << " ";
    cout << "\n";

    stable_partition(names.begin(), names.end(), [](const string& s) {
        return !s.empty() && isVowel(s[0]);
    });
    cout << "Vowel-first: ";
    for (auto& s : names) cout << s << " ";
    cout << "\n";

    return 0;
}
