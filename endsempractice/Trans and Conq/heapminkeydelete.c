#include<stdio.h>
#include<limits.h>
#define swap(a, b){int temp = a; a = b; b = temp;}
void heapify(int *H, int n){
    for(int i = n/2; i >=1; i--){
        int parent = i;
        int ogparent = H[parent];
        int isheap = 0;
        while(!isheap && 2*parent <= n){
            int child = 2 * parent;
            if(child+1 <= n && H[child] < H[child+1]) child++;
            if(ogparent >= H[child]) isheap = 1;
            else{
                H[parent] = H[child];
                parent = child;
            }
        }
        H[parent] = ogparent;
    }
}
int findsmallest(int *H, int n){
    int smind = -1;
    int smval = INT_MAX;
    for(int i = n/2+1; i <= n; i++) //look in the leaf nodes
        if(H[i] < smval){
            smval = H[i];
            smind = i;
        }
    return smind;
}
void deletesmallest(int *H, int* n){
    int index = findsmallest(H, *n);
    if(index == -1) return;
    H[index] = H[*n];
    (*n)--;
    heapify(H, *n);
}
void main(){
    int A[10];
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    heapify(A, n);
    for(int i = 1; i <= n; i++)
        printf("%d ", A[i]);
    deletesmallest(A, &n);
    for(int i = 1; i <= n; i++)
        printf("%d ", A[i]);

}