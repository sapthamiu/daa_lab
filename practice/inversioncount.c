// count the number of inversion pairs in an array (inversion pair => i < j but A[i] > A[j])
#include<stdio.h>
#define MAX 10
void merge(int B[], int p, int C[], int q, int A[], int *icount){
    int i = 0, j = 0, k = 0;
    while(i < p && j < q){
        if(B[i] < C[j])
            A[k++] = B[i++];
        else{
            A[k++] = C[j++];
            (*icount) += p - i;
        }
    }
    while(i < p) A[k++] = B[i++];
    while(j < q) A[k++] = C[j++];
}

void mergesort(int A[], int n, int *icount){
    if(n > 1){
        int B[MAX], C[MAX];
        int mid = n/2;
        for(int i = 0; i < mid; i++)
            B[i] = A[i];
        for(int i = mid; i < n; i++)
            C[i-mid] = A[i];
        mergesort(B, mid, icount);
        mergesort(C, n - mid, icount);
        merge(B, mid, C, n-mid, A, icount);
    }
}
void main(){
    int a[] = {5, 4, 3, 2, 1};
    int icount = 0;
    mergesort(a, 5, &icount);
    printf("Inversion count: %d", icount);
    for(int i = 0; i < 5; i++)
        printf("\t%d", a[i]);
}