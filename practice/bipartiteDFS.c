//check if graph is bipartite using DFS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

int adj[MAX][MAX];
int color[MAX];

bool isBi(int n, int col, int v){
    color[v] = col;
    for(int u = 0; u < n; u++){
        if(adj[v][u] == 1){
            if(color[u] == -1){
                if(!isBi(n, 1-col, u))
                    return false;
            } else if(color[u] == color[v])
                return false;
        }
    }
    return true;
}
bool checkBi(int n){
    for(int i = 0; i < n; i++){
        if(color[i] == -1)
            if(!(isBi(n, 0, i)))
                return false;
    }
    return true;
}
void main(){
    int nv, ne, u, v;
    printf("Enter no. of vertices and edges: ");
    scanf("%d%d", &nv, &ne);
    for(int i = 0; i < nv; i++){
        for(int j = 0; j < nv; j++)
            adj[i][j] = 0;
        color[i] = -1;
    }
    printf("Enter the edges(src dst): ");
    for(int i = 0; i < ne; i++){
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    if(checkBi(nv))
        printf("Bipartite");
    else printf("Not Bipartite");
}