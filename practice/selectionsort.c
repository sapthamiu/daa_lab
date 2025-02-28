#include<stdio.h>
void main(){
    int opcount = 0;
    int a[5] = {5, 4, 3, 2, 1};
    for(int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
    for(int i = 0; i < 4; i++){
        int min = i;
        for(int j = i+1; j < 5; j++){
            opcount++;
            if(a[j] < a[min]){
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    for(int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n%d", opcount);
}