#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    multimap<char, string> m;
    string s;

    while (cin >> s) {
        if (s == "stop") break;
        m.insert({s[0], s});
    }

    for (auto p: m) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
