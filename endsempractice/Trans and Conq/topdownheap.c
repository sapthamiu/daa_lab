#include<stdio.h>
#include<stdlib.h>
#define swap(a, b){int temp = a; a = b; b = temp;}
#define MAX 20

void siftup(int *H, int cur){
    int parent = cur / 2;
    while(cur > 0 && H[parent] < H[cur]){
            swap(H[cur], H[parent]);
            cur = parent;
            parent = cur / 2;
    }
}
void main(){
    int H[MAX], n;
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