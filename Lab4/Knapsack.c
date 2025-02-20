#include<stdio.h>
#define MAX 10
typedef struct{
    int value;
    int weight;
}Item;

int TotalWeight(Item items[], int n, int subset[]){
    int totweight = 0;
    for(int i = 0; i < n; i++)
        if(subset[i])
            totweight += items[i].weight;
    return totweight;
}

int TotalValue(Item items[], int n, int subset[]){
    int totvalue = 0;
    for(int i = 0; i < n; i++)
        if(subset[i])
            totvalue += items[i].value;
    return totvalue;
}

int Knapsack(Item items[], int n, int capacity, int* included){
    int maxval = 0;
    int totalsubs = 1<<n;       //2^n
    for(int subnum = 0; subnum < totalsubs; subnum++){
        int subset[MAX] = {0};
        for(int bit = 0; bit < n; bit++){
            subset[bit] = (subnum >> bit) & 1;          //checks if the bit'th element is included in the subnum'th subset
        }
        int totweight = TotalWeight(items, n, subset);
        int totval = TotalValue(items, n, subset);
        if(totweight <= capacity && totval > maxval){
            maxval = totval;
            for(int i = 0; i < n; i++){
                included[i] = subset[i];
            }
        }
    }
    return maxval;
}

void main(){
    Item items[3] = {{2,1},{4,2},{8,4}};
    int cap = 5;
    int included[3] = {0};
    int maxval = Knapsack(items, 3, cap, included);
    printf("Max Value: %d\n", maxval);
    printf("Items in the knapsack: \n");
    for(int i = 0; i < 3; i++){
        if(included[i] == 1)
            printf("Item %d: Value %d\n", i+1, items[i].value);
    }
}