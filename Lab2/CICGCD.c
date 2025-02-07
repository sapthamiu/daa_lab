#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int fibonacci(int n){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}
int CIC(int n1, int n2, int* opcount){
	
	int t = n1 < n2 ? n1 : n2;
	while(t != 0 && (n1 % t != 0 || n2 % t != 0)){
		t--;
		(*opcount)++;
	}
	return t;
}
void main(){
	int a, b, count = 1;
	printf("Enter two numbers: ");
	srand(time(NULL));
	int n = rand() % 10 + 1;
	a = fibonacci(n);
	b = fibonacci(n+1);
	
	// scanf("%d %d", &a, &b);
	printf("GCD  of %d and %d = %d", a, b, CIC(a,b, &count));

	printf("\n(m+n): %d Operation count: %d", a+b, count);
}

