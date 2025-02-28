//find the gcd of an m x n matrix

#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int rowgcd(int row[], int n){
    int rowgcd = row[0];
    for(int i = 1; i < n; i++){
        rowgcd = gcd(rowgcd, row[i]);
    }
    return rowgcd;
}

void main(){
    int arr[][3] = {{18, 27, 9}, {36, 45, 54}, {63, 72, 81}};
    int matgcd = rowgcd(arr[0], 3);
    for(int i = 1; i < 3; i++){
        matgcd = gcd(matgcd, rowgcd(arr[i], 3));
    }
    printf("MATGCD: %d", matgcd);
}