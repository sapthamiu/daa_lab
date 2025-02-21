#include<stdio.h>
#include<stdbool.h>
#define MAX 100

int adjmat[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

bool cycleCheck(int v, int n, bool visited[], bool curPath[]){
    visited[v] = true;
    curPath[v] = true;

    for(int i = 0; i < n; i++)
        if(adjmat[v][i]){
            if(!visited[i]){
                if(cycleCheck(i, n, visited, curPath))
                    return true;
            }
            else if(curPath[i]) return true;
        }
    curPath[v] = false;
    return false;
}
bool isAcyclic(int n){
    bool visited[MAX] = {0};
    bool curPath[MAX] = {0};
    for(int i = 0; i < n; i++){
        if(!visited[i])
            if(cycleCheck(i, n, visited, curPath))
                return false;
    }
    return true;
}

void dfs(int v, int n){
    visited[v] = 1;
    for(int i = 0; i < n; i++)
        if(adjmat[v][i] && !visited[i])
            dfs(i, n);
    stack[++top] = v;       //push after traversing all adjacent nodes
}
void topoSort(int n){
    if(!isAcyclic(n)){
        printf("Cycle detected. Topo sort not possible.\n");
        return;
    }
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs(i, n);
    printf("Topological sort: ");
    while(top != -1)
        printf("%d ", stack[top--]);
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
        visited[i] = 0;
    }
    printf("Enter the edges (src dst):\n");
    for(int i = 0; i < ne; i++){
        scanf("%d %d", &u, &v);
        adjmat[u][v] = 1;
    }
    topoSort(nv);
}