#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];     // Adjacency matrix
int inDegree[MAX];     // Array to store in-degrees
int n;                 // Number of vertices

void topologicalSort() {
    int sorted[MAX];   // Array to store topological order
    int count = 0;     // Count of sorted vertices

    // Compute initial in-degrees
    for (int i = 0; i < n; i++) {
        inDegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (adj[j][i] == 1) {
                inDegree[i]++;
            }
        }
    }

    while (count < n) {
        int foundSource = 0;

        // Find a vertex with in-degree 0
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                foundSource = 1;
                inDegree[i] = -1;  // Mark as removed
                sorted[count++] = i;

                // Reduce in-degree of neighbors
                for (int j = 0; j < n; j++) {
                    if (adj[i][j] == 1) {
                        inDegree[j]--;
                    }
                }
                break;
            }
        }

        if (!foundSource) {
            printf("The graph has a cycle. Topological sort not possible.\n");
            return;
        }
    }

    // Print topological order
    printf("Topological Sort: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");
}

int main() {
    int e, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter the edges (u v) format:\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort();

    return 0;
}