#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isVowel(char c){
    c = tolower(c);
    if(c=='a'||c=='e'||c='i'||c=='o'||c=='u'){
        return 1;
    }
    return 0;
}

void main(){
    char w[100],tmp;
    int l=0,r;
    printf("Enter word: ");
    scanf("%s",w);
    r = strlen(w)-1;
        while(l<r){
            if(!isVowel(w[l])){
                l++;
            }else if(!isVowel(w[r])){
                r--;
            }else{
                tmp = w[l];
                w[l] = w[r];
                w[r] = tmp;
                l++;
                r--;
            }
    }
    printf("After reversing vowles: \n");
    printf("%s",w);
}