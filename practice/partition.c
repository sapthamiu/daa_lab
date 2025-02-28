#include<stdio.h>
#include<stdbool.h>
void partition(int arr[], int n){
    int totsubs = 1 << n;
    int totsum = 0;
    for(int i = 0; i < n; i++)
        totsum += arr[i];
    if(totsum % 2 != 0) {
        printf("Cannot partition");
        return;
    }
    int target = totsum / 2;
    for(int sub = 0; sub < totsubs; sub++){
        int subsum = 0;
        for(int i = 0; i < n ; i++){
            if(sub & (1<<i))
                subsum += arr[i];
        }
        if(subsum == target){
            printf("\nSubset 1: ");
            for(int i = 0; i < n ; i++)
                if(sub & (1 << i)) 
                    printf("%d ", arr[i]);
            printf("\nSubset 2: ");
            for(int i = 0; i < n; i++)
                if(!(sub & (1<<i)))
                    printf("%d ", arr[i]);
            return;
        }
    }
}

void main(){
    int arr[] = {1, 3, 4};
    partition(arr, 3);
}