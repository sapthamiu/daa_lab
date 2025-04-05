#include<stdio.h>
#include<stdlib.h>
#define swap(a, b){int temp = *a; *a = *b; *b = temp;}

int partition(int A[], int l, int r){
    int i = l+1, j = r;
    int p = l;
    while(i < j){
        while(A[i] <= A[p]) i++;
        while(A[j] > A[p]) j--;
        if(i < j) swap(&A[i], &A[j]);
    }
    swap(&A[j], &A[p]);
    return j;
}
void quicksort(int A[], int l, int r){
    if(l < r){
        int s = partition(A, l, r);
        quicksort(A, l, s-1);
        quicksort(A, s+1, r);
    }
}
void main(){
    int A[] = {6, 5, 2, 1, 4};
    quicksort(A, 0, 4);
    for(int i = 0; i < 5; i++){
        printf("%d ", A[i]);
    }
}