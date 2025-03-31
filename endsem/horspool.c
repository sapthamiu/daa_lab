#include<stdio.h>
#include<string.h>
#define size 256

void shifttable(char* P, int m, int table[]){
    for(int i = 0; i < size; i++)
        table[i] = m;
    for(int i = 0; i < m-1; i++)
        table[P[i]] = m - 1 - i;
}
int horspool(char* T, int n, char* P, int m){
    int table [size];
    shifttable(P, m, table);
    int i = m - 1;
    while(i < n){
        int k = 0;  //matched characters
        while(k < m && P[m-1-k] == T[i-k])
            k++;
        if(k == m)
            return i - m + 1;
        else{
            i += table[T[i]];
        }
    }
    return -1;
}
void main(){
    char T[] = "JIM_SAW_ME_IN_A_BARBERSHOP";
    char P[] = "BARBER";
    int n = strlen(T);
    int m = strlen(P);
    int ind = horspool(T, n, P, m);
    printf(ind == -1 ? "Not found" : "Index: %d", ind);
}