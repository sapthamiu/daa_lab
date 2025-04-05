//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
//return the k closest points to the origin (0, 0).
//The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
//You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

//Approach: Transform points into a distance array and sort it
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int x, y;
    int dist;
}point;

int distance(int x, int y){
    return x*x + y*y;
}
//insertion sort
void sortpoints(point* arr, int n){
    int i, j;
    for(i = 1; i < n; i++){
        point key = arr[i];
        for(j = i - 1; (j >= 0) && arr[j].dist > key.dist; j--)
            arr[j+1] = arr[j];
        arr[j+1] = key;
    }
}

void kclosest(int points[][2], int n, int k){
    point *arr = malloc(n * sizeof(point));
    for(int i = 0; i < n; i++){
        arr[i].x = points[i][0];
        arr[i].y = points[i][1];
        arr[i].dist = distance(arr[i].x, arr[i].y);
    }
    sortpoints(arr, n);
    printf("Closest %d points to origin are: ", k);
    for(int i = 0; i < k; i++)
        printf("(%d, %d) ", arr[i].x, arr[i].y);
}

void main(){
    int points[][2] = {{3, 3}, {5, -1}, {-2, 4}, {1, 1}};
    int n = 4;
    int k = 2;
    kclosest(points, n, k);
}