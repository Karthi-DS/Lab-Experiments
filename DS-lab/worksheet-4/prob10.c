#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char buff[1000];
    int i,j=0,n;
    printf("Enter the word: ");
    fgets(buff,1000,stdin);
    printf("Enter the width: ");
    scanf("%d",&n);
    for(i=0;i<strlen(buff);i++){
        printf("%c",buff[i]);
        if((i+1)%n==0){
            printf("\n");
        }
    }
    return 0;
}