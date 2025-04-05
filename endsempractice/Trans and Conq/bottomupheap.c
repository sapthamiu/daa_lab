#include<stdio.h>
#include<stdlib.h>
#define swap(a, b){int temp = a; a = b; b = temp;}
#define MAX 20
void heapify(int* H, int n){
    for(int i = n/2; i >= 1; i--){
        int parent = i;
        int ogparent = H[parent];
        int isheap = 0;
        while(!isheap && 2*parent <= n){
            int child = 2*parent;
            if(child + 1 <= n && H[child] < H[child+1])
                child ++;
            if(ogparent >= H[child]) isheap = 1;
            else{
                H[parent] = H[child];
                parent = child;
            }
        }
        H[parent] = ogparent;
    }
}
void heapsort(int* H, int n){
    heapify(H, n);
    for(int i = n; i > 1; i--){
        swap(H[1], H[i]);   //swap root and last node
        heapify(H, i-1);    //size of heap reduced by one
    }
}
void main(){
    int A[MAX];
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    heapsort(A, n);
    for(int i = 1; i <= n; i++)
        printf("%d ", A[i]);
}