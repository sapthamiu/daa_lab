#include<stdio.h>
int binsearch(int A[], int key, int l, int h){
    while(l <= h){
        int mid = (l + h)/2;
        if(key < A[mid])
            h = mid - 1;
        else if (key > A[mid])
            l = mid + 1;
        else //equal
            return mid + 1;
    }
    return l;
}
void bininsert(int A[], int n){
    int i, j;
    for(i = 1; i < n; i++){
        int key = A[i];
        int pos = binsearch(A, key, 0, i-1);
        for(int j = i-1; j >= pos; j--)
            A[j+1] = A[j];
        A[pos] = key;
    }
}
void main(){
    int n = 6;
    int A[] = {7, 4, 5, 4, 1, -3};
    bininsert(A, n);
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
}


