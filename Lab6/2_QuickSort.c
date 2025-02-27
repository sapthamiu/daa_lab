#include<stdio.h>
#define swap(x, y){int temp = x; x = y; y = temp;}

int partition(int A[], int l, int r, int* opcount){
    int p = l;
    int i = l, j = r;

    while(i < j){
        while(A[i] <= A[p]){ 
            i++;
            (*opcount)++;
        }
        while(A[j] > A[p] && j>l){ 
            j--;
            (*opcount)++;
        }

        if(i < j) swap(A[i], A[j]);
    }
    swap(A[p], A[j]);
    return j;
}

void quicksort(int A[], int l, int r, int* opcount){
    if(l < r){
        int s = partition(A, l, r, opcount);
        quicksort(A, l, s-1, opcount);
        quicksort(A, s+1, r, opcount);
    }
}

void main(){
    int n, opcount = 0;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int A[100];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    quicksort(A, 0, n-1, &opcount);
    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\nOpcount: %d", opcount);
}