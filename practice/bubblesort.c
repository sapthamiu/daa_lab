#include<stdio.h>
void main(){
    int opcount = 0;
    int a[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5-i-1; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                opcount++;
            }
        }
    }
    for(int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n%d", opcount);
}