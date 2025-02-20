#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int visited[MAX];
int popOrder[MAX];
int currentPath[MAX];
int popInd = 0;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void reverse(int arr[], int start, int end){
	while(start < end){
		swap(&arr[start], &arr[end]);
		start++;
		end--;
	}
}
int dfs(int adjMat[MAX][MAX], int n, int vertex){
	visited[vertex] = 1;
	currentPath[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (adjMat[vertex][i]){
			if(!visited[i]){
				if(dfs(adjMat, n, i)) //perform dfs
					return 1; 		//??
			}
			else if(currentPath[i])		//already traversed
				return 1;
        }
    }
    currentPath[vertex] = 0; //done with the path
   	popOrder[popInd++] = vertex;
   return 0;
}
int DFS(int adjMat[MAX][MAX], int n){
	for(int v = 0; v < n; v++)
		if(!visited[v]){
			if(dfs(adjMat, n, v))
				return 1;
		}
		return 0;
}

void topoDFS(int adjMat[MAX][MAX], int vertices){
	for(int i = 0; i < vertices; i++){
		visited[i] = 0;
		currentPath[i] = 0;
	}
	if(DFS(adjMat, vertices)){
		printf("Topological Sort not possible\n");
		return;
	}
	reverse(popOrder, 0, popInd - 1);
	printf("Topological Sort: ");
	for(int i = 0; i < popInd; i++)
		printf("%d ", popOrder[i]);
	printf("\n");
}

void main(){
	int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int adjMat[MAX][MAX] = {0}; 

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adjMat[src][dest] = 1;  
    }
    topoDFS(adjMat, vertices);
    
}