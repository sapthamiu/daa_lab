//Given an array of integers nums and an integer k, 
//return the total number of subarrays whose sum equals to k.
//A subarray is a contiguous non-empty sequence of elements within an array.

//Approach: Precalculate the prefix sum of every element in a hash table
#include<stdio.h>
#include<stdlib.h>
#define m 1009
typedef struct node{
    int key, freq;  //prefix sum - frequency pair
    struct node* next;
}node;
node* ht[m];

node* getnode(int key){
    node* newnode = malloc(sizeof(node));
    newnode->key = key;
    newnode->freq = 1;
    newnode->next = NULL;
    return newnode;
}

int hashfunction(int key){
    if(key < 0) key = -key;
    return key % m;
}

void insert(int key){
    int index = hashfunction(key);
    node* cell = getnode(key);
    if(ht[index] == NULL)
        ht[index] = cell;
    else{
        //traverse and check if key exists
        node* temp = ht[index];
        while(temp->next != NULL){
            if(temp->key == key){
                temp->freq++;
                return;
            }
            temp = temp->next;
        }
        //check last node
        if(temp->key == key){
            temp->freq++;
            return;
        }
        //not found
        temp->next = cell;
    }
}
int getfreq(int key){
    int index = hashfunction(key);
    node* temp = ht[index];
    while(temp != NULL){
        if(temp->key == key) return temp->freq;
        temp = temp->next;
    }
    return 0;
}

int subarraysum(int* nums, int n, int k){
    for(int i = 0; i < m; i++)
        ht[i] = NULL;
    int sum = 0, count = 0;
    insert(0);  //prefix sum 0 appears before array starts
    for(int i = 0; i < n; i++){
        sum += nums[i];
        count += getfreq(sum-k);
        insert(sum);
    }
    return count;
}
void main(){
    int nums[] = {1, 2, 3};
    int k = 3;
    int n = 3;
    printf("k = %d: %d", k, subarraysum(nums, n, k));
}