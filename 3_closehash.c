// #include<stdio.h>
// #include<stdlib.h>
// #define m 10
// #define empty -1
// //#define deleted -2
// int hashtable[m] = {empty};
// int opcount = 0;
// int hashfunction(int key){
// 	return key % m;
// }
// void insert(int key){
// 	int index = hashfunction(key);
// 	int i = 1;
// 	int ind = index;
// 	while(hashtable[index] != empty){
// 		index = (ind+i) % m;
// 		i++;
// 		if(index == ind){
// 			printf("Table Full.");
// 			return;
// 		}
// 	}
// 	hashtable[index] = key;
// }

// int search(int key){
// 	int index = hashfunction(key);
// 	int ind = index;
// 	int i = 1;
// 	while(hashtable[index] != empty){
// 		opcount++;
// 		if(hashtable[index] == key)
// 			return 1;
// 		index = (ind+i) % m;
// 		i++;
// 		if(ind == index)
// 			break;
// 	}
// 	return -1;
// }
// void display(){
// 	printf("\nHash table: ");
// 	for(int i = 0; i < m; i++)
// 		printf("%d ", hashtable[i]);
// }
// void main(){
// 	int n, key;
// 	printf("Enter no. of elements: ");
// 	scanf("%d", &n);
// 	printf("Enter the elements: ");
// 	for(int i = 0; i < n; i++){
// 		scanf("%d", &key);
// 		insert(key);
// 	}
// 	display();
// 	printf("\nEnter key to search: ");
// 	scanf("%d", &key);
// 	printf(search(key) ? "Found" : "Not found");
// 	printf("\nOpcount: %d", opcount);
// }



#include<stdio.h>
#define m 10
#define empty -1
int opcount = 0;
int hashtable[m];
int hashfunction(int key){
    return key % m;
}
void insert(int key){
    int ind = hashfunction(key);
    int og = ind;
    int i = 1;
    while(hashtable[ind] != empty){
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
            return 1;
        }
        ind = (og + i) % m;
        i++;
        if(ind == og){
            printf("Not found");
            break;
        }
    }
    return 0;
}


void display(){
    printf("Hash Table: ");
    for(int ind = 0; ind < m; ind++){
        if(hashtable[ind] == empty)
            printf("Empty ");
        else printf("%d ", hashtable[ind]);
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
    printf(result ? "Found" : "Not found");
    printf("\nOpcount: %d", opcount);    
}