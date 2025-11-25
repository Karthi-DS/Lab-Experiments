#include <stdio.h>
#include <string.h>


int getNumericalValue(char s[]){
    int res = 0,i;
    for(i=0;i<strlen(s);i++){
        int val = s[i]-'a';
        res = res*10 + val;
    }
    return res;
}


int solution(char s1[], char s2[], char target[]){
    int res = 1;
    if(getNumericalValue(s1)+getNumericalValue(s2)!=getNumericalValue(target)){
        res = 0;
    }
    return res;
}




void main(){
    char s1[100],s2[100],target[100];


    printf("Enter String 1: ");
    scanf("%s",&s1);


    printf("Enter String 2: ");
    scanf("%s",&s2);


    printf("Enter target: ");
    scanf("%s",&target);


    int res = solution(s1,s2,target);


    if(res){
        printf("Valid");
    }else{
        printf("Not valid");
    }
}


