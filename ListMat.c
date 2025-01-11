#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

typedef struct{
	node** head;
	int vertices;
}list;

list* createList(int v){
	list* newlist = malloc(sizeof(list));
	newlist->head = malloc(v * sizeof(node*));
	for (int i = 0; i < v; i++) {
        newlist->head[i] = NULL;
    }
	newlist->vertices = v;
	return newlist;
}

int** createMatrix(int v){
	int** newmat = malloc(v * sizeof(int*));
	for(int i = 0; i < v; i++){
		newmat[i] = malloc(v * sizeof(int));
		for (int j = 0; j < v; j++) {
            newmat[i][j] = 0;
        }
	}
	return newmat;
}

void addList(list* lists, int src, int dest, int v){
	if(src >= v || dest >= v){
		printf("Enter valid source or destination vertex. ");
		return;
	}
	node* newnode = malloc(sizeof(node));
	newnode->data = dest;
	newnode->next = lists->head[src];
	lists->head[src] = newnode;

	newnode = malloc(sizeof(node));
	newnode->data = src;
	newnode->next = lists->head[dest];
	lists->head[dest] = newnode;
}

void displayList(list* lists, int v){
	for(int i = 0; i < v; i++){
		printf("\nVertex %d: ", i);
		node* temp = lists->head[i];
		while(temp){
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

void addMat(int** mat, int src, int dest, int v){
	if(src >= v || dest >= v){
		printf("Enter valid source or destination vertex. ");
		return;
	}
	mat[src][dest] = 1;
	mat[dest][src] = 1;
}

void displayMat(int** mat, int v){
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
}

void main(){
	printf("Enter number of vertices: ");
	int v;
	scanf("%d", &v);
	printf("Enter number of edges: ");
	int e;
	scanf("%d", &e);
	list* lists = createList(v);
	int** mat = createMatrix(v);
	int src, dest;
	for(int i = 0; i < e; i++){
		printf("Enter source and destination: ");
		scanf("%d%d", &src, &dest);
		addList(lists, src, dest, v);
		addMat(mat, src, dest, v);
	}
	displayList(lists,v);
	displayMat(mat, v);
}
