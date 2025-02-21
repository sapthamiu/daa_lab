#include<stdio.h>
#define MAX 100

int adjmat[MAX][MAX];
int indeg[MAX];
int queue[MAX];
int front = 0, rear = 0;
int toposort[MAX];
int ind = 0;

void topoSort(int n){
    for(int i = 0; i < n; i++)
        if(indeg[i] == 0)           //potential source
            queue[rear++] = i;
    
    while(front < rear){
        int v = queue[front++];
        toposort[ind++] = v;

        for(int i = 0; i < n; i++)
            if(adjmat[v][i]){        //edges from v to i exist
                indeg[i]--;
                if(indeg[i] == 0)
                    queue[rear++] = i;
            }
    }
    if(ind != n){
        printf("Cycle detected. Topo sort not possible\n");
        return;
    }

    printf("Topological Sort: ");
    for(int i = 0; i < ind; i++)
        printf("%d ", toposort[i]);
    printf("\n");
}

void main(){
    int nv, ne;
    int u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &nv);

    printf("Enter the number of edges: ");
    scanf("%d", &ne);

    for(int i = 0; i < nv; i++){
        for(int j = 0; j < nv; j++)
            adjmat[i][j] = 0;
        indeg[i] = 0;
    }
    printf("Enter the edges (src dst):\n");
    for(int i = 0; i < ne; i++){
        scanf("%d %d", &u, &v);
        adjmat[u][v] = 1;
        indeg[v]++;
    }
    topoSort(nv);
}