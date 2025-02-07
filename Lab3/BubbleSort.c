#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void bubbleSort(int arr[], int n, int *opcount) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            // (*opcount)++;
            if (arr[j] > arr[j+1]) {
                (*opcount)++;
               int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[30];
    int n = 20;
    int opcount=0;
    srand(time(0));
    int temp = rand() % 100 + n;
    for(int i = 0; i < n; i++){
       // arr[i] = rand() % 100;
       arr[i] = temp + i;
    }
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    bubbleSort(arr, n, &opcount);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("\nn = %d \t opcount = %d\n", n, opcount);
    return 0;
}