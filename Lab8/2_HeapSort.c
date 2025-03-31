#include<stdio.h>
#define swap(x,y){int temp = x; x = y; y = temp;}

void heapify(int a[], int i, int n){        //heapify the subtree at node i
    int heap = 0, j;
    while(!heap && 2*i <= n){
        j = 2*i;                        //left child
        if(j < n && a[j] < a[j+1])      //if right child > left child
            j++;
        if(a[i] >= a[j])
            heap = 1;                   //parent > child
        else{
            swap(a[i], a[j]);
            i = j;                      //move down
        }
    }
}
void heapsort(int a[], int n){
    //build max heap
    for(int i = n/2; i >= 1; i--)
        heapify(a, i, n);
    //max key deletion and restore heap
    for(int i = n; i >= 2; i--){
        swap(a[1], a[i]);               //swap root (max element) with last element
        heapify(a, 1, i-1);             //restore heap from new root
    }
}

void main(){
    int n;
    int a[100];
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    heapsort(a, n);
    printf("\nSorted array: ");
    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);
}