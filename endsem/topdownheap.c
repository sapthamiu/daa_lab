#include<stdio.h>
#include<stdlib.h>
#define swap(a, b){int temp = a; a = b; b = temp;}
void siftup(int* H, int current){
    int parent = current / 2;
    while(current > 0 && H[parent] < H[current]){
        swap(H[parent], H[current]);
        current = parent;
        parent = current / 2;
    }
}
void main(){
    int H[100], n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 1; i <= n; i++){
        scanf("%d", &H[i]);
        siftup(H, i);
    }
    printf("Max heap: ");
    for(int i = 1; i <= n; i++)
        printf("%d ", H[i]);
}