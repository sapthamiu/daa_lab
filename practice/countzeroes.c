//Count the Number of Zeros in an Array using Decrease and Conquer
#include<stdio.h>
int count0(int arr[], int n){
    if(n == 0) return 0;
    return (arr[n-1] == 0) ? count0(arr, n-1) + 1 : count0(arr, n-1);
}
void main(){
    int arr[] = {0, 1, 2, 3, 0, 4, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", count0(arr, n));
}