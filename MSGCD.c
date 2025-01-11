#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* primefactors(int n, int* size){
	if (n == 0) {
        *size = 0;
        return NULL; 
    }
	int* factors = malloc(n * sizeof(int));
	int index = 0;
	while(n % 2 == 0){
		factors[index++] = 2;
		n /= 2;
	}
	for(int i = 3; i * i <= n; i += 2)
		while(n % i == 0){
			factors[index++] = i;
			n /= i;
		}
	if(n>2) factors[index++] = n;
	*size = index;
	return factors;
}

int MS(int n1, int n2){
	int s1,s2;
	int *pf1 = primefactors(n1,&s1);
	int *pf2 = primefactors(n2, &s2);
	int gcd = 1;
	int i = 0, j = 0;
	while(i < s1 && j < s2){
		if(pf1[i] == pf2[j]){
			gcd *= pf1[i];
			i++,j++;
		}
		else if(pf1[i] < pf2[j]) i++;
		else j++;
	}
	free(pf1);
	free(pf2);
	return gcd;
}

void main(){
	int a, b;
	printf("Enter two numbers: ");
	scanf("%d%d", &a,&b);
	printf("GCD = %d", MS(a,b));
}
