#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    map<char, int> freq;
    for (char c: line) {
        freq[c]++;
    }
    for (auto &[ch , cnt]: freq) {
        cout << "'" << ch << "' (" << (int) ch << "): " << cnt << "\n";
    }

    char maxChar = freq.begin()->first;
    int maxCnt = freq.begin()->second;
    for (auto &[ch, cnt]: freq) {
        if (cnt > maxCnt) {
            maxCnt = cnt;
            maxChar = ch;
        }
    }

    cout << "\nthe most usable symbol : " << maxChar << "' - " << maxCnt << "times\n";
    return 0;
}

/* test point
 * Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
 */
