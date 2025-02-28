//Find majority element(>n/2) in an array using divide and conquer
#include<stdio.h>
#include<stdlib.h>
int freq(int a[], int l, int r, int key){
    int f = 0;
    for(int i = l; i <= r; i++)
        if(a[i] == key)
            f++;
    return f;
}

int major(int a[], int l, int r){
    if(l == r) return a[l];

    int mid = (l + r)/2;

    int left = major(a, l, mid);
    int right = major(a, mid+1, r);

    if(left == right) return left; 
    int leftcount = freq(a, l, r, left);
    int rightcount = freq(a, l, r, right);
    int n = r - l + 1;
    if(leftcount > n/2) return left;
    if(rightcount > n/2) return right;
    return -1;
}

void main(){
    int a[] = {2, 2, 2, 4, 4, 4};
    printf("%d ", major(a, 0, 5));
}