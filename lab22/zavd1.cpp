#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("numbers.txt");
    if (!file) {
        cerr << "Cannot open numbers.txt\n";
        return 1;
    }

    vector<int> all;
    int num;
    while (file >> num) all.push_back(num);
    file.close();

    int size;
    cout << "Enter count (max " << all.size() << "): ";
    cin >> size;
    if (size > (int)all.size()) size = (int)all.size();

    vector<int> v(all.begin(), all.begin() + size);

    int t = (int)v.size() / 3;
    sort(v.begin(), v.begin() + t, greater<int>());
    sort(v.begin() + 2 * t, v.end());

    v.erase(unique(v.begin(), v.end()), v.end());

    auto mid = stable_partition(v.begin(), v.end(), [](int x) { return x >= 10; });
    for_each(mid, v.end(), [](int& x) { x += 100; });

    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    replace_if(v.begin(), v.end(), [](int x) { return x > 100; }, mx);
    replace_if(v.begin(), v.end(), [](int x) { return x < -100; }, mn);

    v.erase(remove_if(v.begin(), v.end(), [](int x) { return x >= -5 && x <= 5; }), v.end());

    cout << "Result:\n";
    for (int x : v) cout << x << " ";
    cout << "\n";

    return 0;
}
