#include<stdio.h>
#include<stdlib.h>
#define swap(x, y){int temp = x; x = y; y = temp;}
int partition(int a[], int l, int r){
    int i = l, j = r, p = l;
    while(i < j){
        while(a[i]<= a[p]) i++;
        while(a[j] > a[p] && j > l) j--;
        if(i < j) swap(a[i], a[j]);
    }
    swap(a[j], a[p]);
    return j;
}
int quickselect(int a[], int l, int r, int k){
    if(l < r){
        int s = partition(a, l, r);
        if(s == k-1) return a[s];
        else if(s < k-1) quickselect(a, s+1, r, k);
        else quickselect(a, l, s-1, k);
    }
}

void main(){
    int arr[] = {5, 4, 3, 2, 1};
    printf("2nd smallest element: %d",quickselect(arr, 0, 4, 2) );
}