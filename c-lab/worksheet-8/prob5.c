#include <stdio.h>
#include <string.h>


void sort(char* s){


    int len = strlen(s);


    for(int i=0; i<len; i++){
        for(int j=i;j<len;j++){
            if(s[i]>s[j]){
                char c = s[i];
                s[i]= s[j];
                s[j] = c;
            }
        }
    }
}


void main(){
    char s[100];
    printf("Enter the string: ");
    scanf("%s",s);
    sort(s);
    printf("Sorted String : %s",s);
}


