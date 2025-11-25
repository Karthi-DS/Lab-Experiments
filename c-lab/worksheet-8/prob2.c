#include <stdio.h>
#include <string.h>




int solution(char s1[], char s2[]){
    int res = 1, swappable= 0, i;
    int count[26] = {0};
    if(strlen(s1)!=strlen(s2)){
        return 0;
    }


    for(i=0;i<strlen(s1);i++){
        count[s1[i]-'a'] += 1;
        count[s2[i]-'a'] -= 1;
    }


    for(i=0;i<26;i++){
        if(count[i]!=0){
            return 0;
        }
    }


    for(i=0;i<strlen(s1);i++){
        if(s1[i]!=s2[i]){
            swappable+=1;
        }
    }


    if(swappable>2){
        res = 0;
    }


    return res;
}




void main(){
    char s1[100],s2[100];
    printf("Enter String 1: ");
    scanf("%s",&s1);
    printf("Enter String 2: ");
    scanf("%s",&s2);


    int res = solution(s1,s2);


    if(res){
        printf("Valid");
    }else{
        printf("Not valid");
    }
}
