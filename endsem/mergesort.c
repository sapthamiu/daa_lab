#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void merge(int* A, int* B, int* C, int p, int q){
    int i = 0, j = 0, k = 0;
    while(i < p && j < q){
        if(B[i] <= C[j])
            A[k++] = B[i++];
        else 
            A[k++] = C[j++];
    }
    while(i < p) A[k++] = B[i++];
    while(j < q) A[k++] = C[j++];
}
void mergesort(int* A, int n){
    int B[MAX], C[MAX];
    for(int i = 0; i < n/2; i++)
        B[i] = A[i];
    for(int i = n/2; i < n; i++)
        C[i - n/2] = A[i];
    if(n > 1){
        mergesort(B, n/2);
        mergesort(C, n-n/2);
        merge(A, B, C, n/2, n-n/2);
    }
}

void main(){
    int arr[] = {8, 3, 2, 9, 7, 1, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}