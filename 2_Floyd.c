#include<stdio.h>
#define INF 99999
#define max 10
void floyd(int n, int D[max][max]){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(D[i][k] != INF && D[k][j] != INF)
					if(D[i][j] > D[i][k] + D[k][j])
						D[i][j] = D[i][k] + D[k][j];
}
void main(){
	int n, dist[max][max];
	printf("Enter no. of nodes: ");
	scanf("%d", &n);
	printf("Enter distance matrix: ");
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &dist[i][j]);
	floyd(n, dist);
	printf("Shortest path matrix:\n");
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			printf("%d ", dist[i][j]);
		printf("\n");
	}
}
