#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

int visited[MAX];   // Track visited vertices
int bfsOrder[MAX];  // Store BFS order
int bfsInd = 0;     // Index for BFS order

void bfs(int adjMat[MAX][MAX], int n, int startVertex) {
    int queue[MAX], front = 0, rear = 0;
    
    queue[rear++] = startVertex;
    visited[startVertex] = 1;
    
    while (front < rear) {
        int currentVertex = queue[front++];
        bfsOrder[bfsInd++] = currentVertex;
        
        for (int i = 0; i < n; i++) {
            if (adjMat[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void BFS(int adjMat[MAX][MAX], int n) {
    for (int v = 0; v < n; v++) {
        if (!visited[v])
            bfs(adjMat, n, v);
    }
}

void printOrder(int order[], int n, const char* label) {
    printf("%s Order:\n", label);
    for (int i = 0; i < n; i++) {
        printf("%d ", order[i]);
    }
    printf("\n");
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int adjMat[MAX][MAX] = {0};  // Initialize adjacency matrix to 0

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adjMat[src][dest] = 1;  // Set edge from src to dest
        adjMat[dest][src] = 1;  // Since the graph is undirected, set the reverse edge too
    }

    printf("Performing Breadth-First Search (BFS)...\n");
    BFS(adjMat, vertices);
    
    // Print BFS order
    printOrder(bfsOrder, bfsInd, "BFS");

    return 0;
}