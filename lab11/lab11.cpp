#include <iostream>
using namespace std;

struct Node {
    int v, w;
    Node *next;
} *first[7];

int M[7][7];
// база для создання графів
void addEdge(int u, int v, int weight) {
    M[u][v] = weight;
    M[v][u] = weight;

    Node *c1 = new Node;
    c1->v = v;
    c1->w = weight;
    c1->next = first[u];
    first[u] = c1;

    Node *c2 = new Node;
    c2->v = v;
    c2->w = weight;
    c2->next = first[v];
    first[v] = c2;
}

int main() {
    for (int i = 1; i <= 6; i++) {
        first[i] = nullptr;
        for (int j = 1; j <= 6; j++)
            M[i][j] = 0;
    }
    // создаємо граф
    addEdge(1, 3, 3);
    addEdge(2, 3, 6);
    addEdge(2, 4, 8);
    addEdge(3, 4, 5);
    addEdge(3, 5, 2);
    addEdge(4, 6, 1);

    //складання матриці суміжності
    cout << "Adjacency matrix: \n";
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++)
            cout << M[i][j] << " ";
        cout << "\n";
    }
    //складання листа матриці суміжності
    cout << "Adjacency list: \n";
    for (int i = 1; i <= 6; i++) {
        cout << i << ": ";
        Node *g = first[i];
        while (g != nullptr) {
            cout << g->v << "(w = " << g->w << ") ";
            g = g->next;
        }
        cout << "\n";
    }
    // кількість ребер
    int edgeCount = 0;
    for (int i = 1; i <= 6; i++)
        for (int j = i + 1; j <= 6; j++)
            if (M[i][j] != 0) edgeCount++;
    cout << "\nEdge counter: " << edgeCount << '\n';

    // вершини з максимальною та мінімальною степінню
    int deg[7] = {};
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            if (M[i][j] != 0) deg[i]++;

    int mn = deg[1], mx = deg[1];
    for (int i = 2; i <= 6; i++) {
        if (deg[i] < mn) mn = deg[i];
        if (deg[i] > mx) mx = deg[i];
    }
    // виведення мін/макс степені
    cout << "\nMax (" << mx << "): top ";
    for (int i = 1; i <= 6; i++) if (deg[i] == mx) cout << i << " ";
    cout << "\nMin (" << mn << "): top ";
    for (int i = 1; i <= 6; i++) if (deg[i] == mn) cout << i << " ";
    cout << '\n';

    //вершини що мають однакову кількість звʼязків
    bool found = false;
    for (int i = 1; i <= 6 && !found; i++)
        for (int j = i + 1; j <= 6 && !found; j++)
            if (deg[i] == deg[j]) {
                cout << "\nTops " << i << " and " << j << " have the same connections: " << deg[i] << '\n';
                found = true;
            }
    if (!found) cout << "\nTops with same connection\n";

    // Алгоритм Флойда-Уоршелла
    int constexpr INF = 1e9;
    int dist[7][7];
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++) {
            if (i == j) dist[i][j] = 0;
            else if (M[i][j] != 0) dist[i][j] = M[i][j];
            else dist[i][j] = INF;
        }
    for (int k = 1; k <= 6; k++)
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 6; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

    // знайти три населені пункти, між якими сума відстаней є найменшою;
    int minSum = INF, a = -1, b = -1, c = -1;
    for (int i = 1; i <= 6; i++)
        for (int j = i + 1; j <= 6; j++)
            for (int k = j + 1; k <= 6; k++) {
                int s = dist[i][j] + dist[i][k] + dist[j][k];
                if (s < minSum) {
                    minSum = s;
                    a = i;
                    b = j;
                    c = k;
                }
            }
    cout << "\nThree of the closest: " << a << ", " << b << ", " << c << " (sum=" << minSum << ")\n";

    // найдовше ребро графа
    int maxW = 0, eu = -1, ev = -1;
    for (int i = 1; i <= 6; i++)
        for (int j = i + 1; j <= 6; j++)
            if (M[i][j] > maxW) {
                maxW = M[i][j];
                eu = i;
                ev = j;
            }
    cout << "\nThe longest edge: (" << eu << ") --- " << maxW << " --- (" << ev << ")\n";

    //очищення пам'яті
    for (int i = 1; i <= 6; i++) {
        Node *q = first[i];
        while (q != nullptr) {
            Node *del = q;
            q = q->next;
            delete del;
        }
    }
    return 0;
}


