#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char buff[1000],res[1000];
    char *token;
    int i,j=0;
    printf("Enter the word: ");
    fgets(buff,1000,stdin);
    token = strtok(buff," ");
    while (token){
      for(i=0;i<strlen(token);i++){
        res[j] = token[i];
        j++;
      }  
      res[j++] = ' ';
      token = strtok(NULL," ");
    }
    
    printf("The trimmed version of the entered sentence is %s",res);
    return 0;
}