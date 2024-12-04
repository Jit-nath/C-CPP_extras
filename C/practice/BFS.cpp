#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
#define V 4
void BFS(int adjMatrix[][V], int d[], int p[], int start) {
    int colour[V] = {0};
    colour[start] = 1;
    p[start] = -1;
    d[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v = 0; v < V; ++v) {
            if (adjMatrix[u][v] == 1 && colour[v] == 0) {
                colour[v] = 1;
                p[v] = u;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        colour[u] = 2;
    }
}
int main() {
    int adjMatrix[V][V], d[V] = {0}, p[V], start;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> adjMatrix[i][j];
        }
    }
    cout << "Enter start vertex:";
    cin >> start;
    BFS(adjMatrix, d, p, start);
    return 0;
}