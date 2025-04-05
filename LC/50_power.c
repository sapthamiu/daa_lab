//Implement pow(x, n), which calculates x raised to the power n (i.e., xn)
#include<stdio.h>
int power(int x, int n){
    if(n == 0) return 1;
    if(n < 0){
        x= 1/x;
        n = -n;
    }
    return n%2 ? x * power(x, n/2)*power(x, n/2) : power(x, n/2) * power(x, n/2);
}
void main(){
    int x = 2;
    int n = 10;
    printf("%d", power(x, n));
}