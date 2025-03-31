#include<stdio.h>
#include<stdlib.h>
#define swap(a, b){int temp = a; a = b; b = temp;}
void heapify(int* H, int n){
    for(int i = n/2; i >= 1; i--){
        int k = i, parent = H[k];
        int heap = 0;
        while(!heap && 2*k <= n){
            int j = 2*k;
            if(j < n && H[j] < H[j+1]) j++;
            if(parent >= H[j]) heap = 1;
            else{
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = parent;
    }
}
void heapsort(int* H, int n){
    for(int i = n; i >= 1; i--){
        swap(H[i], H[1]);
        heapify(H, i-1);
    }
}
void main(){
    int n;
    int a[100];
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    heapsort(a, n);
    printf("\nSorted array: ");
    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);
}