#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to initialize the adjacency matrix
void initializeMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0; // Initialize all edges to 0 (no edge)
        }
    }
}

// Function to add an edge to the adjacency matrix
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int src, int dest) {
    graph[src][dest] = 1; // Add edge from src to dest
    graph[dest][src] = 1; // Since it's undirected, add edge from dest to src
}

// Function to print the adjacency matrix
void printMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int vertices, edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    initializeMatrix(graph, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Adjacency Matrix:\n");
    printMatrix(graph, vertices);

    return 0;
}
