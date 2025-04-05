//Given an integer array nums, find the subarray with the largest sum, and return its sum.
//Use divide and conquer
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max(a, b)(a > b ? a : b)

int maxcrossSum(int *arr, int left, int mid, int right){
    int sum = 0;
    int lsum = INT_MIN;
    //find max sum on left of mid
    for(int i = mid; i >= left; i--){
        sum += arr[i];
        if(sum > lsum)  lsum = sum;
    }
    sum = 0;
    int rsum = INT_MIN;
    //find max sum on right of mid
    for(int i = mid+1; i <= right; i++){
        sum += arr[i];
        if(sum > rsum)  rsum = sum;
    }
    return max(lsum + rsum, max(lsum, rsum));
}
int maxsubSum(int *arr, int left, int right){
    if(left == right) return arr[left];
    int mid = (left + right) / 2;
    int lmax = maxsubSum(arr, left, mid);
    int rmax = maxsubSum(arr, mid+1, right);
    int crossmax = maxcrossSum(arr, left, mid, right);
    return max(max(lmax,rmax), crossmax);
}
void main(){
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;
    int maxsum = maxsubSum(arr, 0, n-1);
    printf("Max subarray sum: %d", maxsum);
}