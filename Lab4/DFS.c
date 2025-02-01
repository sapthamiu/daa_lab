#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int visited[MAX];
int pushOrder[MAX];
int popOrder[MAX];
int pushInd = 0;
int popInd = 0;

void dfs(int adjMat[MAX][MAX], int n, int vertex){
	visited[vertex] = 1;
    pushOrder[pushInd++] = vertex;

    for (int i = 0; i < n; i++) {
        if (adjMat[vertex][i]==1 && !visited[i])
            dfs(adjMat, n, i);
    }
   popOrder[popInd++] = vertex;
}
void DFS(int adjMat[MAX][MAX], int n){
	for(int v = 0; v < n; v++)
		if(!visited[v])
			dfs(adjMat, n, v);
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

    printf("Performing Depth-First Search (DFS)...\n");
    DFS(adjMat, vertices);
    
    // Print push and pop order
    printOrder(pushOrder, pushInd, "Push");
    printOrder(popOrder, popInd, "Pop");

    return 0;
}
