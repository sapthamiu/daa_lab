#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int opcount = 1;

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int n, int sub1[], int size1, int sub2[], int size2, int sum1, int sum2, int index){
    opcount++;
    if(index == n){
        if(sum1 == sum2){
            print(sub1, size1);
            print(sub2, size2);
            return 1;
        }
        return 0;
    }
    sub1[size1] = arr[index];
    if(partition(arr, n, sub1, size1 + 1, sub2, size2, sum1 + arr[index], sum2, index + 1)){
        return 1;
    }
    sub2[size2] = arr[index];
    if(partition(arr, n, sub1, size1, sub2, size2 + 1, sum1, sum2 + arr[index], index + 1)){
        return 1;
    }
    return 0;
}

void main(){
    //int arr[20], n, sub1[20], sub2[20];
    // srand(time(0)); // Seed the random number generator
    // n = rand() % 20 + 1; // Generate a random number between 1 and 20
    // printf("Number of elements: %d\n", n);
    // int sum = 0;
    // for(int i = 0; i < n; i++){
    //     arr[i] = rand() % 100; // Generate random elements between 0 and 99
    //     sum += arr[i];
    // }
    // printf("Elements: ");
    // print(arr, n);

    int n, sub1[20], sub2[20];
    // printf("Enter the number of elements: ");
    // scanf("%d", &n);
    n = 10;
    int arr[10] = {2, 4, 6, 10, 20, 50, 100, 200, 400, 800}; 
    //printf("Enter the elements: ");
    int sum = 0;
    // for(int i = 0; i < n; i++){
    //     scanf("%d", &arr[i]);
    //     sum += arr[i];
    // }
    if(sum % 2 != 0){
        printf("Partition not possible\n");
        exit(0);
    }
    if(partition(arr, n, sub1, 0, sub2, 0, 0, 0, 0) == 1){
        printf("Partition possible\n");
    }
    else{
        printf("Partition not possible\n");
    }
    printf("Number of subsets generated: %d\n", opcount);
}