//You are given an array of k linked-lists, each linked-list is sorted in ascending order
//Merge all the linked-lists into one sorted linked-list and return it.

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct node{
    int data;
    struct node* next;
}node;
node* getnode(int data){
    node* newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
node* mergetwo(node* l1, node* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    node* temp1 = l1;
    node* temp2 = l2;
    node* head = NULL;  //merged head
    node* last = NULL;  //merged last
    while(temp1 && temp2){
        node* selected;
        if(temp1->data < temp2->data){
            selected = temp1;
            temp1 = temp1->next;
        }
        else{
            selected = temp2;
            temp2 = temp2->next;
        }
        selected->next = NULL;
        if(!head){
            head = selected;
            last = selected;
        }
        else{
            last->next = selected;
            last = selected;
        }
    }
    node* remaining = temp1 ? temp1 : temp2;
    if(!head) head = remaining;
    else last->next = remaining;
    return head;
}

node* mergek(node** lists, int n){
    if(n == 0) return NULL;
    if(n == 1) return lists[0];

    int mid = n/2;
    node* left = mergek(lists, mid);
    node* right = mergek(lists+mid, n - mid);

    return mergetwo(left, right);
}

node* createlist(int arr[], int n){
    if(n == 0) return NULL;
    node* head = getnode(arr[0]);
    node* current = head;
    for (int i = 1; i < n; i++) {
        current->next = getnode(arr[i]);
        current = current->next;
    }
    return head;
}
void printList(node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Sample arrays to simulate sorted linked lists
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};

    node* list1 = createlist(arr1, 3);
    node* list2 = createlist(arr2, 3);
    node* list3 = createlist(arr3, 2);

    node* lists[MAX];  // You can change MAX to whatever number of lists you want
    lists[0] = list1;
    lists[1] = list2;
    lists[2] = list3;

    int k = 3;

    node* merged = mergek(lists, k);

    printf("Merged List:\n");
    printList(merged);

    return 0;
}