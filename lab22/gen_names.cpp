#include <fstream>

using namespace std;

int main() {
    ofstream file("names.txt");
    const char* names[] = {
        "Anna", "Ivan", "Olena", "Andrii", "Maria",
        "Oleksii", "Inna", "Dmytro", "Oksana", "Viktor",
        "Anna", "Ivan", "Maria", "Olena", "Anna",
        "Emil", "Uliana", "Bohdan", "Alina", "Serhii"
    };
    for (auto n : names) file << n << "\n";
    return 0;
}
