#include <iostream>
using namespace std;

int timeCounter = 0;

void dfsVisit(int Adj[][100], int p[], int d[], int f[], char color[], int vNum, int u) {
    timeCounter++;
    color[u] = 'g';
    d[u] = timeCounter;

    for (int v = 0; v < vNum; v++) {
        if (Adj[u][v] != 0 && color[v] == 'w') {
            p[v] = u;
            dfsVisit(Adj, p, d, f, color, vNum, v);
        }
    }
    timeCounter++;
    color[u] = 'b';
    f[u] = timeCounter;
}

int main() {
    int vNum, eNum;
    cout << "Enter the number of vertices: ";
    cin >> vNum;
    cout << "Enter the number of edges: ";
    cin >> eNum;

    int Adj[100][100] = {0}; // Adjacency matrix with maximum size 100
    int p[100], f[100], d[100];
    char color[100];

    for (int i = 0; i < vNum; i++) {
        p[i] = -1;
        d[i] = 0;
        f[i] = 0;
        color[i] = 'w'; // Initialize all vertices as white (unvisited)
    }

    for (int i = 0; i < eNum; i++) {
        int u, v;
        cout << "Enter the vertices that are connected (directed graph): ";
        cin >> u >> v;
        Adj[u][v] = 1; // Mark edge in adjacency matrix
    }

    for (int u = 0; u < vNum; u++) {
        if (color[u] == 'w') {
            dfsVisit(Adj, p, d, f, color, vNum, u);
        }
    }

    // Print results
    cout << "\nVertex\tDiscovery Time\tFinishing Time\tParent\n";
    for (int i = 0; i < vNum; i++) {
        cout << i << "\t\t" << d[i] << "\t\t" << f[i] << "\t\t" << p[i] << "\n";
    }

    return 0;
}