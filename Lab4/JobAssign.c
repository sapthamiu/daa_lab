#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define MAX_N 10

int minCost = INT_MAX;
int bestAssign[MAX_N];

void swap(int* a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(int* arr, int start, int end){
    while(start < end){
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

int calCost(int N, int costMat[MAX_N][MAX_N], int assign[MAX_N]){
    int totalCost = 0;
    for(int i = 0; i < N; i++)
        totalCost += costMat[i][assign[i]];
    return totalCost;
}
int nextPerm(int arr[], int n){
    int bp = n-2;                         //last but one element
    while(bp >= 0 && arr[bp] >= arr[bp+1])  //find breakpoint
        bp--;
    if(bp >= 0){                          //found a valid breakpoint
        int j = n-1;
        while(arr[j] <= arr[bp])          //find next greater element to bp element
            j--;
        swap(&arr[bp], &arr[j]);
    }
    else return 0;
    int left = bp+1, right = n-1;
    reverse(arr, left, right);
    return 1;
}
void jobAssign(int N, int costMat[MAX_N][MAX_N]){
    int assign[MAX_N];
    for(int i=0; i < N; i++){
        assign[i] = i;
    }
    do{
        int totalCost = calCost(N, costMat, assign);
        if(totalCost < minCost){
            minCost = totalCost;
            for(int i = 0; i < N; i++)
                bestAssign[i] = assign[i];
        }
    }while(nextPerm(assign, N));
}

int main(){
    int N;
    printf("Enter the no. of workers/jobs: ");
    scanf("%d", &N);
    if(N <= 0 || N > MAX_N){
        printf("Invalid no. of workers/tasks. ");
        exit(0);
    }
    int costMat[MAX_N][MAX_N];
    printf("Enter the cost matrix:\n");
    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++){
        printf("Cost for worker %d to task %d: ", i+1, j+1);
        scanf("%d", &costMat[i][j]);
    }
    jobAssign(N, costMat);
    printf("Optimial job assignment:\n");
    for(int i = 0; i < N; i++)
        printf("Worker %d -> task %d\n", i+1, bestAssign[i]+1);
    printf("Minimum cost of assignment: %d\n",minCost);

}