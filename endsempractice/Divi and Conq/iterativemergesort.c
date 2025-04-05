#include<stdio.h>
#include<stdlib.h>
#define MAX 20
void merge(int *A, int *B, int *C, int p, int q){
    int i = 0, j = 0, k = 0;
    while(i < p && j < q){
        if(B[i] <= C[j])
            A[k++] = B[i++];
        else A[k++] = C[j++];
    }
    while(i < p) A[k++] = B[i++];
    while(j < q) A[k++] = C[j++];
}
void mergesort(int* A, int n){
    int B[MAX], C[MAX];
    for(int size = 1; size < n; size *= 2)
        for(int left = 0; left < n; left += 2*size){
            int mid = left + size;
            int right = left + 2*size < n ? left + 2*size : n;
            int p = mid < n ? (mid - left) : 0;
            int q = right - mid;

            for(int i = 0; i < p; i++)
                B[i] = A[left + i];
            for(int i = 0; i < q; i++)
                C[i] = A[mid + i];
            merge(A + left, B, C, p, q);
        }
}

void main(){
    int A[] = {6, 5, 4, 1, 2};
    int n = 5;
    mergesort(A, n);
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
}
