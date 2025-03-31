#include<stdio.h>
#include<stdlib.h>
#define swap(a, b){int temp = a; a = b; b = temp;};
int partition(int* A, int l, int r){
    int p = l;
    int i = l;
    int j = r+1;
    while(i < j){
        do{
            i++;
        }while(A[i] <= A[p]);
        do{
            j--;
        }while(A[j] > A[p]);
        swap(A[i], A[j]);
    }
    swap(A[i], A[j]);   //undo
    swap(A[j], A[p]);
    return j;
}

void quicksort(int* A, int l, int r){
    if(l < r){
        int s = partition(A, l, r);
        quicksort(A, l, s-1);
        quicksort(A, s+1, r);
    }
}

void main(){
    int arr[] = {8, 3, 2, 9, 7, 1, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n-1);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}