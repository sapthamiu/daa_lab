#include<stdio.h>
#include<string.h>
int stringmatch(char* text, char* word){
    int m = strlen(text);
    int n = strlen(word);
    for(int i = 0; i <= m-n; i++){
        int j = 0;
        while(j < n && word[j] == text[i+j]){
            j++;
        }
        if(j == n)
            return i;
    }
    return -1;
}
int main(){
    char text[11] = "vikasansud";
    char word[4] = "sud";
    printf("%d", stringmatch(text, word));
    return 0;
}