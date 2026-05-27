#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int n = 100000;
    map<int, int> m1;
    unordered_map<int, int> m2;

    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < n; i++) m1[i] = i;
    auto t2 = high_resolution_clock::now();
    cout << "map: " << duration_cast<milliseconds>(t2 - t1).count() << " ms\n";

    t1 = high_resolution_clock::now();
    for (int i = 0; i < n; i++) m2[i] = i;
    t2 = high_resolution_clock::now();
    cout << "unordered_map: " << duration_cast<milliseconds>(t2 - t1).count() << " ms\n";

    return 0;
}
