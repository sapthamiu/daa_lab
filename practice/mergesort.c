#include<stdio.h>
#define MAX 10
void merge(int b[], int p, int c[], int q, int a[]){
    int i = 0, j = 0, k = 0;
    while(i < p && j < q){
        if(b[i] <= c[j]) a[k++] = b[i++];
        else a[k++] = c[j++];
    }
    while(i < p) a[k++] = b[i++];
    while(j < q) a[k++] = c[j++];
}
void mergesort(int a[], int n){
    if(n > 1){
        int b[MAX], c[MAX];
        int mid = n/2;
        for(int i = 0; i < mid; i++)
            b[i] = a[i];
        for(int i = mid; i < n; i++)
            c[i - mid] = a[i];
        mergesort(b, mid);
        mergesort(c, n-mid);
        merge(b, mid, c, n-mid, a);
    }
}
void main(){
    int a[] = {5, 4, 3, 2, 1};
    mergesort(a, 5);
    for(int i = 0; i < 5; i++)
        printf("%d ", a[i]);
}