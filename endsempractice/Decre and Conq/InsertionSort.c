#include<stdio.h>
void insertionSort(int A[], int n){
    int i, j;
    for(i = 1; i < n; i++){
        int key = A[i];
        for(j = i-1; j >= 0 && (A[j] > key); j--)
            A[j+1] = A[j];
        A[j+1] = key;
    }
}
void main(){
    int n = 6;
    int A[] = {7, 4, 5, 4, 1, -3};
    insertionSort(A, n);
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
}