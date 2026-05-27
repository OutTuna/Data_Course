#include <iostream>

using namespace std;

struct Node {
    int v;
    int w;
    Node *next;
} *first[7];

int M[7][7];

void addEdge(int u, int v, int weight) {
    M[u][v] = weight;
    M[v][u] = weight;

    Node *c1 = new Node;
    c1->v = v;
    c1->w = weight;
    c1->next = first[u];
    first[u] = c1;

    Node *c2 = new Node;
    c2->v = u;
    c2->w = weight;
    c2->next = first[v];
    first[v] = c2;
}

bool visited[7];
bool hasPath = false;

void dfs(int curr, int count) {
    if (count == 6) {
        hasPath = true;
        return;
    }
    visited[curr] = true;

    for (int i = 1; i <= 6; i++) {
        if (M[curr][i] != 0 && visited[i] == false) {
            dfs(i, count + 1);
        }
    }
    visited[curr] = false;
}

int main() {
    for (int i = 1; i <= 6; i++) {
        first[i] = 0;
        for (int j = 1; j <= 6; j++) {
            M[i][j] = 0;
        }
    }

    addEdge(1, 3, 2);
    addEdge(1, 5, 8);
    addEdge(2, 3, 6);
    addEdge(2, 4, 9);
    addEdge(3, 4, 9);
    addEdge(4, 5, 4);
    addEdge(4, 6, 4);

    cout << "Matrytsia sumizhnosti:\n";
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            cout << M[i][j] << " ";
        }
        cout << '\n';
    }

    bool isComplete = true;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i != j && M[i][j] == 0) {
                isComplete = false;
            }
        }
    }

    if (isComplete) {
        cout << "\nGraf ye povnym.\n";
    } else {
        cout << "\nGraf ne ye povnym.\n";
    }

    cout << "\nSpysok sumizhnosti:\n";
    for (int i = 1; i <= 6; i++) {
        cout << i << ": ";
        Node *q = first[i];
        while (q != 0) {
            cout << "-> [" << q->v << " vaga: " << q->w << "] ";
            q = q->next;
        }
        cout << '\n';
    }

    int sum = 0;
    int countEdges = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = i + 1; j <= 6; j++) {
            if (M[i][j] != 0) {
                sum += M[i][j];
                countEdges++;
            }
        }
    }
    cout << "\nSerednia dovzhyna shliahu (rebra): " << (float) sum / countEdges << '\n';

    cout << "\nIzolovani punkty (zviazok lyshe z 1 mistom):\n";
    int isolatedCount = 0;
    for (int i = 1; i <= 6; i++) {
        int degree = 0;
        int neighbor = 0;
        int dist = 0;

        for (int j = 1; j <= 6; j++) {
            if (M[i][j] != 0) {
                degree++;
                neighbor = j;
                dist = M[i][j];
            }
        }

        if (degree == 1) {
            cout << "Punkt " << i << ", nayblyzhchyi punkt " << neighbor << ", vidstan: " << dist << '\n';
            isolatedCount++;
        }
    }
    cout << "Kilkist izolovanih punktiv: " << isolatedCount << '\n';

    int maxPath = 0;
    int p1 = 0, p2 = 0, p3 = 0;
    int w1 = 0, w2 = 0;

    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                if (i != j && j != k && i != k) {
                    if (M[i][j] != 0 && M[j][k] != 0) {
                        int currentPath = M[i][j] + M[j][k];
                        if (currentPath > maxPath) {
                            maxPath = currentPath;
                            p1 = i;
                            p2 = j;
                            p3 = k;
                            w1 = M[i][j];
                            w2 = M[j][k];
                        }
                    }
                }
            }
        }
    }

    cout << "\nNaybilshyi marshrut mizh 3 mistamy:\n";
    cout << "(" << p1 << ") --- " << w1 << " --- (" << p2 << ") --- " << w2 << " --- (" << p3 << ")\n";

    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) visited[j] = false;
        hasPath = false;
        dfs(i, 1);
        if (hasPath) break;
    }

    if (hasPath) {
        cout << "\nMozhlyvo obyihaty vsi punkty po 1 razu (Gamiltoniv shliah).\n";
    } else {
        cout << "\nNe mozhlyvo obyihaty vsi punkty po 1 razu.\n";
    }

    for (int i = 1; i <= 6; i++) {
        Node *q = first[i];
        while (q != 0) {
            Node *delNode = q;
            q = q->next;
            delete delNode;
        }
    }

    return 0;
}
