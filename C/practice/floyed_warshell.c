#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4

// Function to implement the Floyd-Warshall algorithm
void floydWarshall(int graph[V][V])
{
    // dist[][] will hold the shortest distances between every pair of vertices
    int dist[V][V];

    // Initialize the solution matrix the same as the input graph matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == 0 && i != j)
            {
                dist[i][j] = INT_MAX; // No path between the vertices
            }
            else
            {
                dist[i][j] = graph[i][j]; // Distance from i to j
            }
        }
    }

    // Floyd-Warshall algorithm: updating the distances
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j]; // Update the distance
                }
            }
        }
    }

    // Print the shortest distance matrix
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

// Main function
int main()
{
    int graph[V][V] = {
        {0, 5, 0, 10},
        {0, 0, 3, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};

    floydWarshall(graph);

    return 0;
}
