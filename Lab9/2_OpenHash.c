#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define m 10
typedef struct node{
    int data;
    struct node* next;
}Node;

Node* newnode(int data){
    Node* node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    return node;
}
Node* hashtable[m];
int opcount = 1;
int hashfunction(int key){
    return key % m;
}
void insert(int key){
    int ind = hashfunction(key);
    Node* cell = newnode(key);
    if(hashtable[ind] == NULL){
        hashtable[ind] = cell;
        return;
    }
    Node* temp = hashtable[ind];
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = cell;    
}

bool search(int key){
    int ind = hashfunction(key);
    Node* temp = hashtable[ind];
    while(temp != NULL){
        opcount++;
        if(temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}
void display(){
    for(int i = 0; i < m; i++){
        Node* temp = hashtable[i];
        printf("\n%d", i);
        while(temp != NULL){
            printf("-> %d ", temp->data);
            temp = temp->next;
        }
    }
}

void main(){
    for (int i = 0; i < m; i++)
        hashtable[i] = NULL;
    int n, key;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter keys: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &key);
        insert(key);
    }
    printf("Hash Table: ");
    display();
    printf("\nEnter key to search: ");
    scanf("%d", &key);
    bool result = search(key);
    //printf(result);
    printf(result ? "Found" : "Not found");
    printf("\nOpcount: %d", opcount);
}