#include<stdio.h>
#include<string.h>
#define SIZE 256
int BS[SIZE];
void badShift(char* P){
    int m = strlen(P);
    for(int i = 0; i < SIZE; i++)   //initialise to m
        BS[i] = m;
    for(int i = 0; i < m-1; i++)    //ignore last character
        BS[P[i]] = m - 1 - i;
}

int horspool(char* T, char* P){
    int m = strlen(P);
    int n = strlen(T);
    badShift(P);
    int i = m-1;    //start
    while(i < n){
        int k = 0;  //no. of matched characters
        while(k < m && P[m-1-k] == T[i-k]) k++;
        if(k == m) return i-m+1;
        else i += BS[T[i]];
    }
    return -1;
}
void main(){
    char* T = "JIM_SAW_ME_IN_A_BARBER_SHOP";
    char* P = "BARBER";
    printf("%d", horspool(T, P));
}