#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> m;
    string s;

    while (cin >> s) {
        if (s == "stop") break;
        m[s]++;
    }

    for (auto p: m) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
