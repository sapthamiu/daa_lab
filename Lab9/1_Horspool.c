#include<stdio.h>
#include<string.h>
#define SIZE 256
int opcount = 0;
void shiftTable(char* P, int m, int table[]){
	for(int i = 0; i < SIZE; i++){			//initialise
		table[i] = m;
	}
	for(int j = 0; j < m-1; j++){			//build shift table
		table[P[j]] = m-1-j;
	}
}
int horspool(char* P, int m, char* T, int n){
	int table[SIZE];
	shiftTable(P, m, table);
	int i = m-1;							//last character of pattern
	while(i < n){							//until the end of text
		int k = 0; 							//no. of matched characters
		while(k < m && P[m-1-k] == T[i-k]){
			opcount++;
			k++;
		}
		if(k == m)
			return i-m+1;
		else{
		 	i += table[T[i]];
		 	opcount++;
		}
	}	
	return -1;
}

void main(){
	char Text[100];
	printf("Enter text: ");
	scanf("%s", Text);
	int n = strlen(Text);
	char P[50];
	printf("Enter pattern: ");
	scanf("%s", P);	
	int m = strlen(P);
	printf("Word found at position %d", horspool(P, m, Text, n));
	printf("\nOPCOUNT: %d", opcount);
}