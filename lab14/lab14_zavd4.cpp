#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    multimap<int, string> wordMap;
    string line, word;

    cout << "enter words (blank line to finish): \n";
    while (getline(cin, line) && !line.empty()) {
        istringstream iss(line);
        while (iss >> word) {
            const string punct = " \t\n\r!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
            size_t s = word.find_first_not_of(punct);
            if (s == string::npos) continue;
            size_t e = word.find_last_not_of(punct);
            string cleaned = word.substr(s, e - s + 1);
            wordMap.insert({(int) cleaned.size(), cleaned});
        }
    }

    int prevLen = -1;
    int groupCount = 0;
    for (auto it = wordMap.begin(); it != wordMap.end(); ++it) {
        if (it->first != prevLen) {
            if (prevLen != -1)
                cout << "  Count of words: " << groupCount << "\n";
            prevLen = it->first;
            groupCount = 0;
            cout << "\nLength " << it->first << ":\n";
        }
        cout << "  " << it->second << "\n";
        ++groupCount;
    }
    if (prevLen != -1)
        cout << "  Count of words: " << groupCount << "\n";
    //damn I did some stuff and idk how it works

    return 0;
}
