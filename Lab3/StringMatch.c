#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int bruteForceStringMatch(char *text, char *pattern, int m, int n, int *opcount) {
    for (int i = 0; i <= m - n; i++) {
        int j = 0;
        
        while(j < n && text[i + j] == pattern[j]) {
            (*opcount)++;
            j++;
        }
        if (j == n) {
            return i;
        }
        (*opcount)++;
    }
    return -1;
}
int main() {
    char text[100], pattern[100];

    int opcount = 0;
    srand(time(0)); // Seed for random number generation
    int textLength = 50;
    int patternLength = 20;

    generateBestCaseSuccess(text, pattern, textLength, patternLength);
    generateBestCaseUnsuccess(text, pattern, textLength, patternLength);
    generateWorstCaseSuccess(text, pattern, textLength, patternLength);
    printf("Generated text: %s\n", text);
    printf("Generated pattern: %s\n", pattern);

    int pos = bruteForceStringMatch(text, pattern, strlen(text), strlen(pattern), &opcount);
    printf(pos == -1 ? "Pattern not found in the text\n" : "Pattern found at position %d\n", pos);
    printf("\nm = %d, n = %d \tNumber of comparisons: %d\n", strlen(text), strlen(pattern), opcount);

    return 0;
}




void generateBestCaseSuccess(char *text, char *pattern, int textLength, int patternLength) {
    for (int i = 0; i < textLength; i++) {
        text[i] = 'a' + rand() % 26; // Random lowercase letter
    }
    text[textLength] = '\0';

    // Copy a part of the text to pattern to ensure best case
    strncpy(pattern, text, patternLength);
    pattern[patternLength] = '\0';
}

void generateBestCaseUnsuccess(char *text, char *pattern, int textLength, int patternLength) {
    for(int i = 0; i < textLength; i++) {
        text[i] = 'a' + rand() % 13; // Random lowercase letter
    }
    text[textLength] = '\0';
    for(int i = 0; i < patternLength; i++) {
        pattern[i] = 'n' + rand() % 13; // Random lowercase letter
    }
    pattern[patternLength] = '\0';
}

  void generateWorstCaseSuccess(char *text, char *pattern, int textLength, int patternLength) {
    char repeatedChar = 'a' + rand() % 26;  // Random character for repeated near-matches

    // Fill text with repeated near matches
    for (int i = 0; i < textLength - patternLength; i++) {
        text[i] = repeatedChar;
    }

    // Place the pattern match at the end
    for (int i = 0; i < patternLength - 1; i++) {
        text[textLength - patternLength + i] = repeatedChar;
        pattern[i] = repeatedChar;
    }

    // Set a distinct last character for both text and pattern
    char distinctChar;
    do {
        distinctChar = 'a' + rand() % 26;
    } while (distinctChar == repeatedChar);

    text[textLength - 1] = distinctChar;
    pattern[patternLength - 1] = distinctChar;

    // Null-terminate both
    text[textLength] = '\0';
    pattern[patternLength] = '\0';
}