#include<stdio.h>
#include<stdlib.h>
int CIC(int n1, int n2, int* opcount){
	
	int t = n1 < n2 ? n1 : n2;
	while(t != 0 && (n1 % t != 0 || n2 % t != 0)){
		t--;
		(*opcount)++;
	}
	return t;
}
void main(){
	int a, b, count = 0;
	printf("Enter two numbers: ");
	scanf("%d%d", &a,&b);
	printf("GCD = %d", CIC(a,b, &count));
	printf("\nOperation count: %d", count);
}
