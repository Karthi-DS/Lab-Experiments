#include <stdio.h>

void main(){
    int num,last,first;
    printf("Enter number: ");
    scanf("%d",&num);
    if(num<0){
        printf("The number is invalid");
    }
    else{
        last = num%10;
        while(num>0){
            if(num<10){
                first = num;
            }
            num/=10;
        }
        if(first%last==0){
            printf("The last number is divisible of first number\n");
        }
        if(last%first==0){
            printf("The first number is divisible of last number\n");
        }
    }
}


