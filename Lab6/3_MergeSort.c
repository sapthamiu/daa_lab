#include<stdio.h>
#include<stdlib.h>
void merge(int B[], int p, int C[], int q, int A[], int* opcount, int* icount){
    int i = 0, j = 0, k = 0;
    while(i < p && j < q){
        (*opcount)++;
        if(B[i] <= C[j])
            A[k++] = B[i++];
        else{
            A[k++] = C[j++];
            (*icount) += (p - i);
        }
    }
    while(i < p)
        A[k++] = B[i++];
    while(j < q)
        A[k++] = C[j++];
}

void mergesort(int A[], int n, int* opcount, int* icount){
    if(n > 1){
        int mid = n/2;
        int* B = malloc(mid * sizeof(int));
        int* C = malloc((n-mid) * sizeof(int));

        for(int i = 0; i < mid; i++)
            B[i] = A[i];
        for(int i = mid; i < n; i++)
            C[i-mid] = A[i];

        mergesort(B, mid, opcount, icount);
        mergesort(C, n-mid, opcount, icount);
        merge(B, mid, C, n-mid, A, opcount, icount);

        free(B);
        free(C);
    }
}

void main(){
    int n, opcount = 0, icount = 0;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int A[100];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    mergesort(A, n, &opcount, &icount);
    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\nOpcount: %d\nInversion count: %d", opcount,icount);
}