#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> m;
    m["Ivan"] = "0991234567";
    m["Anna"] = "0671234567";

    string name;
    cin >> name;
    cout << m[name] << endl;

    m.erase("Ivan");

    return 0;
}
