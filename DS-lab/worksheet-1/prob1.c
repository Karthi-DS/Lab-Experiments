#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char *token;
    char *lastToken=NULL;
    
    printf("Enter a Text: ");
    fgets(str, sizeof(str),stdin);
    
    str[strlen(str)-1]='\0';
    // Get the first token
    token = strtok(str, " ");

    // Walk through other tokens
    while(token != NULL) {
        lastToken = token;
        token = strtok(NULL, " ");
    }
    int len = strlen(lastToken);
    printf("The last word was '%s' and the length of %d.",lastToken,len);

    return 0;
}
