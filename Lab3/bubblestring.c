#include<stdio.h>
#include<string.h>
#define swap(a, b, temp) { \
    temp = a; \
    a = b; \
    b = temp; \
}
void bubblesort(char** words, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            //if(strcmp(words[j], words[j+1]) > 0)
            int k = 0;
            while(words[j][k] != '\0' && words[j][k] != '\0' && words[j][k] == words[j+1][k]) k++;
            if(words[j][k] > words[j+1][k]){
                char temp[100];
                swap(words[j], words[j+1], temp);
            }
        }
    }
}
void main(){
    int n = 5;  // Number of strings
    char* s[] = {
        "banana",
        "apple",
        "cherry",
        "date",
        "elderberry"
    };

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", s[i]);
    }

    bubblesort(s, n);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", s[i]);
    }
}