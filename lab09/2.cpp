#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct CompNode {
    int code;
    string name;
    float price;
    CompNode *left;
    CompNode *right;
} *root;

void addNode(CompNode *&r, int c, string n, float p) {
    if (r == 0) {
        CompNode *newNode = new CompNode;
        newNode->code = c;
        newNode->name = n;
        newNode->price = p;
        newNode->left = 0;
        newNode->right = 0;
        r = newNode;
        return;
    }
    if (c < r->code) {
        addNode(r->left, c, n, p);
    } else if (c > r->code) {
        addNode(r->right, c, n, p);
    }
}

void printTree(CompNode *r) {
    if (r == 0) return;
    printTree(r->left);
    cout << "Kod: " << r->code << " | Nazva: " << r->name << " | Tsina: " << r->price << '\n';
    printTree(r->right);
}

void calcAvg(CompNode *r, float &sum, int &count) {
    if (r == 0) return;
    sum += r->price;
    count++;
    calcAvg(r->left, sum, count);
    calcAvg(r->right, sum, count);
}

void countLevels(CompNode *r, int level, int levels[]) {
    if (r == 0) return;
    levels[level]++;
    countLevels(r->left, level + 1, levels);
    countLevels(r->right, level + 1, levels);
}

CompNode *findNode(CompNode *r, int c) {
    if (r == 0) return 0;
    if (r->code == c) return r;
    if (c < r->code) return findNode(r->left, c);
    return findNode(r->right, c);
}

void deleteTree(CompNode *&r) {
    if (r != 0) {
        deleteTree(r->left);
        deleteTree(r->right);
        delete r;
        r = 0;
    }
}

int main() {
    root = 0;

    string filename = "tech.txt";
    ifstream file(filename);

    while (!file.is_open()) {
        cout << "Pomylka: fayl " << filename << " ne znaydeno!\n";
        cout << "Bud laska, stvorit fayl abo vvedit inshu nazvu (napryklad, tech.txt): ";
        cin >> filename;
        file.open(filename);
    }

    int c;
    string n;
    float p;
    while (file >> c >> n >> p) {
        addNode(root, c, n, p);
    }
    file.close();

    cout << "SPYSOK TOVARIV (DO VYDALENNIA)\n";
    printTree(root);

    float sum = 0;
    int count = 0;
    calcAvg(root, sum, count);

    if (count > 0) {
        cout << "Serednia vartist tehniky: " << sum / count << '\n';
    }

    int levels[20];
    for (int i = 0; i < 20; i++) levels[i] = 0;
    countLevels(root, 0, levels);

    cout << "\nKilkist vuzliv na rivniakh:\n";
    for (int i = 0; i < 20; i++) {
        if (levels[i] > 0) {
            cout << "Riven " << i << ": " << levels[i] << '\n';
        }
    }

    int searchCode;
    cout << "\nVvedit kod tehniky dlia vydalennia dochirnih elementiv: ";

    while (!(cin >> searchCode)) {
        cout << "Pomylka: vvedeno nepravylni dani (litery zamist chysla)!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Vvedit kod tehniky shche raz: ";
    }

    CompNode *target = findNode(root, searchCode);
    if (target != 0) {
        // Видаляємо дочірні елементи
        deleteTree(target->left);
        deleteTree(target->right);
        cout << "\n>>> Dochirni elementy dlia tovaru " << target->name << " vydaleno z pamyati.\n\n";

        cout << "SPYSOK TOVARIV (PISLIA VYDALENNIA)\n";
        printTree(root);
    } else {
        cout << "Tehniku z takym kodom ne znaydeno.\n";
    }

    deleteTree(root);
    return 0;
}
