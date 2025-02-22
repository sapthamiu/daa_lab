#include<stdio.h>
#include<stdlib.h>
#define swap(x, y){int temp = x; x = y; y = temp;}
#define MAX 5
int partition(int A[],int l, int r){
	int p = l;
	int i = l;
	int j = r+1;
	while(i < j){
		while(A[i] < A[p]) i++;
		while(A[j] > A[p]) j--;
		if(i < j)
			swap(A[i], A[j]);
	}
	swap(A[p], A[j]);
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
	int n, a[MAX];
	printf("Enter size: ");
	scanf("%d", &n);
	printf("Enter elements: ");
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Unsorted: ");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	quicksort(a, 0, n-1);
	printf("\nSorted: ");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
}