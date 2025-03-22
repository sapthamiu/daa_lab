#include<stdio.h>
#define max 10
void warshall(int n, int A[max][max]){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				A[i][j] = A[i][j] || (A[i][k] && A[k][j]);
}
void main(){
	int n, adj[max][max];
	printf("Enter no. of nodes: ");
	scanf("%d", &n);
	printf("Enter adjacency matrix: ");
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &adj[i][j]);
	warshall(n, adj);
	printf("Transitive closure:\n");
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			printf("%d ", adj[i][j]);
		printf("\n");
	}
}