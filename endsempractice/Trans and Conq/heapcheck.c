#include<stdio.h>
int isMaxHeap(int A[], int n){
    for(int i = 1; i <= n/2; i++){
        int left = 2*i;
        int right = 2*i + 1;
        if(left < n && A[left] > A[i])  return 0;
        if(right < n && A[right] > A[i]) return 0;
    }
    return 1;
}
void main(){
    int A[10], n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    printf(isMaxHeap(A, 6) ? "Heap": "Not Heap");
}