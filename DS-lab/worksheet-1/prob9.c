
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

// Function to repeat a string k times
char* repeatString(char *str, int k) {
    int len = strlen(str);
    char *res = (char*)malloc(len * k + 1);
    res[0] = '\0';
    for (int i = 0; i < k; i++) {
        strcat(res, str);
    }
    return res;
}

// Main decode function
char* decodeString(char *s) {
    char *strStack[MAX];
    int countStack[MAX];
    int strTop = -1, countTop = -1;

    // start with an empty string on stack
    strStack[++strTop] = strdup("");

    int num = 0;
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            // build the number
            num = num * 10 + (s[i] - '0');
        }
        else if (s[i] == '[') {
            countStack[++countTop] = num;  // push repeat count
            num = 0;
            strStack[++strTop] = strdup("");  // new current string
        }
        else if (s[i] == ']') {
            char *cur = strStack[strTop--];        // string inside brackets
            int repeat = countStack[countTop--];   // repeat times
            char *rep = repeatString(cur, repeat); // repeated string

            // append to previous
            char *prev = strStack[strTop];
            char *merged = (char*)malloc(strlen(prev) + strlen(rep) + 1);
            strcpy(merged, prev);
            strcat(merged, rep);

            free(strStack[strTop]); // free old prev
            strStack[strTop] = merged;

            free(cur);
            free(rep);
        }
        else {
            // append character to current top string
            int len = strlen(strStack[strTop]);
            char *newStr = (char*)malloc(len + 2);
            strcpy(newStr, strStack[strTop]);
            newStr[len] = s[i];
            newStr[len+1] = '\0';

            free(strStack[strTop]);
            strStack[strTop] = newStr;
        }
    }

    return strStack[strTop]; // final result
}

int main() {
    char s1[100];
    printf("Enter the input: ");
    scanf("%s",&s1);
    printf("Input: %s -> Output: %s\n", s1, decodeString(s1));

    return 0;
}











