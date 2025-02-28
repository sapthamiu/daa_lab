#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int weights[MAX] = {7, 3, 4, 5};
int values[MAX] = {42, 12, 40, 25};
void knapsack(int n, int maxweight){
    int maxval = 0;
    int bestsub = 0;
    int totsubs = 1 << n;

    for(int sub = 0; sub < totsubs; sub++){
        int weight = 0, value = 0;
        for(int i = 0; i < n; i++){
            if(sub & (1 << i)){
                weight += weights[i];
                value += values[i];
            }
        }
        if(weight <= maxweight && value > maxval){
            maxval = value;
            bestsub = sub;
        }
    }
    printf("Max value: %d", maxval);
    for(int i = 0; i < n; i++)
        if(bestsub & (1<<i))
            printf("\tItem %d: Value: %d",i+1, values[i]);
}

void main(){
    knapsack(4, 10);
}