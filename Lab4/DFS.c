#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100  // Maximum number of vertices

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_NODES];
} Graph;

// Global variables
int visited[MAX_NODES];    // Array to track visited vertices
int pushOrder[MAX_NODES];  // Array to store push order
int popOrder[MAX_NODES];   // Array to store pop order
int pushIndex = 0;         // Index for push order
int popIndex = 0;          // Index for pop order

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void DFS(Graph* graph);
void dfs(Graph* graph, int vertex);
void printOrder(int order[], int size, const char* label);

// Create a graph with given vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        visited[i] = 0;  // Mark all vertices as unvisited
    }
    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add the reverse edge
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Perform DFS traversal for the entire graph
void DFS(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        if (visited[v] == 0) {  // If vertex is unvisited
            dfs(graph, v);
        }
    }
}

// Recursive DFS function for a single vertex
void dfs(Graph* graph, int vertex) {
    // Push order: Mark the vertex as visited and log it
    visited[vertex] = 1;
    pushOrder[pushIndex++] = vertex;

    // Explore all adjacent vertices
    Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (visited[adjVertex] == 0) {  // If adjacent vertex is unvisited
            dfs(graph, adjVertex);
        }
        temp = temp->next;
    }

    // Pop order: Log the vertex when exploration is complete
    popOrder[popIndex++] = vertex;
}

// Print the push/pop order
void printOrder(int order[], int size, const char* label) {
    printf("%s Order:\n", label);
    for (int i = 0; i < size; i++) {
        printf("%d ", order[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Performing Depth-First Search (DFS)...\n");
    DFS(graph);
    
    // Print push and pop order
    printOrder(pushOrder, pushIndex, "Push");
    printOrder(popOrder, popIndex, "Pop");

    return 0;
}
