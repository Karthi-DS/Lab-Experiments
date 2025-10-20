#include <stdio.h>
#include <string.h>

void main(){
    char name[100];
    char reverse[100];
    char cpy[100];
    int len,i,j=0;
    printf("Enter name or word:\n");
    scanf("%s",name);
    len = strlen(name);
    printf("The length of the entered word is %d\n",len);
    for(i=len-1;i>=0;i--){
        reverse[j]=name[i];
        j++;
    }
    printf("The reversed string is %s\n",reverse);
    strcpy(cpy,name);
    printf("Entered name is successfully copied. %s",cpy);
}