#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> m;
    m["Ivan"] = 85;

    string name;
    int mark;
    cin >> name >> mark;

    m[name] = mark;

    for (auto p: m) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
