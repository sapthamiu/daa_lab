#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// int* primefactors(int n, int* size){
// 	if (n == 0) {
//         *size = 0;
//         return NULL; 
//     }
// 	int* factors = malloc(n * sizeof(int));
// 	int index = 0;
// 	while(n % 2 == 0){
// 		factors[index++] = 2;
// 		n /= 2;
// 	}
// 	for(int i = 3; i * i <= n; i += 2)
// 		while(n % i == 0){
// 			factors[index++] = i;
// 			n /= i;
// 		}
// 	if(n>2) factors[index++] = n;
// 	*size = index;
// 	return factors;
// }
int fibonacci(int n){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}
void primefactors(int n, int factors[], int* count, int* opcount){
if(n < 2) return;
	*count = 0;
	while(n % 2 == 0){
		(*opcount)++;
		factors[(*count)++] = 2;
		n /= 2;
	}
	for(int i = 3; i * i <= n; i += 2)
		while(n % i == 0){
			(*opcount)++;
			factors[(*count)++] = i;
			n /= i;
		}
	if(n > 1){
		(*opcount)++;
		factors[(*count)++] = n;
	}
}
int MS(int n1, int n2, int* opcount){
	int factorsA[100], factorsB[100];
	int countA, countB;
	primefactors(n1,factorsA,&countA, opcount);
	primefactors(n2, factorsB, &countB, opcount);
	int gcd = 1;
	int i = 0, j = 0;
	while(i < countA && j < countB){
		if(factorsA[i] == factorsB[j]){
		//	(*opcount)++;
			gcd *= factorsA[i];
			i++,j++;
		}
		else if(factorsA[i] < factorsB[j]) i++;
		else j++;
	}
	return gcd;
}

void main(){
	int a, b;
	int opcount=0;
	printf("Enter two numbers: ");
	srand(time(NULL));
	int n = rand() % 10 + 1;
	a = fibonacci(n);
	b = fibonacci(n+1);
	// scanf("%d%d", &a,&b);
	printf("GCD of %d and %d = %d", a, b, MS(a,b, &opcount));
	printf("\nm+n = %d\t operation count = %d", a+b, opcount);
}
