#include<stdio.h>
void heaptopdown(int h[], int n){
    for(int i = 2; i <= n; i++){        //start inserting from 1st non-root node(1-based index)
        int k = i, v = h[k];
        while(k > 1 && h[k/2] < v){
            h[k] = h[k/2];
            k = k/2;
        }
        h[k] = v;
    }
}
void main(){
    int n, h[100];
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    heaptopdown(h, n);
    printf("Max heap: ");
    for(int i = 1; i <= n; i++)
        printf("%d ", h[i]);
}