
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INITIAL_SIZE 8

int isValidInteger(char *c) {
    if (*c == '\0') return 0;
    while (*c) {
        if (!isdigit(*c)) return 0;
        c++;
    }
    return 1;
}

char *readLineDynamic() {
    size_t size = INITIAL_SIZE;
    char *buffer = malloc(size);
    if (!buffer) return NULL;

    size_t len = 0;
    int ch;

    while ((ch = getchar()) != EOF && ch != '\n') {
        buffer[len++] = ch;
        if (len == size) {
            size *= 2;
            char *new_buffer = realloc(buffer, size);
            if (!new_buffer) {
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }
    }
    buffer[len] = '\0';  // null-terminate
    return buffer;
}

int main() {
    printf("Enter number: ");
    char isContinue[3];
    char *input = readLineDynamic();
    if (!input) {
        printf("Memory allocation error\n");
        return 1;
    }

    if (!isValidInteger(input)) {
        printf("Enter a valid integer\n");
        free(input);
        return 1;
    }

    int num = atoi(input);
    free(input);

    if (num < 0) {
        printf("Entered number is invalid\n");
        printf("do you want to continue? \n");
        scanf("%s",isContinue);
        if(strcmp(isContinue,"yes")){
            main();
        }
        return 1;
    } else if (num == 0) {
        printf("Number should be greater than zero.\n");
         printf("do you want to continue? \n");
        scanf("%s",isContinue);
        if(strcmp(isContinue,"yes")==1){
            main();
        }
        return 1;
    }

    long res = 0;
    for (int i = 0; i <= num; i++) {
        res += i * (num - i + 1);
    }
    printf("The result is %ld\n", res);

    return 0;
}

