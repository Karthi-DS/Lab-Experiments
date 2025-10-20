#include <stdio.h>
#include <string.h>

void main(){
    char w[100],res[256]={0},l;
    int len,i,k,longest=0;
    printf("Enter word: ");
    scanf("%s",w);
    len = strlen(w);
    for(i=0;i<strlen(w);i++){
        res[w[i]]+=1;
        k=res[w[i]];
        if(longest<k){
            longest = k;
            l = w[i];
        }
    }
    printf("Longest Substring is %c and it is repeated %d times.",l,longest);
}