#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
struct Node
{
    int dest;
    struct Node *next;
};

// A structure to represent an adjacency list
struct AdjList
{
    struct Node *head;
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// The size of the array is the number of vertices.
struct Graph
{
    int vertices;
    struct AdjList *array;
};

// Function to create a new adjacency list node
struct Node *createNode(int dest)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'vertices' number of vertices
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Create an array of adjacency lists. Size of the array is 'vertices'
    graph->array = (struct AdjList *)malloc(vertices * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by setting head to NULL
    for (int i = 0; i < vertices; i++)
    {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add an edge from src to dest. A new node is added to the adjacency list of src.
    struct Node *newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src also.
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->vertices; ++v)
    {
        struct Node *currentNode = graph->array[v].head;
        printf("Vertex %d: ", v);
        while (currentNode)
        {
            printf("%d -> ", currentNode->dest);
            currentNode = currentNode->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int vertices, edges, src, dest;

    printf("Enter number of vertices: ");
    scanf_s("%d", &vertices);

    struct Graph *graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf_s("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (src dest): ");
        scanf_s("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Adjacency List:\n");
    printGraph(graph);

    return 0;
}
