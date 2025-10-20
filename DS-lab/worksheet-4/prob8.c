#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i;
    printf("Enter the word: ");
    scanf("%s",str);
    for(i=0;i<strlen(str);i++){
        str[i] = toupper(str[i]);
    }
    printf("The uppercase of the entered word is %s",str);
    return 0;
}