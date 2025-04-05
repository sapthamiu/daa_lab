#include<stdio.h>
#include<stdlib.h>
#define MAX 7
int A[MAX][MAX];
int indegree[MAX];
int q[MAX];
int f = 0, r = 0;
int sorted[MAX];
int ind = 0;
void topoKahn(int n){
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0)    //potential source
            q[r++] = i;         //enqueue
    while(f < r){
        int u = q[f++];         //dequeue
        sorted[ind++] = u;
        for(int v = 0; v < n; v++)
            if(A[u][v]){
                indegree[v]--;
                if(indegree[v] == 0)
                    q[r++] = v;
            }
    }
    if(ind != n) return;
    for(int i = 0; i < n; i++)
        printf("%d ", sorted[i]);
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
            A[i][j] = 0;
        indegree[i] = 0;
    }
    printf("Enter the edges (src dst):\n");
    for(int i = 0; i < ne; i++){
        scanf("%d %d", &u, &v);
        A[u][v] = 1;
        indegree[v]++;
    }
    topoKahn(nv);
}