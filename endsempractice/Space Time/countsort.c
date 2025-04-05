#include<stdio.h>
#define MAX 10
int count[MAX] = {0};
int sorted[MAX];
void sortcount(int A[], int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++){
            if(A[i] >= A[j]) count[i]++;
            else count[j]++;
        }
    for(int i = 0; i < n; i++)
        sorted[count[i]] = A[i];
    printf("\nSorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", sorted[i]);
}
void main(){
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = 7;
    sortcount(A, n);
}