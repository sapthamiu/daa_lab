#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void mergesort(int A[], int n){
	if(n > 1){
		int B[MAX];
		int C[MAX];
		int mid = n/2;
		for(int i = 0; i < mid; i++)
			B[i] = A[i];
		for(int i = mid; i < n; i++)
			C[i-mid] = A[i];
		mergesort(B, mid);
		mergesort(C, n-mid);
		merge(B, mid, C, n-mid, A, n);
	}
}

void merge(int B[MAX], int p, int C[MAX], int q, int A[MAX], int n){
	int i = 0, j = 0, k = 0;
	while(i < p && j < q){
		if(B[i] <= C[j])
			A[k++] = B[i++];
		else A[k++] = C[j++];
	}
	if(i == p)
		while(j < q)
			A[k++] = C[j++];
	else while(i < p)
			A[k++] = B[i++];
}

void main() {
    int n, A[MAX];
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n > MAX) {
        printf("Array size exceeds maximum limit of %d elements.\n", MAX);
        return 1;
    }

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    mergesort(A, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
