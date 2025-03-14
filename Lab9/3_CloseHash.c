#include<stdio.h>
#include<stdlib.h>
#define m 10
#define empty -1
#define deleted -2
int opcount = 0;
int hashtable[m];
int hashfunction(int key){
    return key % m;
}
void insert(int key){
    int ind = hashfunction(key);
    int og = ind;
    int i = 1;
    while(hashtable[ind] != empty && hashtable[ind] != deleted){
        ind = (og + i) % m;
        i++;
        if(ind == og){
            printf("Full. Cannot insert");
            return;
        }
    }
    hashtable[ind] = key;
}

int search(int key){
    int ind = hashfunction(key);
    int og = ind;
    int i = 1;
    while(hashtable[ind] != empty){
        opcount++;
        if(hashtable[ind] == key){
            return ind;
        }
        ind = (og + i) % m;
        i++;
        if(ind == og){
            printf("Not found");
            break;
        }
    }
    return -1;
}

void delete(int key){
    int ind = search(key);
    if(ind == -1){
        printf("Can't delete");
        return;
    }
    hashtable[ind] = deleted;
}

void display(){
    printf("Hash Table: ");
    for(int ind = 0; ind < m; ind++){
        printf("\n%d: ", ind);
        if(hashtable[ind] == empty)
            printf("Empty");
        else if(hashtable[ind] == deleted)
            printf("Deleted");
        else printf("%d", hashtable[ind]);
    }
}
void main(){
    for (int i = 0; i < m; i++)
        hashtable[i] = empty;
    int n, key;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter keys: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &key);
        insert(key);
    }
    display();
    printf("\nEnter key to search: ");
    scanf("%d", &key);
    int result = search(key);
    //printf(result);
    printf(result != -1 ? "Found" : "Not found");
    printf("\nOpcount: %d", opcount);
    printf("\nEnter key to delete: ");
    scanf("%d", &key);
    delete(key);
    display();
    
}