#include<stdio.h>
#include<string.h>
#define swap(x, y){char* temp = x; x = y; y = temp;}

void bubblestring(char* a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(strcmp(a[j], a[j+1]) > 0)
                swap(a[j], a[j+1]);
        }
    }
}
void main(){
    char* a[] = {"apple", "mango", "aaple", "banana", "cherry"};
    bubblestring(a, 5);
    printf("Sorted: ");
    for(int i = 0; i < 5; i++)
        printf("%s ", a[i]);
}