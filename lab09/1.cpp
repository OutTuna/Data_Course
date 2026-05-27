#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

struct Node {
    int v;
    Node *left;
    Node *right;
} *root, *rootEven, *rootOdd;

void addNode(Node *&r, int val) {
    if (r == 0) {
        Node *c = new Node;
        c->v = val;
        c->left = 0;
        c->right = 0;
        r = c;
        return;
    }
    if (val < r->v) {
        addNode(r->left, val);
    } else if (val > r->v) {
        addNode(r->right, val);
    }
}

bool findNode(Node *r, int val) {
    if (r == 0) return false;
    if (r->v == val) return true;
    if (val < r->v) return findNode(r->left, val);
    return findNode(r->right, val);
}

void splitTree(Node *r) {
    if (r == 0) return;
    if (r->v % 2 == 0) {
        addNode(rootEven, r->v);
    } else {
        addNode(rootOdd, r->v);
    }
    splitTree(r->left);
    splitTree(r->right);
}

int getDepth(Node *r) {
    if (r == 0) return 0;
    int leftD = getDepth(r->left);
    int rightD = getDepth(r->right);
    if (leftD > rightD) return leftD + 1;
    else return rightD + 1;
}

void deleteTree(Node *&r) {
    if (r != 0) {
        deleteTree(r->left);
        deleteTree(r->right);
        delete r;
        r = 0;
    }
}


int main() {
    srand(time(0));

    root = 0;
    rootEven = 0;
    rootOdd = 0;

    int n, choice;
    cout << "Vvedit kilkist vuzliv: ";
    cin >> n;

    cout << "1 - Vvesty vruchnu, 2 - Zgeneruvaty vypadkovo: ";
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < n; i++) {
            int val;
            cout << "Vvedit znachennia: ";
            cin >> val;
            addNode(root, val);
        }
    } else if (choice == 2) {
        int a, b;
        cout << "Vvedit mezhi vidrizka a ta b: \n";
        cin >> a >> b;

        while (n > (b - a)) {
            cout << "Pomylka: kilkist vuzliv bilsha za diapazon!\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please enter correctni mezhi: ";
            cin >> a >> b;
        }
        int count = 0;
        while (count < n) {
            int val = a + rand() % (b - a + 1);
            if (findNode(root, val) == false) {
                addNode(root, val);
                count++;
            }
        }
    }

    int searchVal;
    cout << "\nVvedit znachennia dlia poshuku: ";
    cin >> searchVal;

    if (findNode(root, searchVal)) {
        cout << "Znachennia ye u derevi.\n";
    } else {
        cout << "Znachennia ne znaydeno.\n";
    }

    splitTree(root);

    cout << "\nGlybyna osnovnogo dereva: " << getDepth(root) << '\n';
    cout << "Glybyna dereva z parnymy: " << getDepth(rootEven) << '\n';
    cout << "Glybyna dereva z neparnymy: " << getDepth(rootOdd) << '\n';

    deleteTree(root);
    deleteTree(rootEven);
    deleteTree(rootOdd);

    return 0;
}
