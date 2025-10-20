#include <stdio.h>

void main(){
    int num,first,middle,last;
    int i;
    printf("Enter a three digit number: ");
    scanf("%d",&num);
    if(num<99){
        printf("Entered number is invaid");
    }else if(num>99 && num<1000){
        last = num%10;
        while(num>10){
            num /=10;
            if(num>9&&num<100){
                middle = num%10;
            }else{
                first = num%10;
            }
        }
        if((first+last)==middle){
            printf("Sum of the first and the last digits is equal to the middle digit");
        }else{
            printf("sum of the first and the last digits is not equal to the middle digit.");
        }
    }
}
