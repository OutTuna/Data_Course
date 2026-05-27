#include <fstream>

using namespace std;

int main() {
    srand((unsigned) time(nullptr));
    ofstream file("numbers.txt");
    for (int i = 0; i < 1000; i++)
        file << (rand() % 401 - 200) << "\n";
    return 0;
}
