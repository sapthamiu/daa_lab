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

typedef struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

// Global variables
int visited[MAX_NODES];  // Array to track visited vertices
int bfsOrder[MAX_NODES]; // Array to store BFS order
int bfsIndex = 0;        // Index for BFS order

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
Queue* createQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isQueueEmpty(Queue* q);
void BFS(Graph* graph);
void bfs(Graph* graph, int startVertex);
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

// Create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

// Add an element to the queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// Remove an element from the queue
int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

// Perform BFS traversal for the entire graph
void BFS(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        if (visited[v] == 0) {  // If vertex is unvisited
            bfs(graph, v);
        }
    }
}

// Perform BFS for a single vertex
void bfs(Graph* graph, int startVertex) {
    Queue* q = createQueue();
    enqueue(q, startVertex);

    // Mark the starting vertex as visited and log it
    visited[startVertex] = 1;
    bfsOrder[bfsIndex++] = startVertex;

    while (!isQueueEmpty(q)) {
        int currentVertex = dequeue(q);

        // Explore all adjacent vertices
        Node* temp = graph->adjLists[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (visited[adjVertex] == 0) {  // If adjacent vertex is unvisited
                visited[adjVertex] = 1;
                bfsOrder[bfsIndex++] = adjVertex;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

// Print the BFS order
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

    printf("Performing Breadth-First Search (BFS)...\n");
    BFS(graph);


    // Print BFS order
    printOrder(bfsOrder, bfsIndex, "BFS");

    return 0;
}
