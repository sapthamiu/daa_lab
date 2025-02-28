#include<stdio.h>
#define swap(x, y){int temp = x; x = y; y = temp;}

int partition(int A[], int l, int r){
    int i = l, j = r, p = l;
    while(i < j){
        while(A[i] < A[p]) i++;
        while(A[j] > A[p]) j--;
        if(i < j) swap(A[i], A[j]);
    }
    swap(A[j], A[p]);
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
    int n;
    int a[100];
    printf("enter nos:");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, n-1);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}