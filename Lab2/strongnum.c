#include<stdio.h>
#include<stdlib.h>
int fact(int n){
    if(n <= 1)
        return 1;
    return n * fact(n-1);
}
int sumFact(int n){
    if(n == 0) return 0;
    return fact(n % 10) + sumFact(n / 10);
}
void main(){
    int n = 145;
    printf(sumFact(n) == n ? "Strong" : "Not Strong");
}