#include<stdio.h>
int power(int a, int n){
    if(n == 0) return 1;
    int halfpow = power(a, n/2);
    return (n % 2 == 0) ? halfpow * halfpow : halfpow * halfpow * a;
}
void main(){
    int n = 5;
    int a = 2;
    printf("%d", power(a, n));
}